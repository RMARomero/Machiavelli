#pragma once
class Player;
class RoundPhase
{
public:
	RoundPhase();
	virtual ~RoundPhase();

	virtual void Tick(Player player) = 0;
};

