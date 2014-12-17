#include "stdafx.h"
#include "GameMaster.h"

GameMaster& GameMaster::getInstance()
{
	static GameMaster _instance;
	return _instance;
}

GameMaster::~GameMaster()
{
}

void GameMaster::Tick()
{

}
