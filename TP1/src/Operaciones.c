/*
 * Operaciones.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Tomas Mastra
 */

#ifndef OPERACIONES_C_
#define OPERACIONES_C_
#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



#endif /* OPERACIONES_C_ */


float CalcularDebitoLatam(float precioLatam)
{

	float precioDebitoLatam;

	precioDebitoLatam = precioLatam * 0.9;




	return precioDebitoLatam;
}
float CalcularCreditoLatam(float precioLatam)
{
	float precioCreditoLatam;


	precioCreditoLatam = precioLatam * 1.25;




	return precioCreditoLatam;
}
float CalcularBitCoinLatam(float precioLatam)
{

	float precioBitcoinLatam;
	float bitcoin;

	bitcoin = 4606954.55;


	precioBitcoinLatam = precioLatam / bitcoin;


	return precioBitcoinLatam;
}
float CalcularPrecioUnitarioLatam(float precioLatam, int kilometros)
{
	float precioUnitarioLatam;

	precioUnitarioLatam = precioLatam / kilometros;



	return precioUnitarioLatam;
}

///////////////////////////

float CalcularDebitoAerolineas(float precioAerolineas)
{

	float precioDebitoAerolineas;

	precioDebitoAerolineas = precioAerolineas * 0.9;




	return precioDebitoAerolineas;
}
float CalcularCreditoAerolineas(float precioAerolineas)
{
	float precioCreditoAerolineas;


	precioCreditoAerolineas = precioAerolineas * 1.25;




	return precioCreditoAerolineas;
}
float CalcularBitCoinAerolineas(float precioAerolineas)
{

	float precioBitcoinAerolineas;
	float bitcoin;

	bitcoin = 4606954.55;


	precioBitcoinAerolineas = precioAerolineas / bitcoin;


	return precioBitcoinAerolineas;
}
float CalcularPrecioUnitarioAerolineas(float precioAerolineas, int kilometros)
{
	float precioUnitarioAerolineas;

	precioUnitarioAerolineas = precioAerolineas / kilometros;



	return precioUnitarioAerolineas;
}


float CalcularDiferenciaPrecio(float precioAerolineas, float precioLatam)
{
	float diferencia;

	if(precioAerolineas>precioLatam)
	{
		diferencia = precioAerolineas - precioLatam;
	}else
	{
		diferencia = precioLatam - precioAerolineas;
	}



	return diferencia;
}

int mostrarResultados(float precioDebitoLatam, float precioCreditoLatam, float precioBitcoinLatam, float precioUnitarioLatam, float precioDebitoAerolineas, float precioCreditoAerolineas, float precioBitcoinAerolineas, float precioUnitarioAerolineas, float diferenciaPrecio)
{

   int continuar; //Esta variable la cree para que el uauario pueda ver los precios sin que se vuelva a poner el menu




			            			printf("Latam: \n"
										"a) Precio con tarjeta de débito: %.2f \n"
										"b) Precio con tarjeta de crédito: %.2f \n"
										"c) Precio pagando con bitcoin : %.2f \n"
										"d) Precio unitario: %.2f \n"
										"Aerolíneas:\n"
										"a) Precio con tarjeta de débito: %.2f \n"
										"b) Precio con tarjeta de crédito: %.2f \n"
										"c) Precio pagando con bitcoin : %.2f \n"
										"d) Precio unitario: %.2f \n"
										"La diferencia de precio es : %.2f \n\n", precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas, diferenciaPrecio);



			            			printf("Ingrese un numero para continuar: ");
			            			scanf("%d", &continuar);



	return 0;
}

