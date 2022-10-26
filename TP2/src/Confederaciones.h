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

}eConfederacion;

void harcodearConfederacion(eConfederacion confederacion[], int tamConfederacion);

void mostrarConfederacion(eConfederacion confederacion);
int mostrarConfederaciones(eConfederacion confederacion[], int tamConfederacion);

int Confederacion_BuscarPorId(eConfederacion confederacion[], int tamConfederacion, int id);
#endif /* CONFEDERACIONES_H_ */
