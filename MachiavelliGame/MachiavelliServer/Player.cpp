#include "Player.h"
#include "IRole.h"
#include "SocketManager.h"

using std::exception;

Player::~Player()
{
}

void Player::Build(int idx)
{
	shared_ptr<BuildingCard> card = m_Hand->Take(idx);
	m_Buildings->Push_Back(card);
}

int Player::StealMoney()
{
	int ret = m_iCoins;
	m_iCoins = 0;
	return ret; 
}

void Player::Send(string message){
	m_Socket->write(message + "\n");
}

void Player::AllowInput()
{
	m_Socket->write("input\n");
}


bool Player::ValidateAnswer(string input, vector<string> expectedAnswers)
{
	try {
		int position = stoi(input);
		return position >= 0 && position < expectedAnswers.size();
	}
	catch (...) {
		return false;
	}
}

string Player::RequestInput(string question)
{
	AllowInput();
	return GetPlayerInput();
}

int Player::RequestInput(string question, vector<string> expectedAnswers){
	string output = question.append("\n");
	for (int i = 0; i < expectedAnswers.size(); i++){
		output.append(" [");
		output.append(std::to_string(i));
		output.append("] ");
		output.append(expectedAnswers.at(i));
		output.append("\n");
	}

	string answer = "";
	do{
		Send(output);
		AllowInput();
		answer = GetPlayerInput();
	} while (!ValidateAnswer(answer, expectedAnswers));

	return stoi(answer);
}

string Player::GetPlayerInput()
{
	while (true) {
		ClientCommand command;
		SocketManager::getInstance().queue.get(command); // will block here unless there still are command objects in the queue
		shared_ptr<Socket> client{ command.get_client() };
		if (client) {
			try {
				if (command.get_player().get() == this){

					return command.get_cmd();
				}
				//PlayerInput.put(client.get()->get(), command.get_cmd());
			}
			catch (const exception& ex) {
				client->write("Sorry, ");
				client->write(ex.what());
				client->write("\n");
			}
			catch (...) {
				client->write("Sorry, something went wrong during handling of your request.\n");
			}
			//client->write(socketexample::prompt);
		}
		else {
			std::cerr << "trying to handle command for client who has disappeared...\n";
		}
	}

}

//void Player::ShowStats() {
//	string output = "\n";
//	output += " ==== STATS ====\n";
//
//	output += "> CITY <\n";
//
//	for (int i{ 0 }; i < GetCityCardContainer()->Size(); i++) {
//		output += " - " + GetCityCardContainer()->At(i)->GetName() + "\n";
//	}
//
//	output += "\n\n > DistrictCards < \n";
//
//	for (int i{ 0 }; i < GetDistrictCardContainer()->Size(); i++) {
//		output += " - " + GetDistrictCardContainer()->At(i)->GetName() + "\n";
//	}
//
//	output += "\n\n > Characters < \n";
//
//	for (int i{ 0 }; i < GetCharacterCardContainer()->Size(); i++) {
//		output += " - " + GetCharacterCardContainer()->At(i)->GetName() + "\n";
//	}
//
//	output += "\n\n Wallet: " + std::to_string(GetGoldPieces()) + "gp\n";
//
//	Send(output);
//}
