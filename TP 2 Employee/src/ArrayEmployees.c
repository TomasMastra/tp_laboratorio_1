/*
 * ArrayEmployees.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef ARRAYEMPLOYEES_C_
#define ARRAYEMPLOYEES_C_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define EMPTY -1
#define OCCUPED 1;

#define X 1000

#include "ArrayEmployees.h"
#include "AddEmployee.h"



int initEmployees(Employee list[], int len) //INICIALIZA TODOS LOS ISEMPTY EN -1
{


	int i;




	    for(i=0; i<len ;i++)
	    {

	    list[i].isEmpty = EMPTY;

	    if(list[i].isEmpty == EMPTY)
	    {

    	//break;
	    }

	    }








	    return 0;
}



int findEmployeeById(Employee list[], int len, int id)
{

	int i;
	int index = EMPTY;
	id=0;

	for(i=0;i<len;i++)
	{




		if(list[i].isEmpty == EMPTY)
		{



			index = i;

			list[i].id= index + 1000;







			list[i].isEmpty = 1;


			break;




		}



	}






	return index;
}

int askEmployee (Employee list[], int len)
{


	int id=0;
	char name[51];
	char lastName[51];
	float salary;
	int sector;

	int i;





	for(i=0;i<len;i++)
	{
		id=1000+i;
		printf("%d", id);
	if(list[i].isEmpty == EMPTY)
	{




	getInt(&sector, "Enter the sector:\n"
							"1.Sector\n"
							"2.Sector\n"
							"3. Sector\n",
							"Error - invalid option. Enter the correct sector:\n"
							"1.Sector\n"
							"2.Sector\n"
							"3.Sector\n", 1, 3);

				getString(name, "Enter the name: ", "ERROR, only 50 characters and letters only, Enter the name: ", 51);

				getString(lastName, "Enter the last name: ", "ERROR, only 50 characters and letters only, Enter the last name: ", 51);

				getFloat(&salary, "Enter the salary (10000 - 120000):\n","Error - ERROR, Enter the sasary (10000 - 120000) :\n", 10000, 120000);

				addEmployee( list,  len,  id,  name,  lastName,  salary,  sector);

				 break;
	}else
		if(i==1000)
	{

		printf("There is no space, delete an employee\n");
		break;
	}
	}





	return 0;
}



int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector)
{

	int i;
	char confirm ='N';



	i= len;



	i =  findEmployeeById(list, len, X);



	list[i].id=id;

	printf("el id es %d", id);







	if(i!=EMPTY)
	{











		 getChar(&confirm, "Enter S to load employee: ");



		if(confirm ==  's' || confirm == 'S')
		{
			//list[i].id = id;

		list[i].sector=sector;

		strcpy(list[i].name, name);

		strcpy(list[i].lastName, lastName);

		list[i].salary = salary;



		printf("The employee was charged correctly\n");

	}else
	{
		list[i].isEmpty = EMPTY;



		printf("The employee wasn't charged\n");


	}














	}



	return 0;
}



int removeEmployee(Employee list[], int len, int id)
{

	int i;
	//int retorno;
	int idEliminar;
	//int index;


	printf("ID list:\n");

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty != EMPTY)
		{

			printf("%d \n", list[i].id);
		}
	}

		printf("enter the id you are going to remove");
		        scanf("%d", &idEliminar);


		             i=0;
		            for(i=0;i<X;i++)
		            {

		                if(idEliminar==list[i].id)
		                {
		                    list[i].isEmpty=EMPTY;

		    		        printf("The ID is  %d\n", idEliminar); //////////////////


		                    printf("Employee removed successfully  %d  \n\n", list[i].id);
		                    break;
		                }else
		                {


		                	printf("That ID doesn't exist\n");
		                }
		            }




		return 0;

}

int sortEmployees(Employee list[], int len, int order)
{

	Employee auxProducto;
	int i;
	int j;








	len = X;

	getInt(&order, "Enter the order (0.desc - 1.asc)", "ERROR, Enter the order (0.desc - 1.asc)", 0,1);







if(order==0)
{
	for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(list[i].isEmpty == 1 && list[j].isEmpty == 1)
				{
					if(list[i].sector > list[j].sector /*|| strcmp(list[i].lastName, list[j].lastName) == 1*/)
					{
						auxProducto = list[i];
						list[i] = list[j];
						list[j] = auxProducto;
					}
				}
			}
		}
} else
{

	for(i=0; i<len-1; i++)
			{
				for(j=i+1; j<len; j++)
				{
					if(list[i].isEmpty != EMPTY && list[j].isEmpty !=EMPTY)
					{
						if(list[j].sector > list[i].sector /*|| strcmp(list[i].lastName, list[j].lastName) == 1*/)
						{
							auxProducto = list[i];
							list[i] = list[j];
							list[j] = auxProducto;
						}
					}
				}
			}


}






	return 0;
}
void printEmployees(Employee list[], int len)
{


	int i;

	printf("\nShowing product list...\n\n"
			   "%-5s %-20s %-20s %-20s %-20s\n", "ID", "last name", "Name", "Sector", "Salary");

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty != EMPTY)
		{

			//printf("isEmpty es %d", list[i].isEmpty);
				printf("%-5d %-20s %-20s %-20d %-20.2f\n", list[i].id, list[i].lastName, list[i].name, list[i].sector, list[i].salary);

		}

	}
}





#endif /* ARRAYEMPLOYEES_C_ */
