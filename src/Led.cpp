/*
 * Led.cpp
 *
 *  Created on: 11.12.2015
 *      Author: rgdsouza
 */

#include "Led.h"

LED::LED(){
	CurrentState = S_OFF;
}

LED::~LED(){

}

LED::LED_FN_STATUS LED::On(void)
{
	LED_FN_STATUS ReturnValue = E_NOT_OK;

	switch(CurrentState)
	{
		// Transition from S_OFF -> S_ON
		case S_OFF:
			CurrentState = S_ON;
			ReturnValue = E_OK;
			break;

		// Transition from S_ON -> S_ON
		case S_ON:
			// Not valid transition, remain in S_ON, Return error
			break;

		// Transition from S_BLINK_1S to S_ON
		case S_BLINK_1S:
			CurrentState = S_ON;
			ReturnValue = E_OK;
			break;

		// Transition from S_BLINK_2S to S_ON
		case S_BLINK_2S:
			CurrentState = S_ON;
			ReturnValue = E_OK;
			break;
	}

	return ReturnValue;
}

LED::LED_FN_STATUS LED::Off(void)
{
	LED_FN_STATUS ReturnValue = E_NOT_OK;

	switch(CurrentState)
	{
		// Transition from S_OFF -> S_OFF
		case S_OFF:
			// Not valid transition, remain in S_OFF, Return error
			break;

		// Transition from S_ON -> S_OFF
		case S_ON:
			CurrentState = S_OFF;
			ReturnValue = E_OK;
			break;

		// Transition from S_BLINK_1S -> S_OFF
		case S_BLINK_1S:
			// Not valid transition, remain in current state, return error
			break;

		// Transition from S_BLINK_2S -> S_OFF
		case S_BLINK_2S:
			// Not valid transition, remain in current state, return error
			break;
	}

	return ReturnValue;
}

LED::LED_FN_STATUS LED::Blink(int NrOfSec)
{
	LED_FN_STATUS ReturnValue = E_NOT_OK;

	// Check if the argument passed is valid
	if( (NrOfSec > 0) && (NrOfSec < 3))
	{
		switch(CurrentState)
		{
			// Transition from S_OFF to one of the states S_BLINK_<x>S
			case S_OFF:
				// Not valid transition, return error
				break;

			case S_ON:
				if(NrOfSec == 1)
				{
					CurrentState = S_BLINK_1S;
					ReturnValue = E_OK;
				}
				else if(NrOfSec == 2)
				{
					CurrentState = S_BLINK_2S;
					ReturnValue = E_OK;
				}
				else
				{
					// Nothing to do
				}
				break;

			case S_BLINK_1S:
				if(NrOfSec == 1)
				{
					// Not a valid transition, return error
				}
				else if(NrOfSec == 2)
				{
					CurrentState = S_BLINK_2S;
					ReturnValue = E_OK;
				}
				else
				{
					//Nothing to do
				}
				break;

			case S_BLINK_2S:
				if(NrOfSec == 1)
				{
					CurrentState = S_BLINK_1S;
					ReturnValue = E_OK;
				}
				else if(NrOfSec == 2)
				{
					// Invalid transition, return error
				}
				else
				{
					//Nothing to do
				}
				break;
		}
	}
	else
	{
		// Invalid argument, return error
	}

	return ReturnValue;
}

LED::LED_STATE LED::GetCurrentState(void)
{
	return LED::CurrentState;
}

