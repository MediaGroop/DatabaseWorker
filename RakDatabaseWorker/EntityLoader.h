#pragma once
#include "stdafx.h"
#include "ServVars.h"
#include "Entity-odb.hxx"
#include "PhysicsData-odb.hxx"

void loadEntity(int id){
	typedef odb::query<Entity> queryS;
	typedef odb::result<Entity> resultS;
	odb::transaction t(dataBase->begin());
	Entity* ent = dataBase->query_one<Entity>((queryS::id == id));
	if (ent != nullptr)
	{
		RakNet::BitStream bs;

		bs.Write(ent->id());
		bs.Write(ent->bodyId());
		bs.Write(ent->worldId());
		bs.Write(ent->upcastId());

		bs.Write(ent->x_grid());
		bs.Write(ent->y_grid());

		bs.Write(ent->x());
		bs.Write(ent->y());
		bs.Write(ent->z());


		typedef odb::query<PhysicsData> queryP;
		typedef odb::result<PhysicsData> resultP;
		odb::transaction t(dataBase->begin());
		PhysicsData* pd = dataBase->query_one<PhysicsData>((queryP::id == id));
		if (pd != nullptr){
			bs.Write(true);
			bs.Write(pd->shape_id);
			bs.Write(pd->height);
			bs.Write(pd->radius);
			bs.Write(pd->has_mass);
			bs.Write(pd->mass);
		}
		else {
			bs.Write(false);
		}

		rpc.Signal("ae", &bs, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, mainServer->getPeer()->GetSystemAddressFromIndex(0), false, true);
	}
	else
	{
		LOG(INFO) << "No ENtity!";
	}
}