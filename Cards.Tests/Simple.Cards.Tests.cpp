#include <gtest\gtest.h>
#include "BasicCard.h"

using namespace ::testing;
using namespace ::std;

class BasicCards : public ::testing::Test, public BasicCard
{
public:
	BasicCard card;
};

TEST_F(BasicCards, Default_Value_of_initialised_card_is_0)
{
	ASSERT_EQ(0, card.ViewCardValue());
}

TEST_F(BasicCards, Default_name_of_initialised_card_is_blank)
{
	ASSERT_EQ("", card.ViewCardName());
}

TEST_F(BasicCards, Set_value_of_initialised_card)
{
	card.SetCardValue(3);
	ASSERT_EQ(3, card.ViewCardValue());
}

TEST_F(BasicCards, Set_name_of_initialised_card)
{
	card.SetCardName("One");
	ASSERT_EQ("One", card.ViewCardName());
}

TEST_F(BasicCards, Initialise_card_with_custom_value_no_name)
{
	BasicCard card(5);
	ASSERT_EQ(5, card.ViewCardValue());
	ASSERT_EQ("", card.ViewCardName());
}

TEST_F(BasicCards, Initialise_card_with_custom_value_then_set_card_name)
{
	BasicCard card(7);
	card.SetCardName("Seven");
	ASSERT_EQ(7, card.ViewCardValue());
	ASSERT_EQ("Seven", card.ViewCardName());
}

TEST_F(BasicCards, Initialised_card_with_custom_value_update_value_and_name)
{
	BasicCard card(4);
	card.SetCardName("Eight");
	card.SetCardValue(8);
	ASSERT_EQ(8, card.ViewCardValue());
	ASSERT_EQ("Eight", card.ViewCardName());
}

TEST_F(BasicCards, Initialised_card_with_custom_name_has_value_of_0)
{
	BasicCard card("Ace");
	ASSERT_EQ(0, card.ViewCardValue());
	ASSERT_EQ("Ace", card.ViewCardName());
}

TEST_F(BasicCards, Initialised_card_with_custom_name_updates_name_and_value)
{
	BasicCard card("Joker");
	card.SetCardValue(13);
	card.SetCardName("King");
	ASSERT_EQ(13, card.ViewCardValue());
	ASSERT_EQ("King", card.ViewCardName());
}

TEST_F(BasicCards, Initialised_card_with_custom_value_and_custom_name)
{
	BasicCard card(4, "Four");
	ASSERT_EQ(4, card.ViewCardValue());
	ASSERT_EQ("Four", card.ViewCardName());
}

TEST_F(BasicCards, Initialised_card_with_custom_value_and_custom_name_update_value_and_name)
{
	BasicCard card(15, "Fifteen");
	card.SetCardValue(72);
	ASSERT_EQ(72, card.ViewCardValue());
	card.SetCardName("SeventyTwo");
	ASSERT_EQ("SeventyTwo", card.ViewCardName());
}