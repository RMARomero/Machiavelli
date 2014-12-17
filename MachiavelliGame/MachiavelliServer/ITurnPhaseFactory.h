#pragma once
class ITurnPhase;
class ITurnPhaseFactory
{
public:
	ITurnPhaseFactory();
	virtual ~ITurnPhaseFactory();

	virtual ITurnPhase* createClosingTP() = 0;
	virtual ITurnPhase* createExtraTP() = 0;
	virtual ITurnPhase* createSpecialTP() = 0;
	virtual ITurnPhase* createIncomeTP() = 0;
	virtual ITurnPhase* createBuildTP() = 0;
	virtual ITurnPhase* createPickRollTP() = 0;

};

