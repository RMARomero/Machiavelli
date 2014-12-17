#pragma once
#include "MainTurnPhase.h"
class SpecialTP :
	public MainTurnPhase
{
public:
	SpecialTP();
	virtual ~SpecialTP();

	void Tick(Player player);
};

