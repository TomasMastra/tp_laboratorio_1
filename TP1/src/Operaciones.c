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


float CalcularDebito(float precio)
{

	float precioDebito;

	precioDebito = precio * 0.9;




	return precioDebito;
}
float CalcularCredito(float precio)
{
	float precioCredito;


	precioCredito = precio * 1.25;




	return precioCredito;
}
float CalcularBitCoin(float precio)
{

	float precioBitcoin;
	float bitcoin;

	bitcoin = 4606954.55;


	precioBitcoin = precio / bitcoin;


	return precioBitcoin;
}
float CalcularPrecioUnitario(float precio, int kilometros)
{
	float precioUnitario;

	precioUnitario = precio / kilometros;



	return precioUnitario;
}

///////////////////////////




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

int mostrarResultados(int kilometros, float precioLatam, float precioDebitoLatam, float precioCreditoLatam, float precioBitcoinLatam, float precioUnitarioLatam, float precioAerolineas, float precioDebitoAerolineas, float precioCreditoAerolineas, float precioBitcoinAerolineas, float precioUnitarioAerolineas, float diferenciaPrecio)
{

   int continuar; //Esta variable la cree para que el uauario pueda ver los precios sin que se vuelva a poner el menu




   	   	   	   	   	   	   	   printf("KMs Ingresados: %d km\n\n", kilometros );

			            			printf("Aerolineas: $%2.f\n"
										"a) Precio con tarjeta de d?bito: $%.2f \n"
										"b) Precio con tarjeta de cr?dito: $%.2f \n"
										"c) Precio pagando con bitcoin: $%.5f BTC \n"
										"d) Precio unitario: $%.2f \n\n"
										"Latam: $%2.f\n"
										"a) Precio con tarjeta de d?bito: $%.2f \n"
										"b) Precio con tarjeta de cr?dito: $%.2f \n"
										"c) Precio pagando con bitcoin: %.5f BTC \n"
										"d) Precio unitario: $%.2f \n\n"
										"La diferencia de precio es: $%.2f \n\n", precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas, precioLatam, precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam,  diferenciaPrecio);





			            			printf("Ingrese un numero para continuar: ");
			            			scanf("%d", &continuar);



	return 0;
}

