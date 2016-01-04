// RakDatabaseWorker.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "easylogging++.h"
#include "FileManager.h"
#include "ConfigLoader.h"
#include "Server.h"
#include "ServVars.h"
#include "EntityFactory.h"
#include "Entity_Object.h"

//RPC's
#include "RPCLoadWorlds.h"
#include "RPCLoadPlayerEntity.h"
#include "RPCLoadEntity.h"

#include <stdio.h>  /* defines FILENAME_MAX */

#if defined(_WIN64) || defined(_WIN32)
#include <thread>
#else
#include <pthread.h>
#endif

#define ELPP_STL_LOGGING
#define ELPP_PERFORMANCE_MICROSECONDS
#define ELPP_LOG_STD_ARRAY
#define ELPP_LOG_UNORDERED_MAP
#define ELPP_UNORDERED_SET
#define ELPP_THREAD_SAFE
#define ELPP_EXPERIMENTAL_ASYNC 

//DONT FORGET THIS SHIT!!1
INITIALIZE_EASYLOGGINGPP

//extern vars
factory g_factory;
Server* mainServer;
RakNet::RPC4 rpc;
std::auto_ptr<odb::database> dataBase;

//Configuring easyLogging

void setupLog(){
	time_t t;
	t = time(0);
	char str[FILENAME_MAX];

	getcwd(str, sizeof(str));
	if (!FileManager::DirExists(strcat(str, "//logs//"))){
		mkdir(str, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	}

	std::string log_name = "//logs//";
	log_name.append(asctime(localtime(&t)));
	log_name[log_name.length() - 1] = ' ';
	log_name.append(".txt");

	for (int i = 0; i < log_name.length(); ++i)
	{
		if (log_name[i] == ':' || log_name[i] == ' ' || log_name[i] == '\r')
		{
			log_name[i] = '_';
		}
	}

	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename, log_name);
}

static void registerClasses()
{
	REGISTER_CLASS(-1, Entity_Object);
}

int main(int argc, const char** argv)
{

	registerClasses();
	char str[10];
	setupLog();
	LOG(INFO) << "Log was initialized...";
	ConfigLoader::init("config.ini");
	LOG(INFO) << "Configuration loaded...";
	dataBase = *new std::auto_ptr<odb::database>(new odb::pgsql::database(
		ConfigLoader::getVal("Database-User"),
		ConfigLoader::getVal("Database-Pass"),
		ConfigLoader::getVal("Database-DBName"),
		ConfigLoader::getVal("Database-DBAddress")));
	NetworkListener listen;

	Server srv(&listen);

	mainServer = &srv;
#if defined(_WIN64) || defined(_WIN32)
	mainServer->setThread(	new std::thread(mainServer->startNetworkTrd, mainServer, ConfigLoader::getIntVal("Network-Port"), ConfigLoader::getIntVal("Network-MaxCons")));
#else
	pthread_t* trd = new pthread_t();
	server_data data;
	data.instance = mainServer;
	data.max_players = ConfigLoader::getIntVal("Network-MaxCons");
	data.port = ConfigLoader::getIntVal("Network-Port");
	pthread_create(trd, NULL, &mainServer->startMainNetworkThread, (void *)&data);
	mainServer->setThread(trd);
#endif
	while(!mainServer->getRunning()){} // wait for full init
	mainServer->getPeer()->AttachPlugin(&rpc);
	
	//Registering RPC's
	rpc.RegisterFunction("lw", loadWorldsRPC); // loads worlds info
	rpc.RegisterFunction("lpe", loadPlayerEntity); // loads entity for player
	rpc.RegisterFunction("le", loadEntityData); // loads entity for player
	//END

	gets(str);
	
	mainServer->setRunning(false);
#if defined(_WIN64) || defined(_WIN32)
	mainServer->getThread()->join();
#endif
	return 0;
}

