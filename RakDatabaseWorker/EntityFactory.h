#pragma once
#include "stdafx.h"
#include <map>

#define REGISTER_CLASS(t, n) g_factory.register_class<n>(t)
#define CREATE_CLASS(t) g_factory.construct(t);

template <class T> void* constructor() { return (void*)new T(); }

struct factory
{
	typedef void*(*constructor_t)();
	typedef std::map<int, constructor_t> map_type;
	map_type m_classes;

	template <class T>
	void register_class(int id)
	{
		m_classes.insert(std::make_pair(id, &constructor<T>));
	}

	void* construct(int n)
	{
		map_type::iterator i = m_classes.find(n);
		if (i == m_classes.end()) return 0; // or throw or whatever you want
		return i->second();
	}
};

extern factory g_factory;