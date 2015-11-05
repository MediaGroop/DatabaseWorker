#pragma once
#include "stdafx.h"
#include "ServVars.h"
#include "EntityLink-odb.hxx"
//Sends add entity, which checks upcast id on the server and loads additional data to it through this worker
void loadPlayerEntity(RakNet::BitStream *bitStream, RakNet::Packet *packet)
{
	typedef odb::query<EntityLink> query;
	typedef odb::result<EntityLink> result;

	RakNet::RakString n, a;
	bitStream->Read(a);
	bitStream->Read(n);

	odb::transaction t(dataBase->begin());
	//retrieving entity from account name and character name
	EntityLink* link = dataBase->query_one<EntityLink>( (query::account == a.C_String()) && (query::name == n.C_String()) );
	if (link != nullptr)
	{
		int id = link->id();
		loadEntity(id);
	}
	else
	{
		LOG(INFO) << "No link!";
	}
}