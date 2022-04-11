/*
 * Validaciones.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Tomas Mastra
 */

#ifndef VALIDACIONES_C_
#define VALIDACIONES_C_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#endif /* VALIDACIONES_C_ */


int PedirKilometros(int kilometros)
{

	printf("Ingrese los kilometros: ");
	scanf("%d", &kilometros);
	while(kilometros <1)
	{
		printf("ERROR, Ingese los kilometros (mas de 1 KM): ");
		scanf("%d", &kilometros);

	}

	return kilometros;
}

int PedirPrecioLatam(int precioLatam)
{

	printf("Ingese el precio de Latam (minimo $10000): ");
	scanf("%d", &precioLatam);
	while(precioLatam <10000)
	{
		printf("ERROR, Ingese el precio de Latam (minimo $10000): ");
		scanf("%d", &precioLatam);

	}

	return precioLatam;
}


int PedirPrecioAerolineas(int precioAerolineas)
{

	printf("Ingrese el precio de Aerolineas(minimo $10000): ");
	scanf("%d", &precioAerolineas);
	while(precioAerolineas <10000)
	{
		printf("ERROR, Ingese el precio de Aerolineas (minimo $10000): ");
		scanf("%d", &precioAerolineas);

	}

	return precioAerolineas;
}
