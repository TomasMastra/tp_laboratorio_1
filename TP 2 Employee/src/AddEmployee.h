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



int getInt(int* integer, char* message, char* messageError, int min, int max);//This function ask for a integer number like the sector
int getFloat(float* floating, char* message, char* messageError, float min, float max);//This function ask for a floating number
int getString(char* string, char* message, char* messageError, int max);//This function ask for a character string like a name, it validate numbers and simbols
int getChar(char* character, char* message);//This function ask for a character


void modifyEmployee(Employee list[], int len);//This function modifyes an EMPLOYEE


float averageSalary(Employee list[], int len);//This function calculate the average of salary
void printAverage(Employee list[], int len);//This function shows the EMPLOYES who are above average

void subMenu(Employee list[], int len);//This function shows a sub menu with other options

int validateLetters(char* string);//This function validate caps for getString

int putCaps(char* string);





#endif /* ADDEMPLOYEE_H_ */
