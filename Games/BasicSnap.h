#ifndef SNAP_DEFINED
#define SNAP_DEFINED

#include "BasicCard.h"
#include "Deck.h"
#include "BasicDeck.h"
#include <string>
#include <map>

class SnapGame
{
public:
	SnapGame();
	~SnapGame();
	void AddPlayer(const std::string& name, int numberOfCards = 0);
	void PlayerDrawCard(BasicDeck* playerDeck);
	BasicDeck* Player(const std::string& name);
	size_t HowManyPlayers() const;
	size_t DiscardDeckSize() const;
	bool CallSnap() const;
private:
	std::map<std::string, BasicDeck*> m_players;
	Deck* m_discardedCards;
	void DeckBuilder(BasicDeck* deck, int numberOfCards);

};

#endif