#pragma once
#include "stdafx.h"
#include "Server.h"
#include <map>
#include "odb\pgsql\database.hxx"
#include "RPC4Plugin.h"

//#region vars
extern Server* mainServer;
extern RakNet::RPC4 rpc;
extern std::auto_ptr<odb::database> dataBase;
//#endregion