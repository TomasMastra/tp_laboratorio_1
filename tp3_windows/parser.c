#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Input.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{

	char id[20];
	char nombre[20];
	char apellido[20];
	char tipo[20];
	char codigo[20];
	char precio[20];
	char estado[20];

	Passenger* unPasajero;
	int cantidad;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]", id, nombre, apellido, precio, codigo, tipo, estado);//scaneo falso para que se saltee la primera linea
		while(!feof(pFile))
		{
			cantidad = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]", id, nombre, apellido, precio, codigo, tipo, estado);

			if(cantidad == 7)
			{

			unPasajero = Passenger_newParametros(id, nombre, apellido, precio, codigo, tipo, estado);
			ll_add(pArrayListPassenger, unPasajero);

			 Passenger_printOne(unPasajero);
			}
		}
		fclose(pFile);

	}

    return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{


		Passenger* unPasajero;


		if(pFile != NULL && pArrayListPassenger != NULL)
		{

			while(!feof(pFile))
			{
				unPasajero = Passenger_new();

				 fread(unPasajero, sizeof(Passenger), 1, pFile);
				 if(feof(pFile))

				 {
					 break;
				 }

				ll_add(pArrayListPassenger, unPasajero);

				 Passenger_printOne(unPasajero);


			}
			fclose(pFile);

		}



    return 1;
}
