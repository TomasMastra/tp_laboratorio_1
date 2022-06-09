/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "Input.h"
#include "LinkedList.h"




void Passenger_delete(Passenger* this)
{
	free(this);
}
Passenger* Passenger_new()
{
	Passenger* unPasajero;


	unPasajero = (Passenger*)malloc(sizeof(Passenger));

	return unPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* estadoVueloStr)
{

	Passenger* unPasajero;
	int id;
	float precio;

	if(idStr!=NULL &&  nombreStr!=NULL && tipoPasajeroStr!=NULL && apellidoStr!=NULL &&  precioStr!=NULL &&  codigoVueloStr!=NULL &&  estadoVueloStr!=NULL)
	{
		unPasajero = Passenger_new();



		id = atoi(idStr);
		precio = atof(precioStr);



		if((Passenger_setId(unPasajero, id)==0) || 	(Passenger_setNombre(unPasajero, nombreStr)==0)  || (Passenger_setPrecio(unPasajero, precio)==0) || (Passenger_setApellido(unPasajero, apellidoStr)==0)	|| 	(Passenger_setTipoPasajero(unPasajero, tipoPasajeroStr)==0) || 	(Passenger_setCodigoVuelo(unPasajero, codigoVueloStr)==0) ||	(Passenger_setEstadoVuelo(unPasajero, estadoVueloStr)==0))
		{
			 Passenger_delete(unPasajero);
		}
	}

	return unPasajero;
}

int Passenger_setId(Passenger* this,int id)
{
	int ret;
	ret = 0;
	if(this!=NULL && id>0)
	{
		this->id = id;
		ret = 1;
	}

	return ret;
}
int Passenger_getId(Passenger* this,int* id)
{
	int ret;
	ret = 0;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		ret=1;
	}

	return ret;

}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int ret;
		ret = 0;


		if(this!=NULL && nombre>0)
		{
			strcpy(this->nombre, nombre);

			ret = 1;
		}

		return ret;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int ret;
		ret = 0;
		if(this!=NULL && nombre!=NULL)
		{
			strcpy(nombre, this->nombre);

			ret=1;
		}

		return ret;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int ret;
		ret = 0;
		if(this!=NULL && apellido>0)
		{
			strcpy(this->apellido, apellido);

			ret = 1;
		}

		return ret;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int ret;
		ret = 0;
		if(this!=NULL && apellido!=NULL)
		{
			strcpy(apellido, this->apellido);

			ret=1;
		}

		return ret;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ret;
		ret = 0;
		if(this!=NULL && codigoVuelo>0)
		{
			strcpy(this->codigoVuelo, codigoVuelo);

			ret = 1;
		}

		return ret;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ret;
		ret = 0;
		if(this!=NULL && codigoVuelo!=NULL)
		{
			strcpy(codigoVuelo, this->codigoVuelo);
			ret=1;
		}

		return ret;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int ret;
		ret = 0;
		if(this!=NULL && tipoPasajero>0)
		{
			strcpy(this->tipoPasajero,tipoPasajero);

			ret = 1;
		}

		return ret;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int ret;
		ret = 0;
		if(this!=NULL && tipoPasajero!=NULL)
		{
			strcpy(tipoPasajero, this->tipoPasajero);

			ret=1;
		}

		return ret;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int ret;
		ret = 0;
		if(this!=NULL && precio>0)
		{
			this->precio = precio;
			ret = 1;
		}

		return ret;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int ret;
		ret = 0;
		if(this!=NULL && precio!=NULL)
		{
			*precio = this->precio;
			ret=1;
		}

		return ret;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int ret;
		ret = 0;
		if(this!=NULL && estadoVuelo>0)
		{
			strcpy(this->estadoVuelo,estadoVuelo);

			ret = 1;
		}

		return ret;
}
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int ret;
		ret = 0;
		if(this!=NULL && estadoVuelo!=NULL)
		{
			strcpy(estadoVuelo, this->estadoVuelo);
			ret=1;
		}

		return ret;
}

void Passenger_printOne(Passenger* unPasajero)
{
	int id;
	char nombre[20];
	float precio;
	char apellido[20];
	char tipoPasajero[20];
	char estadoVuelo[20];
	char codigoVuelo[20];

	if(unPasajero!=NULL)
	{
	Passenger_getId(unPasajero, &id);
	Passenger_getNombre(unPasajero, nombre);
	Passenger_getApellido(unPasajero, apellido);
	Passenger_getTipoPasajero(unPasajero, tipoPasajero);
	Passenger_getEstadoVuelo(unPasajero, estadoVuelo);
	Passenger_getCodigoVuelo(unPasajero, codigoVuelo);
	Passenger_getPrecio(unPasajero, &precio);


	printf("%4d %10s %10s %4.2f %10s %10s %10s\n", id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);


	}


}

int Passenger_comparebyName(void* p1, void* p2)
{
	int compara;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(p1!=NULL && p2!=NULL)
	{
	unPasajero = (Passenger*) p1;
	otroPasajero = (Passenger*) p2;

	compara = strcmp(unPasajero->nombre, otroPasajero->nombre);
	}



	return compara;
}

int Passenger_comparebyLastName(void* p1, void* p2)
{
	int compara;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(p1!=NULL && p2!=NULL)
	{
	unPasajero = (Passenger*) p1;
	otroPasajero = (Passenger*) p2;

	compara = strcmp(unPasajero->apellido, otroPasajero->apellido);
	}



	return compara;
}

int Passenger_comparebyPrice(void* p1, void* p2)
{
	int compara;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(p1!=NULL && p2!=NULL)
	{
	unPasajero = (Passenger*) p1;
	otroPasajero = (Passenger*) p2;

		if(unPasajero->precio>otroPasajero->precio)
		{
			compara = 1;
		}
	}



	return compara;
}

int Passenger_comparebyId(void* p1, void* p2)
{
	int compara;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(p1!=NULL && p2!=NULL)
	{
	unPasajero = (Passenger*) p1;
	otroPasajero = (Passenger*) p2;

		if(unPasajero->id>otroPasajero->id)
		{
			compara = 1;
		}
	}



	return compara;
}

int Passenger_comparebyFlyCode(void* p1, void* p2)
{
	int compara;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(p1!=NULL && p2!=NULL)
	{
	unPasajero = (Passenger*) p1;
	otroPasajero = (Passenger*) p2;

	compara = strcmp(unPasajero->codigoVuelo, otroPasajero->codigoVuelo);
	}



	return compara;
}

int Passenger_comparebyStatusFlight(void* p1, void* p2)
{
	int compara;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(p1!=NULL && p2!=NULL)
	{
	unPasajero = (Passenger*) p1;
	otroPasajero = (Passenger*) p2;

	compara = strcmp(unPasajero->estadoVuelo, otroPasajero->estadoVuelo);
	}



	return compara;
}

int Passenger_comparebyTypePassenger(void* p1, void* p2)
{
	int compara;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(p1!=NULL && p2!=NULL)
	{
	unPasajero = (Passenger*) p1;
	otroPasajero = (Passenger*) p2;

	compara = strcmp(unPasajero->tipoPasajero, otroPasajero->tipoPasajero);
	}



	return compara;
}

void Passenger_SubMenuModify(Passenger* this)
{

	int option;
	char nombre[21];
	char apellido[21];
	float precio;
	char confirm;

	printf("Pasajero que va a modificar: \n");
	Passenger_printOne(this);

	getInt(&option,
										 "\n***************************\n"
										 "MODIFICAR\n"
										 "\n***************************\n"
										 "1. Modificar Nombre\n"
										 "2. Modificar Apellido\n"
										 "3. Modificar precio\n"
										 "4. Volver al menu principal\n"
										 "Ingrese una opcion: " ,
										 "\n***************************\n"
										 "MODIFICAR\n"
										 "\n***************************\n"
										 "1. Modificar Nombre\n"
										 "2. Modificar Apellido\n"
										 "3. Modificar precio\n"
										 "4. Volver al menu principal\n"
										 "Error, Ingrese de vuelta: " , 1, 4);


	switch(option)
	{

	case 1:
		getName(nombre, "Ingrese el nombre: ", "Error, Ingrese el nombre (Solo letras): ", 50);
		getChar(&confirm, "Ingrese S para confirmar: ");

		confirm = tolower(confirm);
		if(confirm == 's')
		{
			Passenger_setNombre(this, nombre);
			printf("Se modifico correctamente\n");
		}
	break;

	case 2:
		getName(apellido, "Ingrese el apellido: ", "Error, Ingrese el apellido (Solo letras): ", 50);
				getChar(&confirm, "Ingrese S para confirmar: ");

				confirm = tolower(confirm);
				if(confirm == 's')
				{
					Passenger_setApellido(this, apellido);
					printf("Se modifico correctamente\n");
				}

	break;

	case 3:

		getFloat(&precio, "Ingrese el precio: ", "Error, Ingrese el precio (10.000 - 100.000): ", 10000, 100000);
		getChar(&confirm, "Ingrese S para confirmar: ");

				confirm = tolower(confirm);
				if(confirm == 's')
				{
					Passenger_setPrecio(this, precio);
					printf("Se modifico correctamente\n");
				}

	break;
	}

}


int Passenger_GetLastId(LinkedList* pArrayListPassenger)
{
	int len;
	int flag = 0;
	int mayorId;
	Passenger* unPasajero;

	len = ll_len(pArrayListPassenger);
	for(int i = 0;i<len;i++)
	{
		unPasajero = ll_get(pArrayListPassenger, i);


		if(flag == 0)
		{
			mayorId = unPasajero->id;
			flag = 1;
		}else
		{
			if(unPasajero->id>mayorId)
			{
				mayorId = unPasajero->id;
			}
		}
	}

	return mayorId;
}

