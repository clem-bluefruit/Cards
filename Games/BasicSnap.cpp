#include "BasicSnap.h"
#include "BasicCard.h"

using namespace ::std;

BasicSnap::BasicSnap()
{
	m_discardedCards = new BasicDeck;
}

BasicSnap::~BasicSnap()
{
	for (auto players = m_players.begin(); players != m_players.end(); ++players)
		delete players->second;
	delete m_discardedCards;
}

void BasicSnap::AddPlayer(const string& name, int numberOfCards)
{
	BasicDeck* deck = new BasicDeck;
	DeckBuilder(deck, numberOfCards);
	m_players.insert(pair<string, BasicDeck*>(name, deck));
}

void BasicSnap::PlayerDrawCard(BasicDeck* playerDeck)
{
	Card* card = playerDeck->GetTopCard();
	m_discardedCards->AddCard(card);
	playerDeck->RemoveCard(card);
}

void BasicSnap::DeckBuilder(BasicDeck* deck, size_t numberOfCards)
{
	for (unsigned int i = 0; i < numberOfCards; ++i)
	{
		unsigned int cardValue = i + 1;
		Card* card = new BasicCard(cardValue);
		deck->AddCard(card);
	}
}

BasicDeck* BasicSnap::Player(const string& name)
{
	return m_players.find(name)->second;
}

size_t BasicSnap::CurrentNumberOfPlayers() const
{
	return m_players.size();
}

size_t BasicSnap::DiscardDeckSize() const
{
	return m_discardedCards->DeckSize();
}

bool BasicSnap::CallSnap(BasicDeck* player)
{
	unsigned int deckSize = m_discardedCards->DeckSize();
	if (deckSize < 2)
		return false;
	
	Card* topCard  = m_discardedCards->DrawCard(--deckSize);
	Card* nextCard = m_discardedCards->DrawCard(--deckSize);
	if (topCard->ViewCardValue() != nextCard->ViewCardValue())
		return false;

	size_t numberOfDiscards = m_discardedCards->DeckSize();
	while (numberOfDiscards > 0)
	{
		Card* card = m_discardedCards->DrawCard();
		if (player != nullptr)
			player->AddCard(card);
		m_discardedCards->RemoveCard(card);
		--numberOfDiscards;
	}
	return true;
}