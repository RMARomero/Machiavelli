#pragma once
#include "CleanUpTurnPhase.h"
class ClosingTP :
	public CleanUpTurnPhase
{
public:
	ClosingTP();
	virtual ~ClosingTP();

	void Tick(Player player);
};

