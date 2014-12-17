#include "stdafx.h"
#include "RoleContext.h"

using namespace std;

RoleContext RoleContext::getInstance()
{
	static RoleContext _instance;
	return _instance;
}

RoleContext::~RoleContext()
{
}
