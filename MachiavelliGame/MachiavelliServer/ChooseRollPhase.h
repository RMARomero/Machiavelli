#pragma once
#include "RoundPhase.h"
class ChooseRollPhase :
	public RoundPhase
{
public:
	ChooseRollPhase();
	virtual ~ChooseRollPhase();

	void Tick(Player player);
};

