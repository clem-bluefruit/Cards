#ifndef DECK_DEFINE
#define DECK_DEFINE

#include "Card.h"

class Deck
{
public:
	virtual void AddCard(Card*) = 0;
	virtual void RemoveCard(Card*) = 0;
	virtual Card* GetCard(unsigned int pos) = 0;
	virtual size_t DeckSize() = 0;
};

#endif