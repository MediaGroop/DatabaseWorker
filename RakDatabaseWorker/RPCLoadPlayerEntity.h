#pragma once
#include "stdafx.h"
#include "ServVars.h"
#include "EntityLink-odb.hxx"
#include "EntityLoader.h"

//Sends add entity, which checks upcast id on the server and loads additional data to it through this worker
void loadPlayerEntity(RakNet::BitStream *bitStream, RakNet::Packet *packet)
{
	LOG(INFO) << "Loading player's entity data";

	typedef odb::query<EntityLink> query;
	typedef odb::result<EntityLink> result;

	EntityLink link;
	RakNet::RakString n, a;

	bitStream->Read(a);
	bitStream->Read(n);

	try{

		odb::transaction t(dataBase->begin());
		LOG(INFO) << "Retrieving entity link data for " << n.C_String() << " account: " << a.C_String();
		//retrieving entity from account name and character name

		result r(dataBase->query<EntityLink>((query::account == std::string(a.C_String())) && (query::name == std::string(n.C_String()))));

		char str[24];
		for (result::iterator i(r.begin()); i != r.end(); ++i)
		{
			link = (*i);

			//itoa(link.id(), str, 10);
			LOG(INFO) << "Link info:";
			//LOG(INFO) << "id: " << str;
			LOG(INFO) << "account: " << link.account();
			LOG(INFO) << "name: " << link.name();

		}

		t.commit();
	}
	catch (const odb::exception& e)
	{
		cerr << e.what() << endl;
	}

	LOG(INFO) << "...success!";
	//Load data
	int id = link.id();
	Entity ent = loadEntity(id);
	if (&ent != nullptr){
		LOG(INFO) << "Entity data was loaded...";

		LOG(INFO) << "Sending base data to server...";

		//Add entity to core
		RakNet::BitStream bs1;
		bs1.Write(id);
		bs1.Write(ent.upcastId());
		bs1.Write(ent.worldId());
		rpc.Call("addEntity", &bs1, HIGH_PRIORITY, RELIABLE_ORDERED, 0, mainServer->getPeer()->GetSystemAddressFromIndex(0), false);
		
		LOG(INFO) << "Setting it to the avatar...";
		//Set entity exemplar to avatar
		RakNet::BitStream bs;
		bs.Write(a);
		bs.Write(ent.id());
		bs.Write(ent.worldId());
		rpc.Call("se", &bs, HIGH_PRIORITY, RELIABLE_ORDERED, 0, mainServer->getPeer()->GetSystemAddressFromIndex(0), false);

		LOG(INFO) << "Done!";
		//delete ent;
	}
	else
	{
		LOG(INFO) << "No entity data!";
	}

}