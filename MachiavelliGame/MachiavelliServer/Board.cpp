#include "Board.h"


Board::Board()
{
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