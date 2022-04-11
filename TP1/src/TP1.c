/*
 ============================================================================
 Name        : TP1.c
 Author      : Mastapasqua Tomas 1B
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Validaciones.h"
#include "Operaciones.h"

int main(void) {

//Mastrapasqua Tomas 1B
setbuf(stdout, NULL);

	int option;
	int kilometros;
	float precioLatam;
	float precioAerolineas;
	int flagPedirKilometros;
	int flagPedirPrecio;
	int flagCalcular;


	float precioDebitoLatam;
	float precioDebitoAerolineas;
	float precioCreditoLatam;
	float precioCreditoAerolineas;
	float precioBitcoinLatam;
	float precioBitcoinAerolineas;
	float precioUnitarioLatam;
	float precioUnitarioAerolineas;
	float diferenciaPrecio;

	kilometros = 0;
	precioAerolineas = 0;
	precioLatam = 0;
	flagPedirKilometros = 0;
	flagPedirPrecio = 0;
	flagCalcular = 0;

	 precioDebitoLatam = 0;
		 precioDebitoAerolineas = 0;
		 precioCreditoLatam = 0;
		 precioCreditoAerolineas = 0;
		 precioBitcoinLatam = 0;
		 precioBitcoinAerolineas = 0;
		 precioUnitarioLatam = 0;
		 precioUnitarioAerolineas = 0;
		 diferenciaPrecio = 0;


	 do  //a) Tarjeta de débito (descuento 10%)
	 {

	            printf("------------------------------------------------------------------------\n");
		        printf("\n1. ingresar kilometros KM = %d \n\n", kilometros);
		        printf("------------------------------------------------------------------------\n");

		        printf("2. ingresar precio de vuelos (Aerolineas = %.2f "
		        		"Latam = %.2f )\n-Precio vuelo Aerolineas: \n-Precio vuelo Latam \n\n", precioAerolineas, precioLatam);
		        printf("------------------------------------------------------------------------\n");

		        printf("3. Calcular todos los costos:\n"
		            "a) Tarjeta de débito (descuento 10)\n"
		            "b) Tarjeta de crédito (interés 25)\n"
		            "c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
		            "d) Mostrar precio por km (precio unitario)\n"
		            "e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n"
		        	" Ingrese 3 para actualizar los precios \n\n");
		        printf("------------------------------------------------------------------------\n");

		        printf("4. Informar Resultados\n"
		        	   " Latam: \n"
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

		        printf("------------------------------------------------------------------------\n");

		        printf("5. Carga forzada de datos\n\n");
		        printf("------------------------------------------------------------------------\n");

		        printf("6. Salir\n");
		        printf("------------------------------------------------------------------------\n");
		        printf("Elija una opcion:\n\n\n");
		        scanf("%d", &option);

		        switch(option)
		        {
		        	case 1:
		        		kilometros =  PedirKilometros(kilometros);
		        		flagPedirKilometros = 1;

		            break;

		            case 2:


		            	precioAerolineas = PedirPrecioAerolineas(precioAerolineas);
		            	precioLatam = PedirPrecioLatam(precioLatam);
		            	flagPedirPrecio = 1;



		            break;

		            case 3:
		            	if(flagPedirPrecio == 1 && flagPedirKilometros == 1)
		            		{

		            		  precioDebitoLatam = CalcularDebito(precioLatam);
		            		  precioCreditoLatam = CalcularCredito(precioLatam);
		            		  precioBitcoinLatam = CalcularBitCoin(precioLatam);
		            		  precioUnitarioLatam = CalcularPrecioUnitario( precioLatam,  kilometros);
		            		  precioDebitoAerolineas = CalcularDebito(precioAerolineas);
		            		  precioCreditoAerolineas = CalcularCredito(precioAerolineas);
		            		  precioBitcoinAerolineas = CalcularBitCoin(precioAerolineas);
		            		  precioUnitarioAerolineas = CalcularPrecioUnitario( precioAerolineas,  kilometros);
		            		  diferenciaPrecio = CalcularDiferenciaPrecio(precioAerolineas, precioLatam);


		            			flagCalcular = 1;


		            		}else
			            	 {
		            			printf("----------------------------------\n");
		            			printf("Ingrese los kilometros o el precio\n");
		            			printf("-----------------------------------\n");
			            	 }


		            break;
		            case 4:
		            	if(flagCalcular == 1)
		            	{
		            		 mostrarResultados(precioDebitoLatam,  precioCreditoLatam,  precioBitcoinLatam,  precioUnitarioLatam,  precioDebitoAerolineas,  precioCreditoAerolineas,  precioBitcoinAerolineas,  precioUnitarioAerolineas,  diferenciaPrecio);


		            	}else
		            	 {
		            		printf("-----------------------------------\n");
		            		printf("Ingrese los kilometros, el precio o no calculo los precios\n");
		            		printf("-----------------------------------\n");
		            	 }

		            break;
		            case 5:

		            	kilometros = 12944;
		            	precioLatam = 115000;
		            	precioAerolineas = 134870;

		            	precioDebitoLatam = CalcularDebito(precioLatam);
		            	precioCreditoLatam = CalcularCredito(precioLatam);
		            	precioBitcoinLatam = CalcularBitCoin(precioLatam);
		            	precioUnitarioLatam = CalcularPrecioUnitario( precioLatam,  kilometros);
		            	precioDebitoAerolineas = CalcularDebito(precioAerolineas);
		            	precioCreditoAerolineas = CalcularCredito(precioAerolineas);
		            	precioBitcoinAerolineas = CalcularBitCoin(precioAerolineas);
		            	precioUnitarioAerolineas = CalcularPrecioUnitario( precioAerolineas,  kilometros);
		            	diferenciaPrecio = CalcularDiferenciaPrecio(precioAerolineas, precioLatam);
	            		mostrarResultados(precioDebitoLatam,  precioCreditoLatam,  precioBitcoinLatam,  precioUnitarioLatam,  precioDebitoAerolineas,  precioCreditoAerolineas,  precioBitcoinAerolineas,  precioUnitarioAerolineas,  diferenciaPrecio);

		            	break;


		        }


		    }while(option!=6);


	return EXIT_SUCCESS;
}


