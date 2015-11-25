#ifndef PLAYING_CARDS_DEFINED
#define PLAYING_CARDS_DEFINED

typedef unsigned int uint;

#include <string>

namespace PlayingCards
{
	struct BlackJackCards
	{
		enum Value
		{
			ACE = 1,
			TWO,
			THREE,
			FOUR,
			FIVE,
			SIX,
			SEVEN,
			EIGHT,
			NINE,
			TEN,
			JACK,
			QUEEN,
			KING
		};

		enum Suite
		{
			SPADES,
			HEARTS,
			DIAMONDS,
			CLUBS
		};

		static const std::string CardName(BlackJackCards::Value card)
		{
			switch (card)
			{
			case ACE:
				return "Ace";
			case TWO:
				return "2";
			case THREE:
				return "3";
			case FOUR:
				return "4";
			case FIVE:
				return "5";
			case SIX:
				return "6";
			case SEVEN:
				return "7";
			case EIGHT:
				return "8";
			case NINE:
				return "9";
			case TEN:
				return "10";
			case JACK:
				return "Jack";
			case QUEEN:
				return "Queen";
			case KING:
				return "King";
			default:
				return "Joker";
			}
		}

		static const std::string CardSuite(BlackJackCards::Suite suite)
		{
			switch (suite)
			{
			case SPADES:
				return "Spades";
			case HEARTS:
				return "Hearts";
			case DIAMONDS:
				return "Diamonds";
			case CLUBS:
				return "Clubs";
			default:
				return "Invalid";
			}
		}
	};
}

#endif