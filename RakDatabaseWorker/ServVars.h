#pragma once
#include "stdafx.h"
#include "Server.h"
#include <map>
#include "odb\pgsql\database.hxx"
#include "RPC4Plugin.h"

//#region vars
static Server* mainServer;
static RakNet::RPC4 rpc;
std::auto_ptr<odb::database> dataBase(new odb::pgsql::database(
	"postgres",
	"root",
	"data",
	"localhost"));
//#endregion