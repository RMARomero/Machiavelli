#pragma once
#include "ITurnPhaseFactory.h"
class MainTPFactory :
	public ITurnPhaseFactory
{
public:
	MainTPFactory();
	virtual ~MainTPFactory();

	ITurnPhase* createClosingTP();
	ITurnPhase* createExtraTP();
	ITurnPhase* createSpecialTP();
	ITurnPhase* createIncomeTP();
	ITurnPhase* createBuildTP();
	ITurnPhase* createPickRollTP();
};

