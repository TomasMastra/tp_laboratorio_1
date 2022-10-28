/*
 * Confederaciones.h
 *
 *  Created on: 24 oct. 2022
 *      Author: Tomas Mastra
 */

#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;

	int isEmpty;

}eConfederacion;



/**
 * @fn confederacion_inicializar(eConfederacion[], int tamConfederacion)
 * @brief
 *
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return void
 */
void confederacion_inicializar(eConfederacion confederacion[], int tamConfederacion);

/**
 * @fn harcodearConfederacion(eConfederacion[], int tamConfederacion)
 * @brief
 *
 * @param integer recive un puntero a un int
 * @param message recive un mensaje para mostrar
 * @return void
 */
void harcodearConfederacion(eConfederacion confederacion[], int tamConfederacion);


/**
 * @fn mostrarConfederacion(eConfederacion) muestra una confederacion que le pasamos por parametro
 * @brief
 *
 * @param eConfederacion (una sola confederacion)
 * @return void
 */
void mostrarConfederacion(eConfederacion confederacion);

/**
 * @fn mostrarConfederaciones(eConfederacion[], int tamConfederacion)
 * @brief
 *
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return void
 */
void mostrarConfederaciones(eConfederacion confederacion[], int tamConfederacion);


/**
 * @fn confederacion_BuscarPorId(eConfederacion[], int tamConfederacion, int id)
 * @brief
 *
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @param int id le pasamos un id y retorna su posicion
 * @return int (retorna la posicion del id que le pasamos por parametro)
 */
int Confederacion_BuscarPorId(eConfederacion confederacion[], int tamConfederacion, int id);


/**
 * @fn confederacion_buscarLibre(eConfederacion[], int tamConfederacion)
 * @brief
 *
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return int la posicion del array que vamos a agregar
 */
int confederacion_buscarLibre(eConfederacion[], int tamConfederacion);

/**
 * @fn confederacion_agregar(eConfederacion[], int tamConfederacion)
 * @brief
 *
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return int 1 si se agrego la confederacion y -1 si no se agrego
 */
int confederacion_agregar(eConfederacion confederacion[], int tamConfederacion);

/**
 * @fn eliminarConfederacion(eConfederacion[], int tamConfederacion)
 * @brief
 *
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return 1 si se elimino y -1 si no se elimino
 */
int eliminarConfederacion(eConfederacion confederacion[], int tamConfederacion);

/**
 * @fn modificarConfederacion(eConfederacion[], int tamConfederacion)
 * @brief
 *
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return la posicion del array
 */
int modificarConfederacion(eConfederacion confederacion[], int tamConfederacion);

/**
 * @fn confederacion_mostrarMenuModificar(eConfederacion[], int tamConfederacion, int index)
 * @brief
 *
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @param int index la posicion de la confederacion que vamos a eliminar
 * @return -1 si hubo error y 1 si esta salio bien
 */
int confederacion_mostrarMenuModificar(eConfederacion confederacion[], int tamConfederacion, int index);
#endif /* CONFEDERACIONES_H_ */
