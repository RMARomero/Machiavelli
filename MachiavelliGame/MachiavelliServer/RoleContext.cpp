#include "stdafx.h"
#include "RoleContext.h"


RoleContext& RoleContext::getInstance()
{
	static RoleContext _instance;
	return _instance;
}

RoleContext::~RoleContext()
{
}
