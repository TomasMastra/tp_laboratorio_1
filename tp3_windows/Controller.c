#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Input.h"
#include "Parser.h"
#include "Controller.h"


//Mastrapasqua Tomas B


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;

	pFile = fopen(path, "r");

		if(path!=NULL && pArrayListPassenger!=NULL)
		{
			if(pFile!=NULL)
			{
			parser_PassengerFromText(pFile, pArrayListPassenger);
			fclose(pFile);
			pFile = NULL;
			}else
			{
				printf("No se encontro el archivo\n");
			}
		}


    return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;

	pFile = fopen(path, "rb");

			if(path!=NULL && pArrayListPassenger!=NULL)
			{
				if(pFile!=NULL)
				{
				parser_PassengerFromBinary(pFile, pArrayListPassenger);
				fclose(pFile);
				pFile = NULL;
				}else
				{
					printf("No se encontro el archivo\n");
				}
			}




    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int id)
{

		float precio;

		char idStr[22];
		char nombre[20];
		char apellido[20];
		char tipo[20];
		char codigo[20];
		char precioStr[20];
		char estado[20];
	Passenger* unPasajero;
	unPasajero = Passenger_new();



	if(pArrayListPassenger!=NULL)
	{
		id = (Passenger_GetLastId(pArrayListPassenger)+1);


		getName(nombre, "Ingrese el nombre: ", "ERROR, Ingrese el nombre (Solo letras): ", 50);
		getName(apellido, "Ingrese el apellido: ", "ERROR, Ingrese el apellido (Solo letras): ", 50);
		getFloat(&precio, "Ingrese el precio: ", "ERROR, Ingrese el precio (10.000-100.000)", 10000, 100000);

	 getName(tipo,
															"\n***************************\n"
															"TIPO DE PASAJERO\n"
															"\n***************************\n"
															"1. FirstClass\n"
															"2. ExecutiveClass\n"
															"3. EconomyClass\n"
															"Ingrese una opcion: " ,
															"\n***************************\n"
															"TIPO DE PASAJERO\n"
															"\n***************************\n"
															"1. FirstClass\n"
												   		    "2. ExecutiveClass\n"
															"3. EconomyClass\n"
															"Error, Ingrese de vuelta: " , 21);
		getString(codigo,
															 "\n***************************\n"
															 "CODIGO DE VUELO\n"
															 "\n***************************\n"
															 "1. BA2491A\n"
															 "2. IB0800A\n"
															 "3. MM0987B\n"
															 "4. TU6789B\n"
															 "5. GU2345F\n"
															 "6. HY4567D\n"
															 "7. FR5678G\n"
															 "8. BR3456J\n"
															 "9. AB7650G\n"
															 "10.KV7591L\n"
															 "Ingrese una opcion: " ,
															 "\n***************************\n"
															 "CODIGO DE VUELO\n"
															 "\n***************************\n"
															 "1. BA2491A\n"
															 "2. IB0800A\n"
															 "3. MM0987B\n"
															 "4. TU6789B\n"
															 "5. GU2345F\n"
															 "6. HY4567D\n"
															 "7. FR5678G\n"
															 "8. BR3456J\n"
															 "9. AB7650G\n"
															 "10.KV7591L\n"
															 "Error, Ingrese de vuelta: " , 21);

		getString(estado,
															 "\n***************************\n"
															 "ESTADO DE VUELO\n"
															 "\n***************************\n"
															 "1. En Horario\n"
															 "2. Aterrizo\n"
															 "3. En Vuelo\n"
															 "4. Demorado\n"
															 "Ingrese una opcion: " ,
															 "\n***************************\n"
															 "ESTADO DE VUELO\n"
															 "\n***************************\n"
															 "1. En Horario\n"
															 "2. Aterrizo\n"
															 "3. En Vuelo\n"
															 "4. Demorado\n"
															 "Error, Ingrese de vuelta: " , 21);


		printf("Codigo %s - Tipo %s", codigo, tipo);
		itoa(id, idStr, 10);
		itoa(precio, precioStr, 10);
		unPasajero = Passenger_newParametros(idStr, nombre, apellido, precioStr, codigo, tipo, estado);

		Passenger_printOne(unPasajero);


		ll_add(pArrayListPassenger,unPasajero);
	}

    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int id;
	int index = -1;
	int len;
	//int option;
	Passenger* unPasajero;


	   if(pArrayListPassenger!=NULL)
	   {
		   controller_ListPassenger(pArrayListPassenger);

		   getInt(&id, "Ingrese el ID del pasajero para modificar: ", "ERROR, Ingrese el ID del pasajero para modificar: ",1, 20000);
			len=ll_len(pArrayListPassenger);

		   for(int i=0;i<len;i++)
		   {
				unPasajero=(Passenger*)ll_get(pArrayListPassenger, i);

				//if(Passenger_getId(unPasajero, &id)==1)
					{
						if(unPasajero->id == id)
						{
							index = i;
							break;


						}
					}

		   }

	   }

	   if(index!=-1)
	   {
		   Passenger_SubMenuModify(unPasajero);
	   }else
	   {
		   printf("No se encontro el ID %d\n", id);
	   }


    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
   int id;
   int index = -1;
   int len;
   Passenger* unPasajero;


   if(pArrayListPassenger!=NULL)
   {
	   controller_ListPassenger(pArrayListPassenger);

	   getInt(&id, "Ingrese el ID del pasajero para eliminar: ", "ERROR, Ingrese el ID del pasajero para eliminar: ",1, 20000);
		len=ll_len(pArrayListPassenger);

	   for(int i=0;i<len;i++)
	   {
			unPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
			if(unPasajero->id == id)
			{
				index = i;
			}

	   }

	   if(index!=-1)
	   {
		   ll_remove(pArrayListPassenger, index);//Preguntar si quiere eliminarlo
		   unPasajero = NULL;
		   printf("Se elimo el pasajero de ID %d\n", id);
	   }else
	   {
		   printf("No se encontro el ID %d\n", id);
	   }
   }

	return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{

	//int ret=1;
		Passenger* listaPasajeros=NULL;
		int len;
		if(pArrayListPassenger != NULL)
		{
			len = ll_len(pArrayListPassenger);
			//printf("%d\n", len);
			printf("\n%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","APELLIDO","PRECIO");
			for(int i=0;i<len;i++)
			{
				listaPasajeros=ll_get(pArrayListPassenger, i);


		 	 	 Passenger_printOne(listaPasajeros);
					//printf("%4d %10s %10s %4.2f %10s %10s %10s\n", listaPasajeros->id, listaPasajeros->nombre, listaPasajeros->apellido, listaPasajeros->precio, listaPasajeros->tipoPasajero, listaPasajeros->codigoVuelo, listaPasajeros->estadoVuelo);



			}
			//ret=0;
		}


	return 1;

}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int option;

		if(pArrayListPassenger!=NULL)
		{
			getInt(&option,
													 "\n***************************\n"
													 "ORDENAR\n"
													 "\n***************************\n"
													 "1. Nombre ascendente\n"
													 "2. Nombre descendente\n"
													 "3. Apellido ascendente\n"
													 "4. Apellido descendente\n"
													 "5. Precio descendente\n"
													 "6. Precio ascendente\n"
													 "7. Codigo de Vuelo ascendente\n"
													 "8. Codigo de Vuelo descendente\n"
													 "9. Tipo de Pasajero ascendente\n"
													 "10.Tipo de Pasajero descendente\n"
													 "11.Estado de Vuelo\n"
													 "12.Id ascendente\n"
													 "13.Id descendente\n"
													 "14.Volver al menu principal\n"
													 "Ingrese una opcion: " ,
													 "\n***************************\n"
													 "ORDENAR\n"
													 "\n***************************\n"
													 "1. Nombre ascendente\n"
													 "2. Nombre descendente\n"
													 "3. Apellido ascendente\n"
													 "4. Apellido descendente\n"
													 "5. Precio descendente\n"
													 "6. Precio ascendente\n"
													 "7. Codigo de Vuelo ascendente\n"
													 "8. Codigo de Vuelo descendente\n"
													 "9. Tipo de Pasajero ascendente\n"
													 "10.Tipo de Pasajero descendente\n"
													 "11.Estado de Vuelo\n"
													 "12.Id ascendente\n"
													 "13.Id descendente\n"
													 "14.Volver al menu principal\n"
													 "Error, Ingrese de vuelta: " , 1, 13);


			switch(option)//preguntar por nombre ascendente o descendente en el menu
			{
			case 1:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyName, 1);
				printf("Ya se ordenaron los pasajeros por nombre ascendente\n");

			break;

			case 2:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyName, 0);
				printf("Ya se ordenaron los pasajeros por nombre descendente\n");

			break;

			case 3:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyLastName, 1);
				printf("Ya se ordenaron los pasajeros por apellido ascendente\n");
			break;

			case 4:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyLastName, 0);
				printf("Ya se ordenaron los pasajeros por apellido descendente\n");
			break;

			case 5:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyPrice, 1);
				printf("Ya se ordenaron los pasajeros por precio ascedente\n");
			break;
			case 6:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyPrice, 0);
				printf("Ya se ordenaron los pasajeros por apellido descendente\n");
			break;
			case 7:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyFlyCode, 1);
				printf("Ya se ordenaron los pasajeros por codigo de vuelo ascendente\n");
			break;
			case 8:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyFlyCode, 0);
				printf("Ya se ordenaron los pasajeros por codigo de vuelo descendente\n");
			break;
			case 9:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyTypePassenger, 1);
				printf("Ya se ordenaron los pasajeros por tipo de pasajero ascendente\n");
			break;
			case 10:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyTypePassenger, 0);
				printf("Ya se ordenaron los pasajeros por tipo de pasajero descendente\n");
			break;
			case 11:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyStatusFlight, 0);
				printf("Ya se ordenaron los pasajeros por estado de vuelo\n");
			break;
			case 12:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyId, 1);
				printf("Ya se ordenaron los pasajeros por id ascendente\n");
			break;

			case 13:
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_comparebyId, 0);
				printf("Ya se ordenaron los pasajeros por id descendente\n");
			break;
			}
			//menu para preguntar que quiere ordenar
		}
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int ret=1;
	int len;
	Passenger* unPasajero;

	FILE* pFile;
	pFile = fopen(path, "w");

		len = ll_len(pArrayListPassenger);

		if(path!=NULL && pArrayListPassenger!=NULL && pFile!=NULL)
		{

				fprintf(pFile, "%s", "id,nombre,apellido,precio,tipo de pasajero, codigo de vuelo, estado de vuelo\n");
				for(int i=0;i<len;i++)
				{

					unPasajero=ll_get(pArrayListPassenger, i);
					fprintf(pFile, "%d,%s,%s,%f,%s,%s,%s\n", unPasajero->id,unPasajero->nombre,unPasajero->apellido,unPasajero->precio, unPasajero->codigoVuelo,unPasajero->tipoPasajero,unPasajero->estadoVuelo);



				}
				printf("Cantidad de pasajeros guardados: %d\n",len);

				fclose(pFile);
				pFile=NULL;
				unPasajero=NULL;

				ret = 0;

		}else
		{
			printf("No se encontro el archivo\n");
		}

	    return ret;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int ret;
	Passenger* unPasajero;
	int len;
	FILE* pFile;

	ret = 0;

	pFile = fopen(path, "wb");

	len = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL && path!= NULL)
	{
		//fwrite("id,nombre,apellido,precio,tipo de pasajero, codigo de vuelo, estado de vuelo", sizeof(char*), 1, pFile);

		for(int i=0;i<len;i++)
		{
			unPasajero=ll_get(pArrayListPassenger, i);
			fwrite(unPasajero, sizeof(Passenger), 1, pFile);
			ret = 1;


		}
		printf("Cantidad de pasajeros guardados: %d\n",len);

	}


		    return ret;
}

