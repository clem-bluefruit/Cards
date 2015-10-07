#include "BasicCard.h"
#include "BasicDeck.h"
#include <gtest\gtest.h>

using namespace ::testing;
using namespace ::std;

class BasicDeckTest : 
	public ::testing::Test,
	public BasicCard,
	public BasicDeck
{
public:
	BasicDeck deck;
};

TEST_F(BasicDeckTest, Initialise_an_empty_deck_returns_size_0)
{
	ASSERT_EQ(0, deck.DeckSize());
}

TEST_F(BasicDeckTest, Initialise_empty_deck_add_single_card_size_1)
{
	Card* card = new BasicCard(2, "Two");
	deck.AddCard(card);
	ASSERT_EQ(1, deck.DeckSize());
}

TEST_F(BasicDeckTest, Initialised_deck_add_customised_card_name_view_card_name)
{
	Card* card = new BasicCard(3, "Three");
	deck.AddCard(card);
	ASSERT_EQ("Three", deck.CardName(0));
}