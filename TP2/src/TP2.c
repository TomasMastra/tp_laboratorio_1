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

#define X 2000

#define EMPTY -1

#include "ArrayPassenger.h"
#include "Input.h"


int main(void) {

	setbuf(stdout, NULL);

	Passenger list[X];
	int len = X;
	int option;
	//int flag = 0;
	int error;
	int id = 10000;




	/*
	 *
	 * here we asked for an option, each option does something different, but in order to access some of them you need to enter the option 1
	 *
	 *
	 *
	 */




	 error = initPassengers(list,  len); //INICIALIZA TODOS LOS ISEMPTY EN -1 Y VALIDO QUE NO TENGA ERRORES

	 if(error == 0)
	 {
	 	    do
	 	    {

	 	    	getInt(&option, "-------------------------------------\n"
	 	    								 "1. ALTA\n"
	 	    								 "2. BAJA\n"
	 	    								 "3. MODIFICAR PASAJERO\n"
	 	    								 "4. SUB MENU\n"
	 	    								 "5. SALIR\n"
	 	    								 "-------------------------------------\n",
	 	    								 "Enter the option: "
	 	    								 "-------------------------------------\n"
											 "1. ALTA\n"
											 "2. BAJA\n"
											 "3. MODIFICAR PASAJERO\n"
											 "4. SUB MENU\n"
											 "5. SALIR\n"
	 	    								 "-------------------------------------\n"
	 	    								 "Invalid option, Enter the correct option: ", 1, 5);

	 	        switch(option)
	 	        {
	 	            case 1:


	 	            	 askPassengers(list,  len, id);
	 	            	 printf("id - %d\n",id);

	 	            	 id++;


	 	            		//flag = 1;

	 	            break;
	 	            case 2:

	 	            	removePassenger(list,  len,  id);



	 	            break;
	 	            case 3:
	 	            	modifyPassengers(list, len);



	 	            	break;
	 	            case 4:

	 	            	printSubMenu(list, len);
	 	            	//printPassengers(list, len);



	 	            break;


	 	        }
	 	    }while(option!=5);
	 }



	return EXIT_SUCCESS;
}
