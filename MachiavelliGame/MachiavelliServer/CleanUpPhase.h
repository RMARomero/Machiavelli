#pragma once
#include "RoundPhase.h"
class CleanUpPhase :
	public RoundPhase
{
public:
	CleanUpPhase();
	virtual ~CleanUpPhase();

	void Tick(Player player);
};

