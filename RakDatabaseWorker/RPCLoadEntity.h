#pragma once
#include "stdafx.h"
#include "EntityLoader.h"
#include "Entity_Object.h"
#include "EntityFactory.h"

void loadEntityData(RakNet::BitStream *bitStream, RakNet::Packet *packet)
{
	char str[100];
	int id, uid;
	bitStream->Read(id);
	bitStream->Read(uid);
	LOG(INFO) << "Loading entity data:";
	//itoa(id, str, 10);
	//LOG(INFO) << "id: " << str;

	//itoa(uid, str, 10);
	LOG(INFO) << "uid:" << str;
	Entity_Object* ent = (Entity_Object*)CREATE_CLASS(uid);
	ent->set_id(id);

	RakNet::BitStream bs;
	ent->loadData(&bs);
	rpc.Call("sed", &bs, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, mainServer->getPeer()->GetSystemAddressFromIndex(0), false);
};