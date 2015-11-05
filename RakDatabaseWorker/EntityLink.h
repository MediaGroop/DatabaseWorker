#pragma once
#include <string>
#include "odb\core.hxx"

#pragma db object
class EntityLink{
public:
	EntityLink(int i, std::string n, std::string acc) : _id(i), _name(n), _account(acc)	{};

	~EntityLink(){};

	EntityLink()
	{
		_id = -1;
		_name = "";
		_account = "";
	};

	std::string& name()
	{
		return this->_name;
	}

	std::string& account()
	{
		return this->_account;
	}

	int id()
	{
		return _id;
	}


private:
	friend class odb::access;
#pragma db id 
	std::string _account;
	std::string _name;
	int _id;
};