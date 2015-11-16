#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "BasicCard.h"
#include "Deck.h"
#include "BasicDeck.h"
#include <string>
#include <map>

class Game
{
public:
	virtual void AddPlayer(const std::string&, int) = 0;
	virtual void PlayerDrawCard(BasicDeck*) = 0;
	virtual BasicDeck* Player(const std::string&) = 0;
	virtual size_t CurrentNumberOfPlayers() const = 0;
	virtual ~Game() {};
};

#endif