#pragma once
#include "ITurnPhase.h"
class ChooseRoleTurnPhase :
	public ITurnPhase
{
public:
	ChooseRoleTurnPhase();
	virtual ~ChooseRoleTurnPhase();

	virtual void Tick(Player player) = 0;
};

