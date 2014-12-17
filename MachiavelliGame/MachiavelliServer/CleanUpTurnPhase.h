#pragma once
#include "ITurnPhase.h"
class CleanUpTurnPhase :
	public ITurnPhase
{
public:
	CleanUpTurnPhase();
	virtual ~CleanUpTurnPhase();

	virtual void Tick(Player player) = 0;
};

