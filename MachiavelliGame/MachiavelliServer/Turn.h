#pragma once
#include "ITurnPhase.h"

class Player;
class Turn
{
public:
	Turn();
	virtual ~Turn();


	void Tick(Player player);

private:
	std::vector<ITurnPhase> m_Phases;
};

