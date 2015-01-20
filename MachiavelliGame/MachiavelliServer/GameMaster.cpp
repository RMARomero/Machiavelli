#include "stdafx.h"
#include "GameMaster.h"
#include "Round.h"

GameMaster& GameMaster::getInstance()
{
	static GameMaster _instance;
	return _instance;
}

GameMaster::GameMaster()
{
	m_Board = shared_ptr < Board > { new Board };
	m_Round = unique_ptr < Round > { new Round };
}


void GameMaster::Tick()
{
	m_Round->Tick(m_Board->GetPlayers());
}
