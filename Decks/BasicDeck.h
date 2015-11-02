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
	~BasicDeck();
	Card* DrawCard(unsigned int pos);
	Card* GetTopCard();
	void AddCard(Card* card);
	void RemoveCard(Card* card);
	size_t DeckSize();
	std::string CardName(unsigned int cardPos);
	unsigned int CardValue(unsigned int cardPos);
private:
	std::vector<Card*> m_cards;
};

#endif