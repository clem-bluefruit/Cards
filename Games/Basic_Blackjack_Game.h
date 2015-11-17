#ifndef BASIC_BLACKJACK_INCLUDED
#define BASIC_BLACKJACK_INCLUDED

#include "BasicDeck.h"
#include "BasicCard.h"
#include "Game.h"
#include <map>

class BlackjackGame : public Game
{
public:
	BlackjackGame();
	~BlackjackGame();
	BlackjackGame(const BlackjackGame&) = default;
	BlackjackGame& operator = (const BlackjackGame& rVal);
	void AddPlayer(const std::string& playerName, int deckSize = 0);
	void PlayerDrawCard(BasicDeck* deck);
	BasicDeck* Player(const std::string& playerName);
	size_t CurrentNumberOfPlayers() const;
private:
	std::map<std::string, BasicDeck*> m_players;
	BasicDeck* m_discardedCards;
};

#endif