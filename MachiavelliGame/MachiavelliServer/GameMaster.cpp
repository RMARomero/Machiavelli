#include "stdafx.h"
#include "GameMaster.h"
#include "Round.h"
#include "ServerStateFactory.h"

GameMaster& GameMaster::getInstance()
{
	static GameMaster _instance;
	return _instance;
}

GameMaster::GameMaster()
{
	m_Board = shared_ptr < Board > { new Board };
	m_Round = unique_ptr < Round > { new Round };
	ServerStateFactory& factory = ServerStateFactory::getInstance();
	m_State = std::move( factory.createLobbyState() );
}


void GameMaster::Tick()
{
	m_State->Handle(*this);
}
