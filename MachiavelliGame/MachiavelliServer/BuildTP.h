#pragma once
#include "MainTurnPhase.h"
class BuildTP :
	public MainTurnPhase
{
public:
	BuildTP();
	virtual ~BuildTP();

	void Tick(Player player);
};

