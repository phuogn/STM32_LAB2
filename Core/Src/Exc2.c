/*
 * Exc1.c
 *
 *  Created on: Sep 23, 2024
 *      Author: MSIFPT
 */
#include "Exc2.h"

int LED = 1;
void Exc2_init() {
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG2_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, DOT_Pin, SET);
	LED = 1;
}

void Exc2_run() {
	if (LED == 1) {
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		display7SEG(1);
		LED = 2;
	}
	else if(LED == 2) {
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
		display7SEG(2);
		LED = 3;
	}
	else if (LED == 3) {
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
		display7SEG(3);
		LED = 4;
	}
	else {
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
		display7SEG(0);
		LED = 1;
	}
}

void display7SEG(int num) {
	// Mảng lưu giá trị các đoạn cho các số từ 0 đến 9
	    uint8_t segments[10] = {
	        0xC0, // 0 -> các đoạn a b c d e f (g tắt)
	        0xF9, // 1 -> các đoạn b c (a, d, e, f, g tắt)
	        0xA4, // 2 -> các đoạn a b d e g (c, f tắt)
	        0xB0, // 3 -> các đoạn a b c d g (e, f tắt)
	        0x99, // 4 -> các đoạn b c f g (a, d, e tắt)
	        0x92, // 5 -> các đoạn a c d f g (b, e tắt)
	        0x82, // 6 -> các đoạn a c d e f g (b tắt)
	        0xF8, // 7 -> các đoạn a b c (d, e, f, g tắt)
	        0x80, // 8 -> tất cả các đoạn a b c d e f g đều sáng
	        0x90  // 9 -> các đoạn a b c f g (d, e tắt)
	    };

	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (segments[num] & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (segments[num] & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (segments[num] & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (segments[num] & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (segments[num] & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (segments[num] & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (segments[num] & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void DOT_run() {
	HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
}
