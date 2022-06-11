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

/**
 * @fn Passenger Passenegr_new*()
 * @brief reserva espacio para un Passenger nuevo realizando un maloc
 *
 * @return retorna un puntero a Passenger
 */
Passenger* Passenger_new();

/**
 * @fn Passengee Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
 * @brief reserva un espacio para un Passenger nuevo realizando un maloc reciviendo los datos para setear la estructura
 *
 * @param idStr recive un puntero a char con un id
 * @param nombreStr recive un puntero a char con un nombre
 * @param apellidoStr recive un puntero a char con el apellido
 * @param precioStr recive un puntero a char con el precio
 * @param codigoVueloStr recive un puntero a char con el codigo de vuelo
 * @param tipoPasajeroStr recive un puntero a char con el tipo de pasajero
 * @param estadoVueloStr recive un puntero a char con el estado del vuelo
 * @return retorna un puntero a un Passenger
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);

/**
 * @fn void Passenger_delete(Passenger*)
 * @brief hace un free a un empleado para borrarlo en caso de que
 *
 * @param this recive un puntero a un empleado
 */
void Passenger_delete(Passenger* this);

/**
 * @fn int Passenger_setId(Passenger*, int*)
 * @brief setea el id en una estructura de Passenger
 *
 * @param this recive un puntero a un Passenger
 * @param id recive el id del pasajero a setear
 * @return retorna 1  si se pudo cargar o 0 si no se pudo cargar
 */
int Passenger_setId(Passenger* this,int id);
/**
 * @fn int passenger_getId(Passenger*, int*)
 * @brief recive un Passenger y un  puntero a id
 *
 * @param this recive un puntero a un Passenger
 * @param id recive un puntero a un id
 * @return ret 1 si salio bien o 0 si salio mal
 */
int Passenger_getId(Passenger* this,int* id);

/**
 * @fn int Passenger_setNombre(Passenger*, char*)
 * @brief setea el nombre en una estructura de Passenger
 *
 * @param this recive un puntero a un Passenger
 * @param nombe recive el nombre del pasajero a setear
 * @return retorna 1  si se pudo cargar o 0 si no se pudo cargar
 */
int Passenger_setNombre(Passenger* this,char* nombre);

/**
 * @fn int passenger_getNombre(Passenger*, char*)
 * @brief recive un Passenger y un  puntero a nombre
 *
 * @param this recive un puntero a un Passenger
 * @param nombre recive un puntero a un nombre
 * @return ret 1 si salio bien o 0 si salio mal
 */
int Passenger_getNombre(Passenger* this,char* nombre);

/**
 * @fn int Passenger_setApellido(Passenger*, char*)
 * @brief setea el apellido en una estructura de Passenger
 *
 * @param this recive un puntero a un Passenger
 * @param apellido recive el apellido del pasajero a setear
 * @return retorna 1  si se pudo cargar o 0 si no se pudo cargar
 */
int Passenger_setApellido(Passenger* this,char* apellido);

/**
 * @fn int passenger_getApellido(Passenger*, char*)
 * @brief recive un Passenger y un  puntero a apellido
 *
 * @param this recive un puntero a un Passenger
 * @param apellido recive un puntero a un apellido
 * @return ret 1 si salio bien o 0 si salio mal
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/**
 * @fn int Passenger_setCodigoVuelo(Passenger*, char*)
 * @brief setea el codigoVuelo en una estructura de Passenger
 *
 * @param this recive un puntero a un Passenger
 * @param codigoVuelo recive el codigoVuelo del pasajero a setear
 * @return retorna 1  si se pudo cargar o 0 si no se pudo cargar
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * @fn int passenger_getCodigoVuelo(Passenger*, char*)
 * @brief recive un Passenger y un  puntero a codigoVuelo
 *
 * @param this recive un puntero a un Passenger
 * @param codigoVuelo recive un puntero a un codigoVuelo
 * @return ret 1 si salio bien o 0 si salio mal
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * @fn int Passenger_setTipoPasajero(Passenger*, char*)
 * @brief setea el tipoPasajero en una estructura de Passenger
 *
 * @param this recive un puntero a un Passenger
 * @param tipoPasajero recive el tipoPasajero del pasajero a setear
 * @return retorna 1  si se pudo cargar o 0 si no se pudo cargar
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);

/**
 * @fn int passenger_getNombre(Passenger*, char*)
 * @brief recive un Passenger y un  puntero a tipoPasajero
 *
 * @param this recive un puntero a un Passenger
 * @param tipoPasajero recive un puntero a un tipoPasajero
 * @return ret 1 si salio bien o 0 si salio mal
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

/**
 * @fn int Passenger_setPrecio(Passenger*, float*)
 * @brief setea el precio en una estructura de Passenger
 *
 * @param this recive un puntero a un Passenger
 * @param precio recive el precio del pasajero a setear
 * @return retorna 1  si se pudo cargar o 0 si no se pudo cargar
 */
int Passenger_setPrecio(Passenger* this,float precio);

/**
 * @fn int passenger_getNombre(Passenger*, float*)
 * @brief recive un Passenger y un  puntero a precio
 *
 * @param this recive un puntero a un Passenger
 * @param precio recive un puntero a un precio
 * @return ret 1 si salio bien o 0 si salio mal
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/**
 * @fn int Passenger_setEstadoVuelo(Passenger*, char*)
 * @brief setea el estadoVuelo en una estructura de Passenger
 *
 * @param this recive un puntero a un Passenger
 * @param estadoVuelo recive el estadoVuelo del pasajero a setear
 * @return retorna 1  si se pudo cargar o 0 si no se pudo cargar
 */
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);

/**
 * @fn int passenger_getNombre(Passenger*, char*)
 * @brief recive un Passenger y un  puntero a estadoVuelo
 *
 * @param this recive un puntero a un Passenger
 * @param estadoVuelo recive un puntero a un estadoVuelo
 * @return ret 1 si salio bien o 0 si salio mal
 */
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

/**
 * @fn void passenger_printOne(Passenger*)
 * @brief recive un Passenger y lo muestra
 *
 * @param this recive un puntero a un Passenger
 */
void Passenger_printOne(Passenger*);


/**
 * @fn int passenger_getNombre(void*, void*)
 * @brief recive dos Passengers para comparar por nombre
 *
 * @param this recive dos punteros a void
 * @return ret 1 si un pasajero es mayor a otro, 0 si son iguales y -1 si el segundo es mayor
 */
int Passenger_comparebyName(void* p1, void* p2);

/**
 * @fn int passenger_comparebyName(void*, void*)
 * @brief recive dos Passengers para comparar por apellido
 *
 * @param this recive dos punteros a void
 * @return ret 1 si un pasajero es mayor a otro, 0 si son iguales y -1 si el segundo es mayor
 */
int Passenger_comparebyLastName(void* p1, void* p2);

/**
 * @fn int passenger_comparebyPrice(void*, void*)
 * @brief recive dos Passengers para comparar por precio
 *
 * @param this recive dos punteros a void
 * @return ret 1 si un pasajero es mayor a otro, caso contrario retorna -1
 */
int Passenger_comparebyPrice(void* p1, void* p2);

/**
 * @fn int passenger_comparebyFlyCode(void*, void*)
 * @brief recive dos Passengers para comparar por codigoVuelo
 *
 * @param this recive dos punteros a void
 * @return ret 1 si un pasajero es mayor a otro, 0 si son iguales y -1 si el segundo es mayor
 */
int Passenger_comparebyFlyCode(void* p1, void* p2);

/**
 * @fn int passenger_comparebyTypePassenger(void*, void*)
 * @brief recive dos Passengers para comparar por tipoPasajero
 *
 * @param this recive dos punteros a void
 * @return ret 1 si un pasajero es mayor a otro, 0 si son iguales y -1 si el segundo es mayor
 */
int Passenger_comparebyTypePassenger(void* p1, void* p2);

/**
 * @fn int passenger_comparebyStatusFlight(void*, void*)
 * @brief recive dos Passengers para comparar por estadovuelo
 *
 * @param this recive dos punteros a void
 * @return ret 1 si un pasajero es mayor a otro, 0 si son iguales y -1 si el segundo es mayor
 */
int Passenger_comparebyStatusFlight(void* p1, void* p2);

/**
 * @fn int passenger_comparebyPrice(void*, void*)
 * @brief recive dos Passengers para comparar por id (En caso de que se haya ordenado de otra forma)
 *
 * @param this recive dos punteros a void
 * @return ret 1 si un pasajero es mayor a otro, caso contrario retorna -1
 */
int Passenger_comparebyId(void* p1, void* p2);


/**
 * @fn void passenger_SubmenuModify(Passenger*)
 * @brief recive un pasajero para modificar preguntando que quiere modificar
 *
 * @param this recive dos punteros a void
 */
void Passenger_SubMenuModify(Passenger* this);

/**
 * @fn int passenger_GetLastId(LinkedList*)
 * @brief recive el linkedList y busca el ultimo id para poder asignar id a los nuevos pasajeros
 *
 * @param pArrayListPassenger recive un puntero a LinkedList
 * @return retorna el id del nuevo pasajero
 */
int Passenger_GetLastId(LinkedList* pArrayListPassenger);



#endif /* PASSENGER_H_ */
