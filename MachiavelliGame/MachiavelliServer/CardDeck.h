#pragma once
#include "BuildingCard.h"

using std::shared_ptr;
using std::vector;
using std::string;

template<class T>
class CardDeck
{
private:
	vector<shared_ptr<T>> m_Cards;
public:
	CardDeck(){}
	virtual ~CardDeck(){}

	bool HasCard(string name)
	{
		bool result = false;
		for (int i{ 0 }; i < m_Cards.size() && !result; i++)
		{
			result = (m_Cards.at(i)->GetName() == name);
		}
		return result;
	}

	shared_ptr<T> At(int position)
	{
		shared_ptr<T> card{ nullptr };
		card = m_Cards.at(position);

		return card;
	}

	shared_ptr<T> Pop()
	{
		shared_ptr<T> card{ nullptr };
		if (!m_Cards.empty()){
			card = m_Cards.back();
			m_Cards.pop_back();
		}
		return card;
	}

	shared_ptr<T> Peek(){
		shared_ptr<T> card{ nullptr };
		if (!m_Cards.empty()){
			card = m_Cards.back();
		}
		return card;
	}

	shared_ptr<T> Take(int position)
	{
		shared_ptr<T> card{ nullptr };
		card = m_Cards.at(position);
		m_Cards.erase(m_Cards.begin() + position);
		return card;
	}

	void Shuffle()
	{
		std::random_shuffle(m_Cards.begin(), m_Cards.end());
	}

	void Push_Back(shared_ptr<T> card)
	{
		m_Cards.push_back(card);
	}

	int Size()
	{
		return m_Cards.size();
	}

	vector<shared_ptr<T>> GetCardDeck()
	{
		return m_Cards;
	}

	vector<shared_ptr<T>> TakeCardPile()
	{
		vector<shared_ptr<T>> tmp = m_Cards;
		m_Cards.clear();
		return tmp;
	}

	void SetCards(vector<shared_ptr<T>> cards)
	{
		m_Cards = cards;
	}

	void ClearDeck()
	{
		m_Cards.clear();
	}

	void AddCardDeck(vector<shared_ptr<T>> deck)
	{
		m_Cards = deck;
	}

	vector<string> ToVector()
	{
		vector<string> cardNames;

		for (int i{ 0 }; i < m_Cards.size(); i++) {
			cardNames.push_back(m_Cards.at(i)->GetName());
		}
		return cardNames;
	}

};