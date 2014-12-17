#include "stdafx.h"
#include "RoundPhaseFactory.h"
#include "ChooseRollPhase.h"
#include "MainPhase.h"
#include "CleanUpPhase.h"


RoundPhaseFactory::RoundPhaseFactory()
{
}


RoundPhaseFactory::~RoundPhaseFactory()
{
}

RoundPhase* RoundPhaseFactory::createChoosePhase()
{
	return new ChooseRollPhase();
}

RoundPhase* RoundPhaseFactory::createMainPhase()
{
	return new MainPhase();
}

RoundPhase* RoundPhaseFactory::createCleanUpPhase()
{
	return new CleanUpPhase();
}
