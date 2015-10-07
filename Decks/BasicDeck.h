#ifndef BASIC_DECK_DEFINE
#define BASIC_DECK_DEFINE

#include "Deck.h"
#include "Card.h"
#include "BasicCard.h"
#include <vector>

class BasicDeck : public Deck
{
public:
	BasicDeck();
	void AddCard(Card*);
	void RemoveCard(Card*);
	Card* GetCard(unsigned int pos);
	size_t DeckSize();
	std::string CardName(unsigned int cardPos);
private:
	std::vector<Card*> m_cards;
};

#endif