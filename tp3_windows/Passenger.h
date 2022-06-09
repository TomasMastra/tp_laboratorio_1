/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[21];
	char codigoVuelo[21];
	char estadoVuelo[21];
	//int isEmpty;// agregar estado

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* estadoVueloStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

void Passenger_printOne(Passenger*);

//void Passenger_MenuSort(Passenger* hola);
int Passenger_comparebyName(void* p1, void* p2);
int Passenger_comparebyLastName(void* p1, void* p2);
int Passenger_comparebyPrice(void* p1, void* p2);
int Passenger_comparebyFlyCode(void* p1, void* p2);
int Passenger_comparebyTypePassenger(void* p1, void* p2);
int Passenger_comparebyStatusFlight(void* p1, void* p2);
int Passenger_comparebyId(void* p1, void* p2);



void Passenger_SubMenuModify(Passenger* this);
int Passenger_GetLastId(LinkedList* pArrayListPassenger);



#endif /* PASSENGER_H_ */
