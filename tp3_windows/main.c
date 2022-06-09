#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Parser.h"
#include "Input.h"


//Mastrapasqua Tomas B
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).

     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

	int option;
	int id=-1;
	int flag;

	flag = 0;

	LinkedList* listaPasajeros = ll_newLinkedList();



	 do{

		 getInt(&option,  "**************************************\n"
		 								"MENU\n"
		 								"**************************************\n"
		 								"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
		 								"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
		 								"3. Alta de pasajero\n"
		 								"4. Modificar datos de pasajero\n"
		 								"5. Baja de pasajero\n"
		 								"6. Listar pasajeros\n"
		 								"7. Ordenar pasajeros\n"
		 								"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
		 								"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
		 								"10. Salir\n"
		 								"**************************************\n"
		 								"Ingrese una opcion: ",

		 								"**************************************\n"
		 								"MENU\n"
		 								"**************************************\n"
		 								"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
		 								"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
		 								"3. Alta de pasajero\n"
		 								"4. Modificar datos de pasajero\n"
		 								"5. Baja de pasajero\n"
		 								"6. Listar pasajeros\n"
		 								"7. Ordenar pasajeros\n"
		 								"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
		 								"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
		 								"10. Salir\n"
		 								"**************************************\n"
		 								"Opcion invalida, reingrese: ", 1, 10);

		 //Salir del programa usando la opcion 10, de la otra forma si los cargo en el archivo se van a borrar todos los pasajeros

		 switch(option)
		 {
		 case 1:
			 if(flag == 0)
			 {
			 controller_loadFromText("data.csv", listaPasajeros);
			 flag = 1;
			 }else
			 {
				 printf("Ya cargo los pasajeros\n");
			 }
		break;

		 case 2:
			 if(flag == 0)
			 {
			 controller_loadFromBinary("dataBinario.csv", listaPasajeros);
			 flag = 1;
			 }else
			 {
				 printf("Ya cargo los pasajeros\n");
			 }

			 break;

		 case 3:
			 if(flag == 1)
			 {
			 controller_addPassenger(listaPasajeros, id);
			 }else
			 {
				 printf("No cargo los pasajeros\n");
			 }
			 break;



		 case 4:

			 if(flag == 1)
			 {
			 controller_editPassenger(listaPasajeros);
			 }else
			 {
				 printf("No cargo los pasajeros\n");
			 }



		break;


		 case 5:
			 if(flag == 1)
			 {
			 controller_removePassenger(listaPasajeros);
			 }else
			 {
				 printf("No cargo los pasajeros\n");
			 }

			 break;

		 case 6:

			 if(flag == 1)
			 {
			 controller_ListPassenger(listaPasajeros);
			 }else
			 {
				 printf("No cargo los pasajeros\n");
			 }

			 break;

		 case 7:
			 if(flag == 1)
			 {
			 controller_sortPassenger(listaPasajeros);
			 }else
			 {
				 printf("No cargo los pasajeros\n");
			 }
			 break;

		 case 8:

			 if(flag == 1)
			 {
			 controller_saveAsText("data.csv", listaPasajeros);
			 }else
			 {
				 printf("No cargo los pasajeros\n");
			 }
			 break;


		 case 9:
			 if(flag == 1)
			 {
			 controller_saveAsBinary("dataBinario.csv", listaPasajeros);
			 }else
			 {
				 printf("No cargo los pasajeros\n");
			 }

			 break;
		 }

	 }while(option!=10);






    /*LinkedList* listaPasajeros = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;
        }
    }while(option != 10); */



    return 0;
}

