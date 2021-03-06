#include "BasicCard.h"

using namespace ::std;

BasicCard::BasicCard()
{
}

BasicCard::BasicCard(int value) :
m_cardValue(value)
{
}

BasicCard::BasicCard(const string& name) :
m_cardName(name)
{
}

BasicCard::BasicCard(int value, const string& name) :
m_cardValue(value),
m_cardName(name)
{
}

unsigned int BasicCard::ViewCardValue()
{
	return m_cardValue;
}

string BasicCard::ViewCardName()
{
	return m_cardName;
}

void BasicCard::SetCardValue(int value)
{
	m_cardValue = value;
}

void BasicCard::SetCardName(const string& name)
{
	m_cardName = name;
}