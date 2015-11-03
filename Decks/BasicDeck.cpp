#include "BasicDeck.h"

using namespace ::std;

BasicDeck::BasicDeck() :
m_cards(0)
{
}

BasicDeck::~BasicDeck()
{
	for (Card* c : m_cards)
	{
		delete c;
	}
	m_cards.clear();
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

Card* BasicDeck::DrawCard(unsigned int pos)
{
	return m_cards.at(pos);
}

Card* BasicDeck::GetTopCard()
{
	return (m_cards.size() > 0) ? m_cards.back() : m_cards.at(0);
}

size_t BasicDeck::DeckSize()
{
	return m_cards.size();
}

string BasicDeck::CardName(unsigned int cardPos)
{
	return DrawCard(cardPos)->ViewCardName();
}

unsigned int BasicDeck::CardValue(unsigned int cardPos)
{
	return DrawCard(cardPos)->ViewCardValue();
}
