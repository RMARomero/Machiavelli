#pragma once
#include "stdafx.h"
//#include "IRole.h"
#include "BuildingCard.h"


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
		//std::unique_ptr<IRole> m_Role;
		std::vector<BuildingCard> m_Hand;
		std::vector<BuildingCard> m_Buildings;

	};

