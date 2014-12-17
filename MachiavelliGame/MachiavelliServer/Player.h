#pragma once
#include "stdafx.h"
#include "BuildingCard.h"


namespace std {

	class IRole;
	class Player
	{
	public:
		Player(int coins, bool king) : m_iCoins{ coins }, m_bKingToken{ king } {}
		virtual ~Player();

		void Run();

		void giveCard(BuildingCard card) { m_Hand.push_back(card); }
		void giveMoney(int coins) { m_iCoins += coins; }
		void destroyBuilding(int idx) { m_Buildings.erase(m_Buildings.begin() + idx); }

		void build(int idx);
		int stealMoney();

	protected:
		bool m_bKingToken;
		int m_iCoins;
		unique_ptr<IRole> m_Role;
		vector<BuildingCard> m_Hand;
		vector<BuildingCard> m_Buildings;

	};

}// namespace std

