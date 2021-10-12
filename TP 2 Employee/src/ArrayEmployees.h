/*
 * ArrayEmployees.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{

	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;


}Employee;

/*
 * these are the functions that perform different things
 *
 */
int initEmployees(Employee list[], int len);//This function initialize the array, it puts isEmpty in -1

int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);//this function gets the data passed by the askEmployee function

int findEmployeeById(Employee list[], int len, int id);//this function searches for a position in the index that has no EMPLOYEE

int removeEmployee(Employee list[], int len, int id);//This function remove an EMPLOYEE

int sortEmployees(Employee list[], int len, int order);//this function sort the array by sector and last name

void printEmployees(Employee list[], int len);//This function show all the EMPLOYEES


int askEmployee (Employee list[], int len);//This function asks for the data






#endif /* ARRAYEMPLOYEES_H_ */
