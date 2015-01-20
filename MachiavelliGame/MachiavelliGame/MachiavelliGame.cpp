// MachiavelliGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "GameLoop.h"
#include <memory>

using namespace std;

//void connect_to_server()
//{
//	int port = 1080;
//
//	ClientSocket client("localhost", port);
//}

int _tmain(int argc, _TCHAR* argv[])
{
	//std::thread connection{ connect_to_server };//start server
	//connection.detach();

	/*ClientSocket* client = new ClientSocket("localhost", 1080);

	string input = "";
	while (true)
	{
		string cmd = client->readline();
		cerr << cmd << '\n';
		getline(cin, input);
		client->write(input + "\n");
	}
	return 0;*/


	shared_ptr<GameLoop> loop{ new GameLoop() };
	return 0;
}

