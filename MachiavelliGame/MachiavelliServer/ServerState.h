#pragma once
#include "stdafx.h"

using std::shared_ptr;

class GameMaster;
class ServerState
{
public:
	ServerState();
	virtual ~ServerState();

	virtual void Handle(GameMaster& gm) = 0;
};

