#pragma once
#include "stdafx.h"
#include "PlayerList.h"
#include "BuildingCard.h"

using std::shared_ptr;

class Board
{
public:
	Board();
	virtual ~Board();

	shared_ptr<PlayerList> GetPlayers(){ return m_Players; }
	shared_ptr<BuildingCard> DrawCard();
	void discardCard(shared_ptr<BuildingCard> card) { m_DiscardPile->Push_Back(card); }
	void shuffleDeck() { m_DrawDeck->Shuffle(); }
	void resetDeck();


private:
	shared_ptr<PlayerList> m_Players;

	shared_ptr<CardDeck<BuildingCard>> m_DrawDeck;
	shared_ptr<CardDeck<BuildingCard>> m_DiscardPile;
};

