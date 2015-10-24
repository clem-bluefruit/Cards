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
	Deck* Player(std::string name);
	size_t HowManyPlayers() const;
private:
	std::map<std::string, Deck*> m_players;
	Deck* m_discardedCards;
	void DeckBuilder(Deck* deck, int numberOfCards);
};

#endif