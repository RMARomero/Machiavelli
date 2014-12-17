#pragma once
#include "ITurnPhase.h"
class MainTurnPhase :
	public ITurnPhase
{
public:
	MainTurnPhase();
	virtual ~MainTurnPhase();

	virtual void Tick(Player player) = 0;
};

