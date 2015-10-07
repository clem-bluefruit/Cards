#include "BasicDeck.h"

using namespace ::std;

BasicDeck::BasicDeck() :
m_cards(0)
{
}

void BasicDeck::AddCard(Card* card)
{
	m_cards.push_back(card);
}

void BasicDeck::RemoveCard(Card* card)
{
	unsigned int index = 0;
	while (m_cards.at(index) != card)
		++index;
	m_cards.erase(m_cards.begin() + index);
}

Card* BasicDeck::GetCard(unsigned int pos)
{
	return m_cards.at(pos);
}

size_t BasicDeck::DeckSize()
{
	return m_cards.size();
}

string BasicDeck::CardName(unsigned int cardPos)
{
	return GetCard(cardPos)->ViewCardName();
}