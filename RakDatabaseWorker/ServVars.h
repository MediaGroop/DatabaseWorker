#pragma once
#include "stdafx.h"
#include "Server.h"
#include <map>
#include "odb\pgsql\database.hxx"

//#region vars
static Server* mainServer;

std::auto_ptr<odb::database> dataBase(new odb::pgsql::database(
	"postgres",
	"root",
	"data",
	"localhost"));
//#endregion