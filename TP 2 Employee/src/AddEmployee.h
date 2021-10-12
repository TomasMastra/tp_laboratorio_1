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



int getInt(int* entero, char* mensaje, char* mensajeError, int min, int max);
int getFloat(float* flotante, char* mensaje, char* mensajeError, float min, float max);
int getString(char* cadena, char* mensaje, char* mensajeError, int max);
int getChar(char* caracter, char* mensaje);


void modifyEmployee(Employee list[], int len);


void printEmployeesByLastNameAndSector(Employee list[], int len);

float averageSalary(Employee list[], int len);
void printAverage(Employee list[], int len);

void subMenu(Employee list[], int len);





#endif /* ADDEMPLOYEE_H_ */
