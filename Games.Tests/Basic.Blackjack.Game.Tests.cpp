#include "Basic_Blackjack_Game.h"
#include "BasicDeck.h"
#include <gtest\gtest.h>

using namespace ::std;
using namespace ::testing;

class BasicBlackjackGame : public BlackjackGame, public ::testing::Test
{
public:
	BlackjackGame game;
};

TEST_F(BasicBlackjackGame, Initiate_game_with_two_players_gives_three_players_including_Dealer)
{
	game.AddPlayer("One");
	game.AddPlayer("Two");
	ASSERT_EQ(3, game.CurrentNumberOfPlayers());
}

TEST_F(BasicBlackjackGame, Initialised_game_has_a_full_house_deck_of_52_cards)
{
	ASSERT_EQ(52, game.RemainingCards());
}

//TEST_F(BasicBlackjackGame, Initialise_game_with_two_players_players_and_dealer_have_2_cards_each)
//{
//
//}
