#include "BasicSnap.h"
#include "BasicDeck.h"
#include <gtest\gtest.h>

using namespace ::testing;
using namespace ::std;

class BasicSnapGame : public ::testing::Test, public SnapGame
{
public:
	SnapGame game;
};

TEST_F(BasicSnapGame, Initialise_a_game_with_two_players)
{
	game.AddPlayer("One");
	game.AddPlayer("Two");
	ASSERT_EQ(2, game.HowManyPlayers());
}

TEST_F(BasicSnapGame, Initialise_a_player_with_10_card_deck)
{
	const string playerName = "Player";
	const int deckSize = 10;
	game.AddPlayer(playerName, deckSize);
	Deck* playerDeck = game.Player(playerName);
	ASSERT_EQ(10, playerDeck->DeckSize());
}

TEST_F(BasicSnapGame, Two_players_have_10_cards_A_player_loses_a_card_has_9_cards)
{
	const string playerOneName = "Player 1";
	const string playerTwoName = "Player 2";
	const int deckSize = 10;
	game.AddPlayer(playerOneName, deckSize);
	game.AddPlayer(playerTwoName, deckSize);
	Deck* playerOneDeck = game.Player(playerOneName);
	Deck* playerTwoDeck = game.Player(playerTwoName);
	Card* card = playerTwoDeck->DrawCard(9);
	playerTwoDeck->RemoveCard(card);
	ASSERT_EQ(10, playerOneDeck->DeckSize());
	ASSERT_EQ(9, playerTwoDeck->DeckSize());
}

TEST_F(BasicSnapGame, Two_player_game_one_player_adds_card_to_discard_pile_Discard_pile_size_is_1)
{
	const string playerOneName = "One";
	const string playerTwoName = "Two";
	const int deckSize = 10;
	game.AddPlayer(playerOneName, deckSize);
	game.AddPlayer(playerTwoName, deckSize);
	BasicDeck* playerOneDeck = game.Player(playerOneName);
	BasicDeck* playerTwoDeck = game.Player(playerTwoName);
	game.PlayerDrawCard(playerOneDeck);
	ASSERT_EQ(9, playerOneDeck->DeckSize());
	ASSERT_EQ(10, playerTwoDeck->DeckSize());
	ASSERT_EQ(1, game.DiscardDeckSize());
}

TEST_F(BasicSnapGame, Two_player_game_player_two_calls_Snap)
{
	const string playerOneName = "One";
	const string playerTwoName = "Two";
	const int deckSize = 10;
	game.AddPlayer(playerOneName, deckSize);
	game.AddPlayer(playerTwoName, deckSize);
	BasicDeck* playerOneDeck = game.Player(playerOneName);
	BasicDeck* playerTwoDeck = game.Player(playerTwoName);
	game.PlayerDrawCard(playerOneDeck);
	game.PlayerDrawCard(playerTwoDeck);
	ASSERT_EQ(true, game.CallSnap());
}
