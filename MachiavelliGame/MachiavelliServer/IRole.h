#pragma once
#include "stdafx.h"
#include "BuildingCard.h"

	class Player;
	class IRole
	{
	public:
		IRole();
		virtual ~IRole();

		virtual void giveCard(Player player, BuildingCard card) = 0;
		virtual void giveMoney(Player player, int coins) = 0;
		virtual void destroyBuilding(Player player, int idx) = 0;

		virtual void build(Player player, int idx) = 0;
		virtual int stealMoney(Player player) = 0;

		virtual std::string getBuildingOptions(Player player) = 0;
		virtual void runIncomePhase(Player player) = 0;
		virtual void runSpecialPhase(Player player) = 0;
		virtual void runBuildingPhase(Player player) = 0;
		virtual void runExtraPhase(Player player) = 0;
	};
