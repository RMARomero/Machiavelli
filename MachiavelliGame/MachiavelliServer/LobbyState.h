#pragma once
#include "ServerState.h"


class LobbyState :
	public ServerState
{
public:
	LobbyState();
	virtual ~LobbyState();

	void Handle(GameMaster& gm){}
};

