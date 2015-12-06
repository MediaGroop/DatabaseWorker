#pragma once
#include <string>
#include "odb\core.hxx"

#pragma db object
class Entity{
public:

	Entity(int i, int wi, int bi, int xg, int yg, float x, float y, float z, int uid) : _id(i), _body_id(bi), _world_id(wi), _x(x), _y(y), _z(z), _x_grid(xg), _y_grid(yg), _upcast_id(uid)	{};

	virtual ~Entity(){};

	Entity()
	{
		_id = -1;
		_body_id = -1;
		_world_id = -1;
		_x = 0;
		_y = 0;
		_z = 0;
		_x_grid = 0;
		_y_grid = 0;
		_upcast_id = 0;
	};

	int worldId(){
		return _world_id;
	}

	float z(){
		return _z;
	}

	float y(){
		return _y;
	}

	float x(){
		return _x;
	}

	int bodyId(){
		return _body_id;
	}

	int id()
	{
		return _id;
	}

	int x_grid()
	{
		return _x_grid;
	}

	int y_grid()
	{
		return _y_grid;
	}

	int upcastId(){
		return _upcast_id;
	}

private:
	friend class odb::access;

#pragma db id 
	int _id;

	int _world_id;
	float _x, _y, _z;
	int _x_grid, _y_grid;
	int _body_id;
	int _upcast_id;
};