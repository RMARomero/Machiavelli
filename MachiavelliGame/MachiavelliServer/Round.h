#pragma once
#include "RoundPhase.h"

class Player;
class Round
{
public:
	Round();
	virtual ~Round();
	void LoadPhases();

	void Tick(std::vector<Player> playerList);
private:
	std::vector<RoundPhase> m_Phases;
};

