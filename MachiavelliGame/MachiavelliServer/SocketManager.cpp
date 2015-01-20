#include "stdafx.h"
#include "SocketManager.h"
#include "GameMaster.h"

#include <iostream>
#include <fstream>
#include <exception>


using std::shared_ptr;
using std::exception;

SocketManager& SocketManager::getInstance() 
{
	static SocketManager instance;
	return instance;
}


void Start_GameLoop(/*shared_ptr<GameManager> gm*/)
{
	GameMaster::getInstance().Tick();
}

void handle_client(Socket* socket) // this function runs in a separate thread
{
	shared_ptr<Socket> client{ socket };
	shared_ptr<Player> player{ new Player(client) };

	/* Get Player Name: */
	player->Send("Welcome to the fancy game Citadels! What is your name?\n");
	player->AllowInput();
	string name = client->readline();

	/* TODO: */
	// Check if the game is already in progress...
	//If in progress:
	/* Tell the player he missed the train... return method (and thus end thread and close connection) */

	//If not in progress:
	player->Send("\nLet's wait untill all players are ready! To quit, type 'quit'.\n");
	player->SetName(name);

	GameMaster::getInstance().GetPlayerList()->InsertPlayer(player);
	//gm->GetPlayerList()->InsertPlayer(player);

	while (true) { // game loop
		try {
			// read first line of request
			string cmd = client->readline();
			std::cerr << "client (" << client->get() << ") said: " << cmd << '\n';

			if (cmd == "quit") {
				player->Send("Bye!\n");
				//client->write(socketexample::prompt);
				break; // out of game loop, will end this thread and close connection
			}

			ClientCommand command{ cmd, player, client };
			SocketManager::getInstance().queue.put(command);

		}
		catch (const std::exception& ex) {
			player->Send("ERROR: ");
			player->Send(ex.what());
			player->Send("\n");
		}
		catch (...) {
			player->Send("ERROR: something went wrong during handling of your request. Sorry!\n");
		}
	}
}

void SocketManager::getServerInformation(){
	std::string ip;
	const string textfile("../assets/config.txt");
	// input file stream, opent textfile voor lezen
	std::ifstream input_file(textfile);
	input_file >> ip >> m_Port;

}

void SocketManager::start() 
{
	getServerInformation();

	//shared_ptr < GameMaster > gm{ GameMaster::getInstance() };

	// start command consumer thread
	std::thread consumer{ Start_GameLoop };
	consumer.detach(); // detaching is usually ugly, but in this case the right thing to do

	// create a server socket
	ServerSocket server(m_Port);

	while (true) {
		try {
			// wait for connection from client; will create new socket
			std::cerr << "server listening" << '\n';
			Socket* client = nullptr;

			while ((client = server.accept()) != nullptr) {
				// communicate with client over new socket in separate thread
				std::thread handler{ handle_client, client};
				handler.detach(); // detaching is usually ugly, but in this case the right thing to do
				std::cerr << "server listening again" << '\n';
			}
		}
		catch (const exception& ex) {
			std::cerr << ex.what() << ", resuming..." << '\n';
		}
	}
}

