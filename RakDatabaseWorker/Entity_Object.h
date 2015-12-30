#pragma once
#include "stdafx.h"
#include <string>
#include "odb\core.hxx"
#include "ServVars.h"
#include "Entity-odb.hxx"
#include "PhysicsData-odb.hxx"

//Inherit all data classes from this class and load data
class Entity_Object
{
private:
	int _id;
public:

	Entity_Object();

	virtual void loadData(RakNet::BitStream* to);

	void set_id(int i);

	~Entity_Object();
};

