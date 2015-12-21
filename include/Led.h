/*
 * Led.h
 *
 *  Created on: 11.12.2015
 *      Author: rgdsouza
 */

#ifndef SRC_LED_H_
#define SRC_LED_H_


class LED
{
public:
	enum LED_STATE {S_OFF, S_ON, S_BLINK_1S, S_BLINK_2S};
	enum LED_FN_STATUS {E_OK, E_NOT_OK};

private:
	LED_STATE CurrentState;

public:
	LED();
	virtual ~LED();

	LED_FN_STATUS On(void);
	LED_FN_STATUS Off(void);
	LED_FN_STATUS Blink(int NrOfSec);
	LED_STATE GetCurrentState(void);
};

#endif /* SRC_LED_H_ */
