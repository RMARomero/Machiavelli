#pragma once
#include "stdafx.h"
#include "Player.h"
#include "BuildingCard.h"
	class Board
	{
	public:
		Board();
		virtual ~Board();

		std::vector<Player> getPlayers(){ return m_Players; }
		BuildingCard drawCard();
		void discardCard(BuildingCard card) { m_DiscardPile.push_back(card); }
		void shuffleDeck() { std::random_shuffle(m_DrawDeck.begin(), m_DrawDeck.end()); }
		void resetDeck();


	private:
		std::vector<Player> m_Players;
		std::deque<BuildingCard> m_DrawDeck;
		std::vector<BuildingCard> m_DiscardPile;
	};

