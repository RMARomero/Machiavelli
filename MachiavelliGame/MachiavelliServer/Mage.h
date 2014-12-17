#pragma once
#include "IRole.h"


	class Mage :
		public IRole
	{
	public:
		Mage();
		virtual ~Mage();

		void giveCard(Player player, BuildingCard card);
		void giveMoney(Player player, int coins);
		void destroyBuilding(Player player, int idx);

		void build(Player player, int idx);
		int stealMoney(Player player);

		std::string getBuildingOptions(Player player);
		void runIncomePhase(Player player);
		void runSpecialPhase(Player player);
		void runBuildingPhase(Player player);
		void runExtraPhase(Player player);

	};

