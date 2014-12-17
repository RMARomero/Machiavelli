#pragma once
#include "ITurnPhaseFactory.h"
class RoleTPFactory :
	public ITurnPhaseFactory
{
public:
	RoleTPFactory();
	virtual ~RoleTPFactory();

	ITurnPhase* createClosingTP();
	ITurnPhase* createExtraTP();
	ITurnPhase* createSpecialTP();
	ITurnPhase* createIncomeTP();
	ITurnPhase* createBuildTP();
	ITurnPhase* createPickRollTP();
};

