/*
 * Input.h
 *
 *  Created on: 26 abr. 2022
 *      Author: Tomas Mastra
 */

#ifndef INPUT_H_
#define INPUT_H_

int getInt(int* integer, char* message, char* messageError, int min, int max);
int getFloat(float* floating, char* message, char* messageError, int min, int max);
int getString(char* string, char* message, char* messageError, int max);
int getChar(char* character, char* message);


int tolowerString(char* string);
int validateLetters(char *string);
int getName(char *string, char *message, char *messageError, int max);


#endif /* INPUT_H_ */
