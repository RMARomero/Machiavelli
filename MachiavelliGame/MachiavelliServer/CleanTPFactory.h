#pragma once
#include "ITurnPhaseFactory.h"
class CleanTPFactory :
	public ITurnPhaseFactory
{
public:
	CleanTPFactory();
	virtual ~CleanTPFactory();

	ITurnPhase* createClosingTP();
	ITurnPhase* createExtraTP();
	ITurnPhase* createSpecialTP();
	ITurnPhase* createIncomeTP();
	ITurnPhase* createBuildTP();
	ITurnPhase* createPickRollTP();
};

