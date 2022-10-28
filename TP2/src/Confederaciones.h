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

void mostrarConfederacion(eConfederacion confederacion);
int mostrarConfederaciones(eConfederacion confederacion[], int tamConfederacion);

int Confederacion_BuscarPorId(eConfederacion confederacion[], int tamConfederacion, int id);

int confederacion_buscarLibre(eConfederacion[], int tamConfederacion);
int confederacion_agregar(eConfederacion confederacion[], int tamConfederacion);


int eliminarConfederacion(eConfederacion confederacion[], int tamConfederacion);
int modificarConfederacion(eConfederacion confederacion[], int tamConfederacion);
int confederacion_mostrarMenuModificar(eConfederacion confederacion[], int tamConfederacion, int index);
#endif /* CONFEDERACIONES_H_ */
