#pragma once
#include "MainTurnPhase.h"
class IncomeTP :
	public MainTurnPhase
{
public:
	IncomeTP();
	virtual ~IncomeTP();

	void Tick(Player player);
};

