#pragma once
#include "MainTurnPhase.h"
class ExtraTP :
	public MainTurnPhase
{
public:
	ExtraTP();
	virtual ~ExtraTP();

	void Tick(Player player);
};

