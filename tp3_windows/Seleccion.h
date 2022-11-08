#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

/**
 * @fn void selec_delete(Seleccion*)
 * @brief hace un free a una seleccion para borrarla en caso de que no se pueda cargar bien
 *
 * @param this recive un puntero a un empleado
 */
void selec_delete(Seleccion* this);

/**
 * @fn int selec_setId(Seleccion*,int);

 * @brief
 *
 * @param Seleccion*: una seleccion
 * @param int id:
 * @return 1 si salio bien y 0 si salio mal
 */
int selec_setId(Seleccion* this,int id);

/**
 * @fn int selec_getId(Seleccion*,int*);

 * @brief
 *
 * @param Seleccion*: una seleccion
 * @param int* id:
 * @return 1 si salio bien y 0 si salio mal
 */
int selec_getId(Seleccion* this,int* id);


/**
 * @fn int selec_setPais(Seleccion*,char*);

 * @brief
 *
 * @param Seleccion*: una seleccion
 * @param char* pais:
 * @return 1 si salio bien y 0 si salio mal
 */
int selec_setPais(Seleccion* this,char* pais);

/**
 * @fn int selec_getPais(Seleccion*,char*);

 * @brief
 *
 * @param Seleccion*: una seleccion
 * @param char* pais:
 * @return 1 si salio bien y 0 si salio mal
 */
int selec_getPais(Seleccion* this,char* pais);

/**
 * @fn int selec_setConfederacion(Seleccion*,char*);

 * @brief
 *
 * @param Seleccion*: una seleccion
 * @param char* confederacion:
 * @return 1 si salio bien y 0 si salio mal
 */
int selec_setConfederacion(Seleccion* this,char* confederacion);

/**
 * @fn int selec_getConfederacion(Seleccion*,char*);

 * @brief
 *
 * @param Seleccion*: una seleccion
 * @param char* confedracion:
 * @return 1 si salio bien y 0 si salio mal
 */
int selec_getConfederacion(Seleccion* this,char* confederacion);


/**
 * @fn int selec_setConvocados(Seleccion*,int);

 * @brief
 *
 * @param Seleccion*: una seleccion
 * @param int convocados:
 * @return 1 si salio bien y 0 si salio mal
 */
int selec_setConvocados(Seleccion* this,int convocados);

/**
 * @fn int selec_getConvocados(Seleccion*,int*);

 * @brief
 *
 * @param Seleccion*: una seleccion
 * @param int* convocados:
 * @return 1 si salio bien y 0 si salio mal
 */
int selec_getConvocados(Seleccion* this,int* convocados);


/**
 * @fn int selec_print(Seleccion*);

 * @brief muestra las selecciones
 *
 * @param Seleccion*: una seleccion
 * @return void
 */
void selec_print(Seleccion* this);

/**
 * @fn int selec_compararPorConfederacion(void*,void*);

 * @brief compara por confederacion
 *
 * @param void* p1
 * @param void* p2
 * @return 1 si p1 es mayor a p2, -1 si p2 es mayor a p1 y 0 si son iguales
 */
int selec_compararPorConfederacion(void* p1, void* p2);

/**
 * @fn int selec_disminuir convocados(Seleccion*,int);

 * @brief agrega o elimina un convocado de un pais
 *
 * @param Seleccion*: una seleccion
 * @param int* cantidad: le paso 0 si quiero disminuir y 1 si quiero agregar
 * @return void
 */
void selec_disminuirConvocados(Seleccion* this, int cantidad);


#endif // selec_H_INCLUDED
