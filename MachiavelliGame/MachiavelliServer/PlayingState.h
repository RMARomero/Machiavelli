#pragma once
#include "ServerState.h"
class PlayingState :
	public ServerState
{
public:
	PlayingState();
	virtual ~PlayingState();

	void Handle(GameMaster& gm){}
};

