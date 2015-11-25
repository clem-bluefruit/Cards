#ifndef DECK_DEFINE
#define DECK_DEFINE

typedef unsigned int uint;

#include "Card.h"

class Deck
{
public:
	virtual void AddCard(Card*) = 0;
	virtual void RemoveCard(Card*) = 0;
	virtual Card* DrawCard(unsigned int pos) = 0;
	virtual size_t DeckSize() = 0;
	virtual ~Deck() {};
};

#endif