#include "stdafx.h"
#include "ServerStateFactory.h"


ServerStateFactory& ServerStateFactory::getInstance()
{
	static ServerStateFactory _instance;
	return _instance;
}

ServerStateFactory::~ServerStateFactory()
{
}
