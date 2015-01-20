#include "stdafx.h"
#include "GameLoop.h"

#include "Socket.h"
#include <iostream>
#include <fstream>
#include <string>

#include <thread>
#include <exception>
#include <memory>

using namespace std;

GameLoop::GameLoop()
{
	getServerInformation();

	shared_ptr<ClientSocket> server{ new ClientSocket(m_cIP, m_iPort) };

	while (true) { // game loop
		try {
			// read first line of request
			string cmd = server->readline();

			if (cmd == "Bye!") {
				break; // out of game loop, will end this thread and close connection
			}
			else if (cmd == "input"){
				string input = "";
				getline(cin, input);
				server->write(input + "\n");
			}
			else{
				cerr << cmd << '\n';
			}
		}
		catch (const exception& ex) {
			//server->write("ERROR: ");
			//server->write(ex.what());
			//server->write("\n");
		}
		catch (...) {
			//server->write("ERROR: something went wrong during handling of your request. Sorry!\n");
		}
	}
}

GameLoop::~GameLoop()
{
	delete[] m_cIP;
}

void GameLoop::getServerInformation(){
	std::string ip;
	const string textfile("../assets/config.txt");
	// input file stream, opent textfile voor lezen
	ifstream input_file(textfile);
	input_file >> ip >> m_iPort;

	m_cIP = &ip[0];

}
