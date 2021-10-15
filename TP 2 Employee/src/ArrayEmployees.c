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








			list[i].isEmpty = 1;


			break;




		}



	}






	return index;
}

int askEmployee (Employee list[], int len, int id)
{


	char name[51];
	char lastName[51];
	float salary;
	int sector;

	int i;





	for(i=0;i<len;i++)
	{




	if(list[i].isEmpty == EMPTY)
	{






	getInt(&sector, "Ingrese el sector:\n"
							"1.Sector\n"
							"2.Sector\n"
							"3. Sector\n",
							"Error - Opcion incorrecta, Ingrese el sector:\n"
							"1.Sector\n"
							"2.Sector\n"
							"3.Sector\n", 1, 3);

				getString(name, "Ingrese el nombre: ", "ERROR, Solo 50 caracteres y letras, Ingrese el nombre: ", 51);

				getString(lastName, "Ingrese el apellido: ", "ERROR, Solo 50 caracteres y letras, ingrese el apellido: ", 51);

				getFloat(&salary, "Ingrese el salario (10000 - 120000):\n","Error - ERROR, Ingrese el salario (10000 - 120000) :\n", 10000, 120000);

				addEmployee( list,  len,  id,  name,  lastName,  salary,  sector);

				 break;
	}else
		if(i==999)
	{

		printf("No hay espacio\n");
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












	if(i!=EMPTY)
	{




		list[i].id = id;







		 getChar(&confirm, "Ingrese S para cargar el empleado: ");



		if(confirm ==  's' || confirm == 'S')
		{

		list[i].sector=sector;

		strcpy(list[i].name, name);

		strcpy(list[i].lastName, lastName);

		list[i].salary = salary;

		list[i].isEmpty = 1;




		printf("El empleado fue cargado\n");

	}else
	{
		list[i].isEmpty = EMPTY;



		printf("No se cargo el empleado\n");


	}














	}



	return 0;
}



int removeEmployee(Employee list[], int len, int id)
{

	int i;
	int ret = -1;
	int idDelete;



    printf("-------------------------------------\nID list: \n");

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty != EMPTY)
		{

			printf("%d \n", list[i].id);
		}
	}
    printf("-------------------------------------\n\n");





		        getInt(&idDelete, "Ingrese el ID para eliminar: ", "ERROR, Ingrese la ID para eliminar: ", 1000, 2000);

		        printf("la ID a eliminar es %d\n", idDelete);


		             i=0;
		            for(i=0;i<X;i++)
		            {

		                if(idDelete==list[i].id)
		                {
		                    list[i].isEmpty=EMPTY;




		                    printf("Empleado eliminado correctamente  %d  \n\n", list[i].id);

		                    ret = 1;
		                    break;
		                }
		            }




		return ret;

}

int sortEmployees(Employee list[], int len, int order)
{

	Employee auxEmployee;
	int i;
	int j;








	len = X;

	getInt(&order, "Ingrese el orden (0.desc - 1.asc)", "ERROR, Ingrese el orden (0.desc - 1.asc)", 0,1);







if(order==0)
{
	for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(list[i].isEmpty == 1 && list[j].isEmpty == 1)
				{
					if(list[i].sector > list[j].sector )
					{
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}else
	    				if((strcmp(list[i].lastName, list[j].lastName ) == 1))
	    				{
	    					auxEmployee = list[i];
	    					list[i] = list[j];
	    					list[j] = auxEmployee;
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
							auxEmployee = list[i];
							list[i] = list[j];
							list[j] = auxEmployee;
						}else
    	    				if((strcmp(list[i].lastName, list[j].lastName ) == 1))
    	    				{
    	    					auxEmployee = list[i];
    	    					list[i] = list[j];
    	    					list[j] = auxEmployee;
    	    				}
					}
				}
			}


}






	return 0;
}
int printEmployees(Employee list[], int len)
{


	int i;
	int ret = -1;

	printf("\nLista de empleados...\n\n"
			   "%-5s %-20s %-20s %-20s %-20s\n", "ID", "Apellido", "Tomas", "Sector", "Salario");

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty != EMPTY)
		{

			//printf("isEmpty es %d", list[i].isEmpty);
				printf("%-5d %-20s %-20s %-20d %-20.2f\n", list[i].id, list[i].lastName, list[i].name, list[i].sector, list[i].salary);

				ret = 1;

		}

	}

	return ret;
}





#endif /* ARRAYEMPLOYEES_C_ */
