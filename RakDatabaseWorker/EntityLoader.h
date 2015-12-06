#pragma once
#include "stdafx.h"
#include "ServVars.h"
#include "Entity-odb.hxx"

//Loads entity info form database
Entity loadEntity(int id){
	typedef odb::query<Entity> queryS;
	typedef odb::result<Entity> resultS;
	odb::transaction t(dataBase->begin());
	Entity ent;

	resultS r(dataBase->query<Entity>(queryS::id == id));

	for (resultS::iterator i(r.begin()); i != r.end(); ++i)
	{
		char str[100];
		itoa((*i).id(), str, 10);
		LOG(INFO) << "ID: " << str;
		itoa((*i).upcastId(), str, 10);
		LOG(INFO) << "Uid: " << str;
		itoa((*i).worldId(), str, 10);
		LOG(INFO) << "World Id: " << str;
		ent = (*i);
	}
	t.commit();
	return ent;
};
