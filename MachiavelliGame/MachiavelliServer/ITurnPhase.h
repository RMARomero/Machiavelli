#pragma once
class Player;
class ITurnPhase
{
public:
	ITurnPhase();
	virtual ~ITurnPhase();

	virtual void Tick(Player player) = 0;
};

