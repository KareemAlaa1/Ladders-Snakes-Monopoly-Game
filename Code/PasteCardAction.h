#pragma once

#include "Action.h"


class PasteCardAction : public Action
{
	// [Action Parameters]
	CellPosition cardPosition; //cell position of the card

	// Note: These parameters should be read in ReadActionParameters()

public:

	PasteCardAction ( ApplicationManager* pApp );


	virtual void ReadActionParameters ( ); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute ( ); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell


	virtual ~PasteCardAction ( ); // A Virtual Destructor



};

