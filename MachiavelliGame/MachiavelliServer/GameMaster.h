#pragma once
#include "stdafx.h"
#include "Board.h"
#include "Round.h"

using std::shared_ptr;
using std::unique_ptr;

class PlayerList;
class GameMaster
{
public:
	static GameMaster& getInstance();
	virtual ~GameMaster(){}

	void Tick();

	shared_ptr<PlayerList> GetPlayerList(){ return m_Board->GetPlayers(); }
private:
	GameMaster(){}
	shared_ptr<Board> m_Board;
	unique_ptr<Round> m_Round;

};

