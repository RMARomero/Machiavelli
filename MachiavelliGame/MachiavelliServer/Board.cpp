#include "Board.h"

using namespace std;

Board::Board()
{
}


Board::~Board()
{
}

BuildingCard Board::drawCard()
{
	auto card = move(m_DrawDeck.front());
	m_DrawDeck.pop_front();
	return card;
}

void Board::resetDeck()
{
	//first move everything from the discard pile into the drawing deck
	m_DrawDeck.insert(
		m_DrawDeck.begin(),
		std::make_move_iterator(m_DiscardPile.begin()),
		std::make_move_iterator(m_DiscardPile.end())
		);
	//then clear the discard pile
	m_DiscardPile.clear();
	//then shuffle the deck
	shuffleDeck();
}