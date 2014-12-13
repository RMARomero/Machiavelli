#pragma once
#include "stdafx.h"
#include "BuildingCard.h"

namespace std {

	class IPlayer
	{
	public:
		IPlayer(int coins, bool king) : m_iCoins{ coins }, m_bKingToken{ king } {}
		virtual ~IPlayer();

		void giveCard(BuildingCard card) { m_Hand.push_back(card); }
		void giveMoney(int coins) { m_iCoins += coins; }
		void destroyBuilding(int idx) { m_Buildings.erase(m_Buildings.begin + idx); }

		void build(int idx);
		int stealMoney();

		virtual string getBuildingOptions() = 0;
		virtual void earnBuildingMoney() = 0;
		virtual void runIncomePhase() = 0;
		virtual void runSpecialPhase() = 0;
		virtual void runBuildingPhase() = 0;
		virtual void runExtraPhase() = 0;

	protected:
		bool m_bKingToken;
		int m_iCoins;
		Role m_eRole;
		vector<BuildingCard> m_Hand;
		vector<BuildingCard> m_Buildings;

	};

}// namespace std

