#include "libs/object_server/src/object_server_service.h"

const std::string address = "tcp://127.0.0.1:9090";

int main()
{
	std::thread mainThread;
	ObjectServer server;
	
	server.Init(address);
	server.Connect();
	mainThread = std::thread([&] { server.Start(); });
	mainThread.join();
}