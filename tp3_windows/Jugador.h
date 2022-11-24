#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[50];
	int edad;
	char posicion[50];
	char nacionalidad[50];
	int idSeleccion;
}Jugador;


/**
 * @fn int jug_new() reserva espacio para un jugador realizando un malloc

 * @brief
 *
 * @return unJugador
 */
Jugador* jug_new();

/**
 * @fn Jugador* jug_newParametros*(char*, char*, char*, char*, char*, char*)
 * @brief reserva un espacio para un Passenger nuevo realizando un maloc reciviendo los datos para setear la estructura
 *
 * @param idStr recive un puntero a char con un id
 * @param nombreCompletoStr recive un puntero a char con un nombre
 * @param edadStr recive un puntero a char con la edad
 * @param posicionStr recive un puntero a char con la posicion
 * @param nacionalidadStr recive un puntero a char con la nacionalidad
 * @param idSeleccionStr recive un puntero a char con el id de la seleccion
 * @return retorna un puntero a un Jugador
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);


/**
 * @fn void jug_delete(Jugador*)
 * @brief hace un free a un jugador para borrarlo en caso de que
 *
 * @param Jugador* this:  recive un puntero a un jugador
 */
void jug_delete(Jugador* this);


/**
 * @fn int jug_setId(Jugador*,int);

 * @brief setea el id a la estructura de Jugador
 *
 * @param Jugador*: puntero a  un jugador
 * @param int id: id del jugador
 * @return 1 si salio bien y 0 si salio mal
 */
int jug_setId(Jugador* this,int id);


/**
 * @fn int jug_getId(Jugador*,int*);

 * @brief recive y devuelve el id
 *
 * @param Jugador*: puntero a un jugador
 * @param int* id: puntero con el id
 * @return 1 si salio bien y 0 si salio mal
 */
int jug_getId(Jugador* this,int* id);


/**
 * @fn int jug_setNombreCompleto(Jugador*,char*);

 * @brief setea el nombre a la estructura de Jugador
 *
 * @param Jugador*: recive un puntero con el jugador un jugador
 * @param char* nombreCompleto: recive un puntero con el nombre
 * @return 1 si salio bien y 0 si salio mal
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);

/**
 * @fn int jug_getNombreCompleto(Jugador*,char*);

 * @brief recive y devuelve el nombre
 *
 * @param Jugador*: recive un puntero a  un jugador
 * @param char* nombreCompleto:recive un puntero con el nombre
 * @return 1 si salio bien y 0 si salio mal
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);


/**
 * @fn int jug_setPosicion(Jugador*,char*);

 * @brief setea la posicion a la estructura de Jugador
 *
 * @param Jugador*: recive un puntero a  un jugador
 * @param char* posicion: recive un puntero a posicion
 * @return 1 si salio bien y 0 si salio mal
 */
int jug_setPosicion(Jugador* this,char* posicion);

/**
 * @fn int jug_getPosicion(Jugador*,char*);

 * @brief recive y devuelve la posicion
 *
 * @param Jugador*:  recive un puntero a un jugador
 * @param char* posicion: recive un puntero a posicion
 * @return 1 si salio bien y 0 si salio mal
 */
int jug_getPosicion(Jugador* this,char* posicion);


/**
 * @fn int jug_setNacionalidad(Jugador*,char*);

 * @brief setea la nacionalidad a la estructura de Jugador
 *
 * @param Jugador*: recive un puntero a jugador
 * @param char* nacionalidad: recive un puntero con la nacionalidad
 * @return 1 si salio bien y 0 si salio mal
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad);

/**
 * @fn int jug_getNacionalidad(Jugador*,char*);

 * @brief recive y devuelve la nacionalidad
 *
 * @param Jugador*: recive un puntero a Jugador
 * @param char* nacionalidad: puntero con la nacionalidad
 * @return 1 si salio bien y 0 si salio mal
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad);


/**
 * @fn int jug_setEdad(Jugador*,int);

 * @brief setea la edad a la estructura de Jugador
 *
 * @param Jugador*: puntero a jugador
 * @param int edad: edad del jugador
 * @return 1 SI SALIO BIEN Y 0 SI SALIO MAL
 */
int jug_setEdad(Jugador* this,int edad);

/**
 * @fn int jug_getEdad(Jugador*,int*);

 * @brief recive y devuelve la edad
 *
 * @param Jugador*: puntero a jugador
 * @param int* edad: puntero con la edad
 * @return 1 si salio bien y 0 si salio mal
 */
int jug_getEdad(Jugador* this,int* edad);

/**
 * @fn int jug_setIdSeleccion(Jugador*,int);

 * @brief setea el idSeleccion a la estructura de Jugador
 *
 * @param Jugador*:  un jugador
 * @param int idSeleccion: el id de la seleccion
 * @return 1 si salio bien y 0 si salio mal
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

/**
 * @fn int jug_getIdSeleccion(Jugador*,int*);

 * @brief recive y devuelve el idSeleccion
 *
 * @param Jugador*: recive un puntero a jugador
 * @param int* idSeleccion: puntero con el idSelecion
 * @return 1 si salio bien y 0 si salio mal
 */
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);




/**
 * @fn int jug_print(Jugador*);

 * @brief
 *
 * @param Jugador*: puntero a un jugador
 * @return void
 */
void jug_print(Jugador* this);

/**
 * @fn int jug_printSubmenuModify(Jugador*);

 * @brief
 *
 * @param Jugador*: puntero a un jugador
 * @return void
 */
int jug_printSubmenuModify(Jugador* this);

/**
 * @fn int jug_compararPorNombre(void*, void*);

 * @brief
 *
 * @param void*
 * @param void*
 * @return ret compara, 1 si un nombre es mayor a la otra, -1 al revez y 0 ambas son iguales
 */
int jug_compararPorNombre(void* p1, void* p2);

/**
 * @fn int jug_compararPorEdad(void*, void*);

 * @brief
 *
 * @param void*
 * @param void*
 * @return ret compara, 1 si una edad es mayor a la otra, -1 al revez y 0 ambas son iguales
 */
int jug_compararPorEdad(void* p1, void* p2);

/**
 * @fn int jug_compararPorNacionalidad(void*, void*);

 * @brief
 *
 * @param void*
 * @param void*
 * @return ret compara, 1 si una nacionalidad es mayor a la otra, -1 al revez y 0 ambas son iguales
 */
int jug_compararPorNacionalidad(void* p1, void* p2);


/**
 * @fn int jug_obtenerId(char*,  int )
 * @brief
 *
 * @param char* path: puntero a char que indica la ruta del archivo
 * @return ret ultimoId (la ultima id cargada)
 */
int jug_obtenerId(char* path);

/**
 * @fn int jug_guardarUltimaId(char*,  int )
 * @brief
 *
 * @param char* path: puntero a char que indica la ruta del archivo
 * @param int id: el id que va a guardar dentro del archivo
 * @return ret 1
 */
int jug_guardarUltimaId(char* path,  int id);

int jug_validarNacionalidad(Jugador* this, char* nacionalidad, LinkedList* listaJugadores);

int jug_validarPosicion(char* posicion, LinkedList* listaJugadores);

#endif // jug_H_INCLUDED
