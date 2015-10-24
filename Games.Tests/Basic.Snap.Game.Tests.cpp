#include "BasicSnap.h"
#include "BasicDeck.h"
#include <gtest\gtest.h>

using namespace ::testing;
using namespace ::std;

TEST(BasicSnapGame, Initialise_a_game_with_two_players)
{
	SnapGame game;
	game.AddPlayer("One");
	game.AddPlayer("Two");
	ASSERT_EQ(2, game.HowManyPlayers());
}

TEST(BasicSnapGame, Initialise_a_player_with_10_card_deck)
{
	SnapGame game;
	game.AddPlayer("Player", 10);
	Deck* playerDeck = game.Player("Player");
	ASSERT_EQ(10, playerDeck->DeckSize());
}

TEST(BasicSnapGame, Two_players_have_10_cards_A_player_loses_a_card_has_9_cards)
{
	SnapGame game;
	game.AddPlayer("Player 1", 10);
	game.AddPlayer("Player 2", 10);
	Deck* playerOneDeck = game.Player("Player 1");
	Deck* playerTwoDeck = game.Player("Player 2");
	Card* card = playerTwoDeck->GetCard(9);
	playerTwoDeck->RemoveCard(card);
	ASSERT_EQ(10, playerOneDeck->DeckSize());
	ASSERT_EQ(9, playerTwoDeck->DeckSize());
}