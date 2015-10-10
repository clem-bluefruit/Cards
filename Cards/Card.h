#ifndef CARD_DEFINED
#define CARD_DEFINED

#include <string>

class Card
{
public:
	virtual unsigned int ViewCardValue() = 0;
	virtual std::string ViewCardName() = 0;
	virtual void SetCardValue(int value) = 0;
	virtual void SetCardName(const std::string& name) = 0;
	virtual ~Card() {};
};

#endif