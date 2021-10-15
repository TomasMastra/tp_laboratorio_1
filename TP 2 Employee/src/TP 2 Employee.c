/*
 ============================================================================
 Name        : TP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define X 1000

#define EMPTY -1

#include "ArrayEmployees.h"
#include "AddEmployee.h"


int main(void) {

	setbuf(stdout, NULL);
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	Employee list[X];
	int len = X;

	int option;

	int flag = 0;

	int id = 1000;




	/*
	 *
	 * here we asked for an option, each option does something different, but in order to access some of them you need to enter the option 1
	 *
	 *
	 *
	 */




	 initEmployees( list,  len); //INICIALIZA TODOS LOS ISEMPTY EN -1


	 	    do
	 	    {

	 	    	getInt(&option, "-------------------------------------\n"
	 	    								 "1. ALTA\n"
	 	    								 "2. BAJA\n"
	 	    								 "3. MODIFICAR empleado\n"
	 	    								 "4. SUB MENU\n"
	 	    								 "5. SALIR\n"
	 	    								 "-------------------------------------\n",
	 	    								 "Enter the option: "
	 	    								 "-------------------------------------\n"
											 "1. ALTA\n"
											 "2. BAJA\n"
											 "3. MODIFICAR empleado\n"
											 "4. SUB MENU\n"
											 "5. SALIR\n"
	 	    								 "-------------------------------------\n"
	 	    								 "Invalid option, Enter the correct option: ", 1, 5);

	 	        switch(option)
	 	        {
	 	            case 1:


	 	            		 askEmployee (list,  len, id);

	 	            		 id++;
	 	            		flag = 1;

	 	            break;
	 	            case 2:

	 	            	if(flag==1)
	 	            	{

	 	            		 removeEmployee(list, len,  X);


	 	            	}
	 	            	else
	 	            	{
	 	            		printf("No ingreso un empleado\n");


	 	            	}

	 	            break;
	 	            case 3:
	 	            	if(flag==1)
	 	            	{

	 	            	 modifyEmployee(list,  len);

	 	            	}else
	 	            	{

	 	            		printf("No ingreso un empleado\n");

	 	            	}



	 	            	break;
	 	            case 4:

	 	            	if(flag == 1)
	 	            	{

	 	            	 subMenu(list, len);

	 	            	}else
	 	            	{
	 	            		printf("No ingreso un empleado\n");

	 	            	}



	 	            break;


	 	        }
	 	    }while(option!=5);


	return EXIT_SUCCESS;
}
