#include "stdafx.h"
#include "RoleTPFactory.h"
#include "PickRoleTP.h"


RoleTPFactory::RoleTPFactory()
{
}


RoleTPFactory::~RoleTPFactory()
{
}

ITurnPhase* RoleTPFactory::createClosingTP()
{
	return new PickRoleTP();
}

ITurnPhase* RoleTPFactory::createExtraTP() 
{
	return new PickRoleTP();
}

ITurnPhase* RoleTPFactory::createSpecialTP()
{
	return new PickRoleTP();
}

ITurnPhase* RoleTPFactory::createIncomeTP()
{
	return new PickRoleTP();
}

ITurnPhase* RoleTPFactory::createBuildTP() 
{
	return new PickRoleTP();
}

ITurnPhase* RoleTPFactory::createPickRollTP()
{
	return new PickRoleTP();
}
