#pragma once
#include "Card.h"
class Card_9_11 : public Card
{
	static Player* owner;
	static int fees;
	static int price;
public:
	Card_9_11(const CellPosition& pos); // A Constructor takes card position
};

