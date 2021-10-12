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

#define OCCUPED 1
#define EMPTY -1
#define x 1000

#include "ArrayEmployees.h"
#include "AddEmployee.h"




int getInt(int* integer, char* message, char* messageError, int min, int max)
{
	int ret = -1;
	int number;

	if(integer != NULL && message != NULL && messageError != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &number);

		while(number < min || number > max)
		{
			printf("%s", messageError);
			fflush(stdin);
			scanf("%d", &number);
		}

		*integer = number;
		ret = 0;
	}

	return ret;
}

int getFloat(float* floating, char* message, char* messageError, float min, float max)
{

	int ret = -1;
	float number;

		if(floating != NULL && message != NULL && messageError != NULL && min < max)
		{
			printf("%s", message);
			fflush(stdin);
			scanf("%f", &number);

			while(number < min || number > max)
			{
				printf("%s", messageError);
				fflush(stdin);
				scanf("%f", &number);
			}

			*floating = number;
			ret = 0;
		}

		return ret;

}

int getString(char* string, char* message, char* messageError, int max)
{
	int ret = -1;
	char buffer[256];
	int len;

	int i;

	if(string != NULL && message != NULL && messageError != NULL && max > 0)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		len = strlen(buffer);
		//tolower(buffer);



		printf("%s\n", buffer);
		for(i=0;i<len;i++)
		{



			//while((!(buffer[i]>'a' && buffer[i]<'z')) || (!(buffer[i]>'A' && buffer[i]<'Z')))
			while(len>max || validateLetters(buffer)==0)
			{
				//while(!(buffer[i]>96 && buffer[i]<123))


						//if(len>max)
						{
							printf("%s", messageError);
							fflush(stdin);
							//__fpurge(stdin);
							scanf("%[^\n]", buffer);
							len = strlen(buffer);
							//tolower(buffer);

						}

			}
		}

		//string = tolower(buffer);

		strcpy(string, buffer);



		ret = 0;
	}



	return ret;
}

int getChar(char* character, char* message)
{
	int ret = -1;

	if(character != NULL && message != NULL)
	{
		printf("%s", message);
		fflush(stdin);
		//__fpurge(stdin);

		*character = getchar();
		ret = 0;
	}

	return ret;
}

int validateLetters(char *string)
{

	//int i;
	int ret = -1;
	int len;
	char validateCaps[256];

	len = strlen(string);

	//tolower(string);


	for(int i=0;i<len;i++)
	{

		validateCaps[i] = tolower(string[i]);

		if(validateCaps[i] < 97 || validateCaps[i] > 122)
		{
			ret = 0;

		}

	}





	return ret;

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
