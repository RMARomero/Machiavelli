#pragma once
#include "Board.h"

class GameMaster
{
public:
	static GameMaster& getInstance();
	virtual ~GameMaster();

	void Tick();

private:
	GameMaster(){}
	Board m_Board;
};

