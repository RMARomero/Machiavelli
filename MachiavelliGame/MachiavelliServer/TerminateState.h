#pragma once
#include "ServerState.h"
class TerminateState :
	public ServerState
{
public:
	TerminateState();
	virtual ~TerminateState();

	void Handle(GameMaster& gm){}
};

