#ifndef BASIC_BLACKJACK_INCLUDED
#define BASIC_BLACKJACK_INCLUDED

typedef unsigned int uint;

#include "BasicDeck.h"
#include "BasicCard.h"
#include "Game.h"
#include "PlayingCards.h"
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
	void DealCard(const std::string& player);
	BasicDeck* Player(const std::string& playerName);
	size_t CurrentNumberOfPlayers() const;
	size_t RemainingCards() const;
	size_t PlayerHandSize(BasicDeck* player);
	uint HandValue(BasicDeck* deck);
private:
	std::map<std::string, BasicDeck*> m_players;
	BasicDeck* m_discardedCards;
	std::map<std::string, uint> m_houseDeck;
	void DeckBuilder();
	const uint m_royalCardValues = 10;
};

#endif