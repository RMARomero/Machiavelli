#pragma once
#include "stdafx.h"
#include "BuildingCard.h"
#include "Socket.h"
#include "CardDeck.h"

using std::vector;
using std::shared_ptr;
using std::string;

class IRole;
class Player
{
public:
	Player(shared_ptr<Socket> client): m_Socket{ client }{}
	virtual ~Player();

	void Run();

	void GiveCard(shared_ptr<BuildingCard> card) { m_Hand->Push_Back(card); }
	void GiveMoney(int coins) { m_iCoins += coins; }

	eRole GetRole() { return m_eRole; }
	string GetName() { return m_sName; }
	shared_ptr<BuildingCard> DestroyBuilding(int idx) { m_Buildings->Take(idx); }

	void SetName(string name){ m_sName = name; }
	void Send(string Message);
	void AllowInput();

	string RequestInput(string question);
	int RequestInput(string question, vector<string> expectedAnswers);
	string GetPlayerInput();

	void Build(int idx);
	int StealMoney();

protected:
	string m_sName;
	int m_iAge;
	bool m_bKingToken;
	int m_iCoins;
	eRole m_eRole;

	shared_ptr<Socket> m_Socket;
	shared_ptr<CardDeck<BuildingCard>> m_Hand;
	shared_ptr<CardDeck<BuildingCard>> m_Buildings;

	bool ValidateAnswer(string input, vector<string> expectedAnswers);
};

