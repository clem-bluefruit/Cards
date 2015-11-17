#ifndef BASIC_BLACKJACK_INCLUDED
#define BASIC_BLACKJACK_INCLUDED

#include "BasicDeck.h"
#include "BasicCard.h"
#include "Game.h"
#include <map>

class BlackJackGame : public Game
{
public:
	BlackJackGame();
	~BlackJackGame();
	BlackJackGame(const BlackJackGame&) = default;
	BlackJackGame& operator = (const BlackJackGame& rVal);
	void AddPlayer(const std::string& playerName, int deckSize = 0);
	void PlayerDrawCard(BasicDeck* deck);
	BasicDeck* Player(const std::string& playerName);
	size_t CurrentNumberOfPlayers() const;
private:
	std::map<std::string, BasicDeck*> m_players;
};

#endif