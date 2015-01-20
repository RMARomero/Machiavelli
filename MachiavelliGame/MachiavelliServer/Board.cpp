#include "Board.h"


Board::Board()
{
	m_Players = shared_ptr< PlayerList > { new PlayerList};

	m_DrawDeck = shared_ptr < CardDeck<BuildingCard> > { new CardDeck < BuildingCard > };
	m_DiscardPile = shared_ptr < CardDeck<BuildingCard> > { new CardDeck < BuildingCard > };
}


Board::~Board()
{
}

std::shared_ptr<BuildingCard> Board::DrawCard()
{
	return m_DrawDeck->Pop();
}

void Board::resetDeck()
{
	m_DrawDeck->ClearDeck();
	m_DrawDeck->SetCards(m_DiscardPile->TakeCardPile());
	m_DrawDeck->Shuffle();
}