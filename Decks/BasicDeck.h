#ifndef BASIC_DECK_DEFINE
#define BASIC_DECK_DEFINE

#include "Deck.h"
#include "Card.h"
#include "BasicCard.h"
#include <vector>
#include <algorithm>

class BasicDeck : public Deck
{
public:
	BasicDeck();
	~BasicDeck();
	BasicDeck(const BasicDeck&) = default;
	BasicDeck& operator = (const BasicDeck& rVal);
	Card* DrawCard(unsigned int pos = 0);
	Card* GetTopCard();
	void AddCard(Card* card);
	void RemoveCard(Card* card);
	void ShuffleDeck();
	size_t DeckSize();
	std::string CardName(unsigned int cardPos);
	unsigned int CardValue(unsigned int cardPos);
private:
	std::vector<Card*> m_cards;
};

#endif