/*
 * timer.c
 *
 *  Created on: Sep 23, 2024
 *      Author: MSIFPT
 */
#include "timer.h"

int timer_flag[5];
int timer_counter[5];
void setTimer(int index, int duration) {
	timer_flag[index] = 0;
	timer_counter[index] = duration/10;
}

void timer_run() {
	for (int i = 0; i < 5; i++) {
		if (timer_counter[i] > 0) {
			timer_counter[i]--;
			if (timer_counter[i] <= 0)
				timer_flag[i] = 1;
		}
	}
}
