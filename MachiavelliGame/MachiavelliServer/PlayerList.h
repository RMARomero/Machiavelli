#pragma once
#include "stdafx.h"
#include "Player.h"

using std::vector;
using std::string;
using std::shared_ptr;

class PlayerList
{
private:
	vector<shared_ptr<Player>> m_PlayerList;
	vector<shared_ptr<int>> m_Temp;
public:
	PlayerList(){}
	virtual ~PlayerList(){}

	shared_ptr<Player> GetPlayerAt(int position);
	shared_ptr<Player> GetPlayerByRole(eRole role);
	shared_ptr<Player> GetPlayerByName(string name);
	void InsertPlayer(shared_ptr<Player> player);
	void RemovePlayer(shared_ptr<Player> player);
	void SendAll(string message);
	void SendAllBut(shared_ptr<Player> player, string message);
	int Size();
};

