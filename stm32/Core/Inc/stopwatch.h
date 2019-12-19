/*
 * stopwatch.h
 *
 *  Created on: Dec 17, 2019
 *      Author: NMSI
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <stdint.h>

#define STOPWATCH_READY 	0
#define STOPWATCH_RUN 		1
#define STOPWATCH_TIMEOUT 	2
#define STOPWATCH_PAUSE 	3
#define STOPWATCH_HALT		4

#define UART_NO_RETURN  	0
#define UART_RETURN  		1

#define V_ERROR 			0
#define V_OK 				1

typedef uint8_t v_error;
typedef uint8_t modeT;
typedef int stopWatchStatus;

typedef struct stopWatchStruct {

	stopWatchStatus status;
	float timeCounter;
	float maxCounter;

} stopWatch;

v_error stopWatch_init(stopWatch *stopwatch, float maxCounter);

v_error stopWatch_start(stopWatch *stopwatch);

v_error stopWatch_setTime(stopWatch *stopwatch, float time);

v_error stopWatch_pause(stopWatch *stopwatch);

v_error stopWatch_continue(stopWatch *stopwatch);

v_error stopWatch_timeout(stopWatch * stopwatch);

v_error stopWatch_halt(stopWatch *stopwatch);

v_error stopWatch_reset(stopWatch *stopwatch);

v_error stopWatch_decrement(stopWatch *stopwatch, float timeUnit);

#endif /* STOPWATCH_H_ */
