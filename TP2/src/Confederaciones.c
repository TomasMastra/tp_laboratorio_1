/*
 * Confederaciones.c
 *
 *  Created on: 24 oct. 2022
 *      Author: Tomas Mastra
 */

#include <stdio.h>
#include <stdlib.h>
#include "Confederaciones.h"


void harcodearConfederacion(eConfederacion confederacion[], int tamConfederacion)
{

	eConfederacion auxConfederacion[6] = {{1,"AFC", "Asia", 1954}, {2, "CAF", "Africa", 1957},{3, "Concacaf","Norteamerica y Centroamerica",1961},{4,"Conmebol","Sudamerica",1916},{5, "OFC", "Oceania",1966},{6, "UEFA", "Europa",1954}};

	for(int i=0;i<tamConfederacion;i++)
	{
		confederacion[i] = auxConfederacion[i];
	}
}

int Confederacion_BuscarPorId(eConfederacion confederacion[], int tamConfederacion, int id)
{
	int ret=-1;
		for(int i=0;i<tamConfederacion; i++)
		{
			if(confederacion[i].id == id)
			{
				ret = i;
				break;
			}
		}



		return ret;
}


void mostrarConfederacion(eConfederacion confederacion)
{
	printf("| %-5d | %-10s  | %-30s | %-d     |\n", confederacion.id, confederacion.nombre, confederacion.region, confederacion.anioCreacion);
}

int mostrarConfederaciones(eConfederacion confederacion[], int tamConfederacion)
{
	int ret = -1;

	printf("|-----------------------------------------------------------------|\n");
	printf("| %-5s | %-11s | %-30s | %-s |\n", "ID", "NOMBRE", "REGION", "CREACION");
	printf("|-----------------------------------------------------------------|\n");

	for(int i = 0;i<tamConfederacion;i++)
	{
		mostrarConfederacion(confederacion[i]);
	}
	printf("|-----------------------------------------------------------------|\n");


	return ret;

}
