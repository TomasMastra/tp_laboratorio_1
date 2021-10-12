/*
 * AddEmployee.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef ADDEMPLOYEE_C_
#define ADDEMPLOYEE_C_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define OCCUPED 1
#define EMPTY -1
#define x 5

#include "ArrayEmployees.h"
#include "AddEmployee.h"




int getInt(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

int getFloat(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{

	int retorno = -1;
		float numeroIngresado;

		if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &numeroIngresado);

			while(numeroIngresado < min || numeroIngresado > max)
			{
				printf("%s", mensajeError);
				fflush(stdin);
				scanf("%f", &numeroIngresado);
			}

			*flotante = numeroIngresado;
			retorno = 0;
		}

		return retorno;

}

int getString(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int retorno = -1;
	char buffer[256];
	int len;

	int i;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		len = strlen(buffer);

		for(i=0;i<len;i++)
		{
		while(!(buffer[i]>64 && buffer[i]<91 || buffer[i]>96 && buffer[i]<123) || len > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			//__fpurge(stdin);
			scanf("%[^\n]", buffer);
			len = strlen(buffer);
		}
		}

		strcpy(cadena, buffer);
		retorno = 0;
	}

	return retorno;
}

int getChar(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		//__fpurge(stdin);

		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}




void modifyEmployee(Employee list[], int len)
{


	int i;
	int idAsk;

	int optionModify;



    printf("-----------------------------------------\n\n");

	for(i=0;i<len;i++)
	{
		        if(list[i].isEmpty!=EMPTY)
		        {

		            printf("%d\n", list[i].id);



		        }
	}
		        printf("-----------------------------------------\n\n");


		    printf("Que id quieres modificar?");
		    scanf("%d", &idAsk);

		    getInt(&optionModify, "Enter the option to modify\n 1.name\n2.last Name\n3,sector\n4.salary", "ERROR, Enter the option to modify\n 1.name\n2.last Name\n3,sector\n4.salary", 1, 4);








		    for(i=0;i<len;i++)
		    {

		        if(idAsk==list[i].id)
		        {


		        	switch(optionModify)
		        	{

		        	case 1:
		        		getString(list[i].name, "Enter the name", "ERROR, enter the name", 51);
		        	break;
		        	case 2:
		        		getString(list[i].lastName, "enter the  last name", "ERROR, enter the last name", 51);

		        	break;
		        	case 3:
		        		getInt(&list[i].sector, "Enter the new sector", "ERROR, Enter the new sector", 1, 3);

		        	break;
		        	case 4:
		        		getFloat(&list[i].salary, "Enter the new salary", "ERROR, Enter the new salary", 10000, 120000);
		        	break;





		        	}




		        }

		    }




}

float averageSalary(Employee list[], int len)
{

	int i;
	int average;
	int sum=0;

	int amount;

	amount=0;

	for(i=0;i<len;i++)
	{

		if(list[i].isEmpty!=EMPTY)
		{

			amount++;
			sum = sum + list[i].salary;

		}

	}



	average = sum / amount;

	printf("-------------------------------------\n");

	printf("The sum of the SALARY is %d\n", sum);
	printf("The average SALARY is %d\n", average);


	return average;
}
void printAverage(Employee list[], int len)
{


	float moreAverage;
	int i;


	moreAverage= averageSalary(list, len);

	printf("\nEmployees who are above average:\n\n"
				   "%-5s %-20s %-20s %-20s %-20s\n", "ID", "last name", "Name", "Sector", "Salary");
	for(i=0;i<len;i++)
	{

		if(list[i].salary>moreAverage)
		{
			if(list[i].isEmpty!=EMPTY)
			{

			printf("%-5d %-20s %-20s %-20d %-20.2f\n", list[i].id, list[i].lastName, list[i].name, list[i].sector, list[i].salary);
			}

		}

	}
	//printf("-------------------------------------\n");

}

void subMenu(Employee list[], int len)
{

	int option;



	do{
		getInt(&option, "-------------------------------------\n"
				 "1. Show all employees sorted by sector and last name\n"
				 "2. Total, average salaries and how many employees are above the average salary\n"
				 "3. EXIT\n"
				 "-------------------------------------\n",
				 "-------------------------------------\n"
				 "1. Show all employees sorted by sector and last name\n"
				 "2. Total, average salaries and how many employees are above the average salary\n"
				 "3. EXIT\n"
				 "-------------------------------------\n",1,3);


		switch(option)
		{

		case 1:
			 sortEmployees(list,  len,  5);

			 printEmployees(list,  len);

			break;



		case 2:

			 printAverage(list,  len);



			break;

		}



	}while(option>2);


}



#endif /* ADDEMPLOYEE_C_ */
