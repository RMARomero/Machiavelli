#pragma once
#include "stdafx.h"
#include "BuildingCard.h"
#include "Player.h"

namespace std{

	class IRole
	{
	public:
		IRole();
		virtual ~IRole();

		virtual void giveCard(Player player, BuildingCard card);
		virtual void giveMoney(Player player, int coins);
		virtual void destroyBuilding(Player player, int idx);

		virtual void build(Player player, int idx);
		virtual int stealMoney(Player player);

		virtual std::string getBuildingOptions(Player player);
		virtual void runIncomePhase(Player player);
		virtual void runSpecialPhase(Player player);
		virtual void runBuildingPhase(Player player);
		virtual void runExtraPhase(Player player);
	};
}

