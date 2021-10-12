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
int initEmployees(Employee list[], int len);

int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);

int findEmployeeById(Employee list[], int len, int id);

int removeEmployee(Employee list[], int len, int id);

int sortEmployees(Employee list[], int len, int order);

void printEmployees(Employee list[], int len);


int askEmployee (Employee list[], int len);






#endif /* ARRAYEMPLOYEES_H_ */
