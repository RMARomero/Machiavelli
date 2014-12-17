#pragma once
#include "ChooseRoleTurnPhase.h"
class PickRoleTP :
	public ChooseRoleTurnPhase
{
public:
	PickRoleTP();
	virtual ~PickRoleTP();


	void Tick(Player player);
};

