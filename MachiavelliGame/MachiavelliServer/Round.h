#pragma once
#include "RoundPhase.h"
#include "PlayerList.h"

using std::shared_ptr;
using std::unique_ptr;

class Player;
class Round
{
public:
	Round();
	virtual ~Round();
	void LoadPhases();

	void Tick(shared_ptr<PlayerList> playerList);
private:
	unique_ptr<RoundPhase> m_Phases;
};

