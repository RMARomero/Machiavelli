#include "stdafx.h"
#include "GameMaster.h"

GameMaster& GameMaster::getInstance()
{
	static GameMaster _instance;
	return _instance;
}


void GameMaster::Tick()
{

}
