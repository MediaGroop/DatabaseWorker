#pragma once
#include <string>
#include "odb/core.hxx"

#pragma db object
class PhysicsData{
public:
	PhysicsData(int i, int si, float h, float r, float m, bool hm) : _id(i), _shape_id(si), _height(h), _radius(r), _mass(m), _has_mass(hm){};

	~PhysicsData(){};

	PhysicsData()
	{
		_id = -1;
		_shape_id = 0;
		_height = 0;
		_radius = 0;
		_mass = 0;
		_has_mass = false;
	};

	int id(){
		return _id;
	};

	int shape_id(){
		return _shape_id;
	};

	float height(){
		return _height;
	};

	float radius(){
		return _radius;
	};

	float mass(){
		return _mass;
	};

	bool has_mass(){
		return _has_mass;
	};


private:
	friend class odb::access;

#pragma db id 
	int _id;

	int _shape_id;

	float _height, _radius, _mass;
	bool _has_mass;
};