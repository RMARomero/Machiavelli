#include "stdafx.h"
#include "MainTPFactory.h"
#include "SpecialTP.h"
#include "IncomeTP.h"
#include "ExtraTP.h"
#include "BuildTP.h"


MainTPFactory::MainTPFactory()
{
}


MainTPFactory::~MainTPFactory()
{
}

ITurnPhase* MainTPFactory::createClosingTP()
{
	return new IncomeTP();
}

ITurnPhase* MainTPFactory::createExtraTP()
{
	return new ExtraTP();
}

ITurnPhase* MainTPFactory::createSpecialTP()
{
	return new SpecialTP();
}

ITurnPhase* MainTPFactory::createIncomeTP()
{
	return new IncomeTP();
}

ITurnPhase* MainTPFactory::createBuildTP()
{
	return new BuildTP();
}

ITurnPhase* MainTPFactory::createPickRollTP()
{
	return new IncomeTP();
}