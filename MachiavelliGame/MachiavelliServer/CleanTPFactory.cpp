#include "stdafx.h"
#include "CleanTPFactory.h"
#include "ClosingTP.h"


CleanTPFactory::CleanTPFactory()
{
}


CleanTPFactory::~CleanTPFactory()
{
}

ITurnPhase* CleanTPFactory::createClosingTP()
{
	return new ClosingTP();
}

ITurnPhase* CleanTPFactory::createExtraTP()
{
	return new ClosingTP();
}

ITurnPhase* CleanTPFactory::createSpecialTP()
{
	return new ClosingTP();
}

ITurnPhase* CleanTPFactory::createIncomeTP()
{
	return new ClosingTP();
}

ITurnPhase* CleanTPFactory::createBuildTP()
{
	return new ClosingTP();
}

ITurnPhase* CleanTPFactory::createPickRollTP()
{
	return new ClosingTP();
}