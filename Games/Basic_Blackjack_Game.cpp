#include "Basic_Blackjack_Game.h"
#include "BasicDeck.h"

using namespace ::std;

BlackjackGame::BlackjackGame()
{
	m_discardedCards = new BasicDeck;
	AddPlayer("Dealer");
}

BlackjackGame::~BlackjackGame()
{
	for (auto players = m_players.begin(); players != m_players.end(); ++players)
		delete players->second;
	delete m_discardedCards;
}

void BlackjackGame::AddPlayer(const string& playerName, int deckSize)
{
	BasicDeck* deck = new BasicDeck;
	m_players.insert(pair<string, BasicDeck*>(playerName, deck));
}

void BlackjackGame::PlayerDrawCard(BasicDeck* deck)
{
	Card* card = deck->GetTopCard();
	m_discardedCards->AddCard(card);
	deck->RemoveCard(card);
}

BasicDeck* BlackjackGame::Player(const string& name)
{
	return m_players.find(name)->second;
}

size_t BlackjackGame::CurrentNumberOfPlayers() const
{
	return m_players.size();
}