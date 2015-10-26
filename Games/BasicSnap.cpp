#include "BasicSnap.h"
#include "BasicCard.h"

using namespace ::std;

SnapGame::SnapGame()
{
	m_discardedCards = new BasicDeck;
}

SnapGame::~SnapGame()
{
	for (auto players = m_players.begin(); players != m_players.end(); ++players)
	{
		delete players->second;
	}
	delete m_discardedCards;
}

void SnapGame::AddPlayer(const string& name, int numberOfCards)
{
	Deck* deck = new BasicDeck;
	DeckBuilder(deck, numberOfCards);
	m_players.insert(pair<string, Deck*>(name, deck));
}

Deck* SnapGame::Player(string name)
{
	return m_players.find(name)->second;
}

size_t SnapGame::HowManyPlayers() const
{
	return m_players.size();
}

void SnapGame::DeckBuilder(Deck* deck, int numberOfCards)
{
	for (int i = 0; i < numberOfCards; ++i)
	{
		int cardValue = i + 1;
		Card* card = new BasicCard(cardValue);
		deck->AddCard(card);
	}
}