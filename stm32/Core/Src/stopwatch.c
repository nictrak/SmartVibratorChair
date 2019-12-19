/*
 * stopwatch.c
 *
 *  Created on: Dec 17, 2019
 *      Author: NMSI
 */

#include "stopwatch.h"



v_error stopWatch_init(stopWatch *stopwatch, float maxCounter) {
	if (maxCounter <= 0) {
		return V_ERROR;
	} else {
		stopwatch->maxCounter = maxCounter;
		stopwatch->timeCounter = maxCounter;
		stopwatch->status = STOPWATCH_READY;
		return V_OK;
	}
}

v_error stopWatch_start(stopWatch *stopwatch) {

	if (stopwatch->status == STOPWATCH_READY) {
		stopwatch->status = STOPWATCH_RUN;
		return V_OK;
	} else {
		return V_ERROR;
	}

}

v_error stopWatch_setTime(stopWatch *stopwatch, float time) {

	if (stopwatch->status == STOPWATCH_READY) {
		stopwatch->maxCounter = time;
		stopwatch->timeCounter = time;
		return V_OK;
	} else {
		return V_ERROR;
	}

}

v_error stopWatch_pause(stopWatch *stopwatch) {

	if (stopwatch->status == STOPWATCH_RUN) {
		stopwatch->status = STOPWATCH_PAUSE;
		return V_OK;
	} else {
		return V_ERROR;
	}

}

v_error stopWatch_continue(stopWatch *stopwatch) {

	if (stopwatch->status == STOPWATCH_PAUSE) {
		stopwatch->status = STOPWATCH_RUN;
		return V_OK;
	} else {
		return V_ERROR;
	}

}

v_error stopWatch_timeout(stopWatch *stopwatch) {
	if (stopwatch->status == STOPWATCH_RUN) {
		stopwatch->status = STOPWATCH_TIMEOUT;
		return V_OK;
	} else {
		return V_ERROR;
	}
}

v_error stopWatch_halt(stopWatch *stopwatch) {

	if (stopwatch->status == STOPWATCH_RUN || stopwatch->status == STOPWATCH_PAUSE) {
		stopwatch->status = STOPWATCH_HALT;
		return V_OK;
	} else {
		return V_ERROR;
	}

}

v_error stopWatch_reset(stopWatch *stopwatch) {

	if (stopwatch->status == STOPWATCH_TIMEOUT || stopwatch->status == STOPWATCH_HALT) {
		stopwatch->timeCounter = stopwatch->maxCounter;
		stopwatch->status = STOPWATCH_READY;
		return V_OK;
	} else {
		return V_ERROR;
	}

}

v_error stopWatch_decrement(stopWatch *stopwatch, float timeUnit) {
	stopwatch->timeCounter -= timeUnit;
}
