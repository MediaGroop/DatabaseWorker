#pragma once
#include "stdafx.h"
#include "ServVars.h"
#include "WorldInfo-odb.hxx"

void loadWorldsRPC(RakNet::BitStream *bitStream, RakNet::Packet *packet)
{
	//LOG(INFO) << "load worlds reqquest";
	typedef odb::query<WorldInfo> query;
	typedef odb::result<WorldInfo> result;


	odb::transaction t(dataBase->begin());

	result r(dataBase->query<WorldInfo>());

	for (result::iterator i(r.begin()); i != r.end(); ++i)
	{
		RakNet::BitStream bs;
	//	LOG(INFO) << i->name();
		bs.Write(i->id());
		bs.Write(i->name());
		bs.Write(i->x());
		bs.Write(i->y());
		bs.Write(i->z());
		rpc.Signal("aw", &bs, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, mainServer->getPeer()->GetSystemAddressFromIndex(0), false, true);
		LOG(INFO) << "Add world RPC";
	}

};