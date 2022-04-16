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
	int flagAerolineas;
	int flagLatam;
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
	flagAerolineas = 0;
	flagLatam = 0;
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


		 printf("1. Ingresar Kilómetros: ( km = %d )\n"
		 "2. Ingresar Precio de Vuelos: (Aerolíneas = %.2f, Latam = %.2f)\n"
		 "- Precio vuelo Aerolíneas:\n"
		 "- Precio vuelo Latam:\n"
		 "3. Calcular todos los costos:\n"
		 "a) Tarjeta de débito (descuento 10) \n"
		 "b) Tarjeta de crédito (interés 25)\n"
		 "c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
		 "d) Mostrar precio por km (precio unitario)"
		 "e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n"
		 "4. Informar Resultados\n"
		 "Latam:\n"
		 "a) Precio con tarjeta de débito: r\n"
		 "b) Precio con tarjeta de crédito: r\n"
		 "c) Precio pagando con bitcoin : r\n"
		 "d) Precio unitario: r\n"
		 "Aerolíneas:\n"
		 "a) Precio con tarjeta de débito: r\n"
		 "b) Precio con tarjeta de crédito: r\n"
		 "c) Precio pagando con bitcoin : r\n"
		 "d) Precio unitario: r\n"
		 "La diferencia de precio es : r\n"
		 "5. Carga forzada de datos\n"
		 "6. Salir\n", kilometros, precioAerolineas, precioLatam);
		        scanf("%d", &option);

		        switch(option)
		        {
		        	case 1:
		        		kilometros =  PedirKilometros(kilometros);
		        		flagPedirKilometros = 1;

		            break;

		            case 2:


		            	printf("Ingrese el precio de (1.Aerolineas o 2.Latam):");
		            	scanf("%d", &option);
		            	while(option <1 || option >2 )
		            	{
		            		printf("ERROR, Ingrese el precio de (1.Aerolineas o 2.Latam):");
		            				            	scanf("%d", &option);
		            	}

		            	if(option == 1)
		            	{
		            	precioAerolineas = PedirPrecioAerolineas(precioAerolineas);
		            	flagAerolineas = 1;

		            	}
		            	else
		            	{
		            	precioLatam = PedirPrecioLatam(precioLatam);
		            	flagLatam = 1;


		            	}



		            break;

		            case 3:
		            	if(flagLatam == 1 && flagAerolineas == 1 && flagPedirKilometros == 1)
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
		            			printf("-----------------------------------\n");
		            			printf("Ingrese los kilometros o el precio\n");
		            			printf("-----------------------------------\n");
			            	 }


		            break;
		            case 4:
		            	if(flagCalcular == 1)
		            	{
		            		 mostrarResultados(kilometros, precioLatam, precioDebitoLatam,  precioCreditoLatam,  precioBitcoinLatam,  precioUnitarioLatam,  precioAerolineas, precioDebitoAerolineas,  precioCreditoAerolineas,  precioBitcoinAerolineas,  precioUnitarioAerolineas,  diferenciaPrecio);


		            	}else
		            	 {
		            		printf("------------------------------------------------------------\n");
		            		printf("Ingrese los kilometros, el precio o no calculo los precios\n");
		            		printf("------------------------------------------------------------\n");
		            	 }

		            break;
		            case 5:

		            	kilometros = 7090;
		            	precioLatam = 1350000.76;
		            	precioAerolineas = 1335000.66;

		            	precioDebitoLatam = CalcularDebito(precioLatam);
		            	precioCreditoLatam = CalcularCredito(precioLatam);
		            	precioBitcoinLatam = CalcularBitCoin(precioLatam);
		            	precioUnitarioLatam = CalcularPrecioUnitario( precioLatam,  kilometros);
		            	precioDebitoAerolineas = CalcularDebito(precioAerolineas);
		            	precioCreditoAerolineas = CalcularCredito(precioAerolineas);
		            	precioBitcoinAerolineas = CalcularBitCoin(precioAerolineas);
		            	precioUnitarioAerolineas = CalcularPrecioUnitario( precioAerolineas,  kilometros);
		            	diferenciaPrecio = CalcularDiferenciaPrecio(precioAerolineas, precioLatam);
	            		mostrarResultados(kilometros, precioLatam, precioDebitoLatam,  precioCreditoLatam,  precioBitcoinLatam,  precioUnitarioLatam,  precioAerolineas, precioDebitoAerolineas,  precioCreditoAerolineas,  precioBitcoinAerolineas,  precioUnitarioAerolineas,  diferenciaPrecio);

		            	break;


		        }


		    }while(option!=6);


	return EXIT_SUCCESS;
}


