#pragma once
#include <string>
#include "odb/core.hxx"

#pragma db object
class WorldInfo{
public:
	WorldInfo(int i, std::string n, float x, float y, float z) : _id(i), _name(n), _x(x), _y(y), _z(z)	{};

	~WorldInfo(){};

	WorldInfo()
	{
		_id = -1;
		_name = "";
		_x = 0;
		_y = 0;
		_z = 0;
	};

	std::string& name()
	{
		return this->_name;
	}

	int id()
	{
		return _id;
	}

	float x()
	{
		return _x;
	}

	float y()
	{
		return _y;
	}

	float z()
	{
		return _z;
	}


private:
	friend class odb::access;
#pragma db id 
	int _id;
	std::string _name;
	float _x;
	float _y;
	float _z;
};