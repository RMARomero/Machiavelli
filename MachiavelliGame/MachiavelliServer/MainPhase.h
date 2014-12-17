#pragma once
#include "RoundPhase.h"
class MainPhase :
	public RoundPhase
{
public:
	MainPhase();
	virtual ~MainPhase();

	void Tick(Player player);
};

