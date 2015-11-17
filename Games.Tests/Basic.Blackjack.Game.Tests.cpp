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