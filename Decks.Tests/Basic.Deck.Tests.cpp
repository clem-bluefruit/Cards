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
	void MakeDeckOfInts(BasicDeck& deck, int numberOfCards)
	{
		for (int i = 0; i < numberOfCards; ++i)
		{
			Card* card = new BasicCard(i);
			deck.AddCard(card);
		}
	}
	void MakeDeckOfCustomCards(BasicDeck& deck, int numberOfCards, vector<const string>& cardNames)
	{
		for (int i = 0; i < numberOfCards; ++i)
		{
			Card* card = new BasicCard(i, cardNames.at(i));
			deck.AddCard(card);
		}
	}
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

TEST_F(BasicDeckTest, Initialised_deck_add_customised_card_value_view_card_value)
{
	Card* card = new BasicCard(1, "One");
	deck.AddCard(card);
	ASSERT_EQ(1, deck.CardValue(0));
}

TEST_F(BasicDeckTest, Initialise_a_deck_of_ten_int_numbered_cards)
{
	MakeDeckOfInts(deck, 10);
	ASSERT_EQ(10, deck.DeckSize());
	ASSERT_EQ(3, deck.CardValue(3));
}

TEST_F(BasicDeckTest, Initialise_a_deck_of_cards_custom_value_and_names)
{
	std::vector<const string> cardNames = { "Zero", "One", "Two", "Three", "Four" };
	MakeDeckOfCustomCards(deck, 5, cardNames);
	ASSERT_EQ(5, deck.DeckSize());
	ASSERT_EQ(4, deck.CardValue(4));
	ASSERT_EQ("Two", deck.CardName(2));
}

TEST_F(BasicDeckTest, Remove_card_from_deck_of_cards)
{
	MakeDeckOfInts(deck, 5);
	ASSERT_EQ(5, deck.DeckSize());
	Card* cardToRemove = deck.GetCard(4);
	deck.RemoveCard(cardToRemove);
	ASSERT_EQ(4, deck.DeckSize());
	ASSERT_EQ(3, deck.CardValue(3));
}