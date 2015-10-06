#ifndef DECK_DEFINE
#define DECK_DEFINE

#include "Card.h"

class Deck
{
	virtual void AddCard(Card*) = 0;
	virtual Card* GetCard() = 0;
};

#endif