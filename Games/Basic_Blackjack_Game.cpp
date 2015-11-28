#include "Basic_Blackjack_Game.h"
#include "BasicDeck.h"

using namespace ::PlayingCards;
using namespace ::std;

BlackjackGame::BlackjackGame()
{
	m_discardedCards = new BasicDeck;
	AddPlayer("Dealer");
	DeckBuilder();
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

void BlackjackGame::DealCard(const string& player)
{
	BasicDeck* deck = Player(player);
	auto topCard = m_houseDeck.begin();
	const uint cardValue = topCard->second;
	const string cardName = topCard->first;
	BasicCard* card = new BasicCard(cardValue, cardName);
	deck->AddCard(card);
	m_houseDeck.erase(topCard);
}

BasicDeck* BlackjackGame::Player(const string& name)
{
	return m_players.find(name)->second;
}

size_t BlackjackGame::CurrentNumberOfPlayers() const
{
	return m_players.size();
}

size_t BlackjackGame::RemainingCards() const
{
	return m_houseDeck.size();
}

size_t BlackjackGame::PlayerHandSize(BasicDeck* player)
{
	return player->DeckSize();
}

void BlackjackGame::DeckBuilder()
{
	for (uint suite = BlackJackCards::Suite::SPADES; suite <= BlackJackCards::Suite::CLUBS; suite++)
	{
		for (uint card = BlackJackCards::Value::ACE; card <= BlackJackCards::Value::KING; card++)
		{
			pair<string, uint> cardDetails;
			cardDetails.first = BlackJackCards::CardName(BlackJackCards::Value(card)) + " of " + BlackJackCards::CardSuite(BlackJackCards::Suite(suite));
			cardDetails.second = (card >= m_royalCardValues) ? m_royalCardValues : BlackJackCards::Value(card);
			m_houseDeck.insert(cardDetails);
		}
	}
}