/*
 * Input.h
 *
 *  Created on: 6 jun. 2022
 *      Author: Tomas Mastra
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>   //MASTRAPASQUA TOMAS B
#include <string.h>
#include <stdlib.h>
#include <ctype.h>






int getInt(int* integer, char* message, char* messageError, int min, int max);


int getFloat(float* floating, char* message, char* messageError, int min, int max);


int getString(char* string, char* message, char* messageError, int max);


int getChar(char* character, char* message);


int tolowerString(char* string);


int validateLetters(char* string);

int validateInt(char* integer);




int getName(char *string, char *message, char *messageError, int max);




#endif /* INPUT_H_ */
