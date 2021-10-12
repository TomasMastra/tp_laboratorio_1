/*
 * AddEmployee.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef ADDEMPLOYEE_H_
#define ADDEMPLOYEE_H_


#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>



int getInt(int* integer, char* message, char* messageError, int min, int max);
int getFloat(float* floating, char* message, char* messageError, float min, float max);
int getString(char* string, char* message, char* messageError, int max);
int getChar(char* character, char* message);


void modifyEmployee(Employee list[], int len);


void printEmployeesByLastNameAndSector(Employee list[], int len);

float averageSalary(Employee list[], int len);
void printAverage(Employee list[], int len);

void subMenu(Employee list[], int len);

int validateLetters(char* string);





#endif /* ADDEMPLOYEE_H_ */
