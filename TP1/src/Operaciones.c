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


	                                printf("-------------------------------------------------\n");
			            			printf("El precio con debito de Latam es %f\n\n", precioDebitoLatam);
			            			printf("El precio con credito de Latam es %f\n\n", precioCreditoLatam);
			            			printf("El precio con bitcoin de Latam es %f\n\n", precioBitcoinLatam);
			            			printf("El precio con unitario de Latam es %f\n\n", precioUnitarioLatam);
			            			printf("-------------------------------------------------\n");
			            			printf("El precio con debito de Aerolineas es %f\n\n", precioDebitoAerolineas);
			            			printf("El precio con credito de Aerolineas es %f\n\n", precioCreditoAerolineas);
			            			printf("El precio con bitcoin de Aerolineas es %f\n\n", precioBitcoinAerolineas);
			            			printf("El precio con unitario de Aerolineas es %f\n\n", precioUnitarioAerolineas);
			            			printf("-------------------------------------------------\n");
			            			printf("La diferencia entre ambas aerolineas es %f\n\n", diferenciaPrecio);
			            			printf("-------------------------------------------------\n\n\n");



			            			printf(" “Latam: \n"
										"a) Precio con tarjeta de débito: %f \n"
										"b) Precio con tarjeta de crédito: %f \n"
										"c) Precio pagando con bitcoin : %f \n"
										"d) Precio unitario: %f \n"
										"Aerolíneas:\n"
										"a) Precio con tarjeta de débito: %f \n"
										"b) Precio con tarjeta de crédito: %f \n "
										"c) Precio pagando con bitcoin : %f \n"
										"d) Precio unitario: %f \n"
										"La diferencia de precio es : %f \n\n “", precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas, diferenciaPrecio);






	return 0;
}

