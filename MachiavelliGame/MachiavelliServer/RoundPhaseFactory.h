#pragma once
class RoundPhase;
class RoundPhaseFactory
{
public:
	RoundPhaseFactory();
	virtual ~RoundPhaseFactory();

	RoundPhase* createChoosePhase();
	RoundPhase* createMainPhase();
	RoundPhase* createCleanUpPhase();
};

