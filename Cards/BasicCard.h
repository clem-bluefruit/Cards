#ifndef BASIC_CARD_DEFINED
#define BASIC_CARD_DEFINED

#include "Card.h"
#include <string>

class BasicCard : public Card
{
public:
	BasicCard();
	BasicCard(int value);
	BasicCard(const std::string& name);
	BasicCard(int value, const std::string& name);
	unsigned int ViewCardValue();
	std::string ViewCardName();
	void SetCardValue(int value);
	void SetCardName(const std::string& name);
private:
	unsigned int m_cardValue = 0;
	std::string m_cardName = "";
};

#endif