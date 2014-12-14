#pragma once
#include "stdafx.h"
#include "Player.h"
#include "BuildingCard.h"
namespace std {
	class Board
	{
	public:
		Board();
		virtual ~Board();

		vector<Player> getPlayers(){ return m_Players; }
		BuildingCard drawCard();
		void discardCard(BuildingCard card) { m_DiscardPile.push_back(card); }
		void shuffleDeck() { std::random_shuffle(m_DrawDeck.begin(), m_DrawDeck.end()); }
		void resetDeck();


	private:
		vector<Player> m_Players;
		deque<BuildingCard> m_DrawDeck;
		vector<BuildingCard> m_DiscardPile;
	};
}//namespace std

