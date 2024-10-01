/*
 * Exc9.c
 *
 *  Created on: Sep 25, 2024
 *      Author: MSIFPT
 */
#include "Exc9.h"

const int MAX_LED_MATRIX = 8;

uint8_t matrix_buffer [8] = {0x07, 0xF3, 0xF5, 0xF6, 0xF6, 0xF5, 0xF3, 0x07};
//uint8_t matrix_buffer[8] = {0x7F, 0xBF, 0x9F, 0xAF, 0x9F, 0xBF, 0x7F, 0xFF};

void updateLEDMatrix(int index) {
    switch (index) {
        case 0:
        	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, SET);
        	displayCol(0);
            break;
        case 1:
        	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, SET);
        	displayCol(1);
            break;
        case 2:
        	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, SET);
        	displayCol(2);
            break;
        case 3:
        	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, SET);
        	displayCol(3);
            break;
        case 4:
        	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, SET);
        	displayCol(4);
            break;
        case 5:
        	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, SET);
        	displayCol(5);
            break;
        case 6:
        	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, SET);
        	displayCol(6);
            break;
        case 7:
        	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, SET);
        	displayCol(7);
            break;
        default:
            break;
    }
}

void displayCol(int col) {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, (matrix_buffer[col] & 0x01));
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, (matrix_buffer[col] & 0x02));
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (matrix_buffer[col] & 0x04));
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, (matrix_buffer[col] & 0x08));
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (matrix_buffer[col] & 0x10));
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (matrix_buffer[col] & 0x20));
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, (matrix_buffer[col] & 0x40));
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, (matrix_buffer[col] & 0x80));
}
