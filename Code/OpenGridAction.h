#pragma once

#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
#include "CardOne.h"
#include "Card_2.h"
#include "Card_3.h"
#include "Card_4.h"
#include "Card_5.h"
#include "Card_6.h"
#include "Card_7.h"
#include "Card_8.h"
#include "Card_9.h"
#include "Card_10.h"
#include "Card_11.h"
#include "Card_12.h"


class OpenGridAction : public Action
{

	int gridNum;

public:

	OpenGridAction(ApplicationManager* pApp);


	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell


	virtual ~OpenGridAction(); // A Virtual Destructor




};
