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

void BasicDeck::ShuffleDeck()
{
	random_shuffle(m_cards.begin(), m_cards.end());
}

Card* BasicDeck::DrawCard(unsigned int pos)
{
	return m_cards.at(pos);
}

Card* BasicDeck::GetTopCard()
{
	return m_cards.back();
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
