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

#define X 5

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





	// initEmployees( list,  len); //INICIALIZA TODOS LOS ISEMPTY EN -1






	 	    do
	 	    {

	 	    	getInt(&option, "-------------------------------------\n"
	 	    								 "1. Enter an employee\n"
	 	    								 "2. Delete an employee\n"
	 	    								 "3. Modify an employee\n"
	 	    								 "4. SUB MENU\n"
	 	    								 "5. EXIT\n"
	 	    								 "-------------------------------------\n",
	 	    								 "Enter the option: "
	 	    								 "-------------------------------------\n"
											 "1. Enter an employee\n"
											 "2. Delete an employee\n"
											 "3. Modify an employee\n"
											 "4. SUB MENU\n"
											 "5. EXIT\n"
	 	    								 "-------------------------------------\n"
	 	    								 "Invalid option, Enter the correct option: ", 1, 5);

	 	        switch(option)
	 	        {
	 	            case 1:
	 	            	if(flag==0)
	 	            	{


	 	            		 initEmployees( list,  len); //INICIALIZA TODOS LOS ISEMPTY EN -1

	 	            		 printf("kkkkkkkkkk");



	 	            		 askEmployee (list,  len);






	 	            		flag = 1;
	 	            	}else
	 	            	{


	 	            		 askEmployee (list,  len);








	 	            	}




	 	            break;
	 	            case 2:

	 	            	if(flag==1)
	 	            	{

	 	            		 removeEmployee(list, len,  X);


	 	            	}
	 	            	else
	 	            	{


	 	            	}

	 	            break;
	 	            case 3:
	 	            	if(flag==1)
	 	            	{

	 	            	 modifyEmployee(list,  len);

	 	            	}



	 	            	break;
	 	            case 4:

	 	            	if(flag == 1)
	 	            	{

	 	            	 subMenu(list, len);

	 	            	}



	 	            break;


	 	        }
	 	    }while(option!=5);


	return EXIT_SUCCESS;
}
