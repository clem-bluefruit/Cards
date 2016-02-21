#include "Basic_Blackjack_Game.h"
#include "BasicDeck.h"
#include <gtest\gtest.h>

using namespace ::std;
using namespace ::testing;

class BasicBlackjackGame : public BlackjackGame, public ::testing::Test
{
public:
	BlackjackGame game;
	void SetupTwoPlayerGame(string nameOne = "One", string nameTwo = "Two")
	{
		game.AddPlayer(nameOne);
		game.AddPlayer(nameTwo);
	}
};

TEST_F(BasicBlackjackGame, Initiate_game_with_two_players_gives_three_players_including_Dealer)
{
	game.AddPlayer("One");
	game.AddPlayer("Two");
	ASSERT_EQ(3, game.CurrentNumberOfPlayers());
}

TEST_F(BasicBlackjackGame, Helper_function_in_test_framework_to_create_two_players_gives_THREE_players)
{
	SetupTwoPlayerGame();
	ASSERT_EQ(3, game.CurrentNumberOfPlayers());
}

TEST_F(BasicBlackjackGame, Initialised_game_has_a_full_house_deck_of_52_cards)
{
	ASSERT_EQ(52, game.RemainingCards());
}

TEST_F(BasicBlackjackGame, Initialise_game_with_two_players_Players_and_dealer_have_2_cards_each_house_deck_has_46_cards_left)
{
	SetupTwoPlayerGame();
	const uint expectedHandSize = 2;
	for (size_t i = 0; i < expectedHandSize; i++)
	{
		game.DealCard("One");
		game.DealCard("Two");
		game.DealCard("Dealer");
	}
	ASSERT_EQ(expectedHandSize, game.PlayerHandSize(game.Player("One")));
	ASSERT_EQ(46, game.RemainingCards());
}

TEST_F(BasicBlackjackGame, Initialised_game_with_unshuffled_deck_player_One_and_Twos_card_totals_are_20_and_12)
{
	SetupTwoPlayerGame();
	const uint expectedHandSize = 2;
	for (size_t i = 0; i < expectedHandSize; i++)
	{
		game.DealCard("One");
		game.DealCard("Two");
		game.DealCard("Dealer");
	}
	ASSERT_EQ(20, game.HandValue(game.Player("One"))) << "Error: Player One hand value should be 20";
	ASSERT_EQ(12, game.HandValue(game.Player("Two"))) << "Error: Player Two hand value should be 12";
}

TEST_F(BasicBlackjackGame, Initialised_game_with_unshuffled_deck_Dealer_has_first_card_face_down_hand_value_is_2)
{
	SetupTwoPlayerGame();
	const uint expectedHandSize = 2;
	for (size_t i = 0; i < expectedHandSize; i++)
	{
		game.DealCard("One");
		game.DealCard("Two");
		game.DealCard("Dealer");
	}
	
	ASSERT_EQ(2, game.HandValue(game.Player("Dealer")));
}
