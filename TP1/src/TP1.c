/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//Mastrapasqua Tomas
#include <stdio.h>
#include <stdlib.h>

#include "Equipo.h"
#include "Funciones.h"
#define TAM 22

int main(void) {

	setbuf(stdout,NULL);
	int cantidadPosicion[4];
	int cantidadConfederacion[6];
	int option;
	int flag = 0;
	//int costoMantenimiento[3];
	int cantidadJugadores=0;

	float costoHospedaje=0;
	float costoComida=0;
	float costoTransporte=0;
	float promedioAfc;
	float promedioCaf;
	float promedioConcacaf;
	float promedioConmebol;
	float promedioUefa;
	float promedioOfc;
	int aumento=0;
	float aumentoEuropa;
	float mantenimiento;



	 inicializarCantidadYCosto(cantidadPosicion, cantidadConfederacion);


	do
		 	    {



		/*printf("afc = %d\n",cantidadConfederacion[0]);
		printf("caf = %d\n",cantidadConfederacion[1]);
		printf("concacaf = %d\n",cantidadConfederacion[2]);
		printf("conmebol = %d\n",cantidadConfederacion[3]);*/

		/*getName(hola, "ingrese nombre", "ingrese nombre\n",21);
		printf("%s\n", hola);
		getString(hola, "ingrese string", "ingrese string\n",21);
		printf("%s\n", hola);*/






		printf( "1. INGRESO DE LOS COSTOS DE MANTENIMIENTO\n"
				"Costo de hospedaje   %.2f\n"
				"Costo de Comida   %.2f\n"
				"Costo de Transporte   %.2f\n"
		 	    "2. CARGA JUGADORES\n"
				"Arqueros  %d \n"
				"Defensores  %d\n"
				"Mediocampistas  %d\n"
				"Delanteros  %d\n"
				 "3. REALIZAR CALCULOS\n"
				 "4. MOSTRAR RESULTADOS\n"
				 "5. SALIR\n"
				 "-------------------------------------\n"
				 "\n", costoHospedaje, costoComida, costoTransporte, cantidadPosicion[0], cantidadPosicion[1], cantidadPosicion[2], cantidadPosicion[3]);

		 	    	getInt(&option, "Ingrese una opcion: \n\n", "ERROR, Ingrese una opcion: \n", 1, 5);


		 	        switch(option)
		 	        {
		 	            case 1:
		 	            	 ingresarCostos(&costoHospedaje, &costoComida, &costoTransporte);


		            	flag++;

		 	            break;
		 	            case 2:

		 	             cargarJugadores(&cantidadJugadores, cantidadPosicion, cantidadConfederacion);

		 	             flag++;

		 	            break;
		 	            case 3:
		 	            	if(flag>1)
		 	            	{

		 	            		 aumento=calcularPromedioJugadores(cantidadConfederacion, &promedioConmebol, &promedioAfc,  &promedioCaf, &promedioConcacaf,&promedioUefa,&promedioOfc);
		 	            		 calcularMantenimiento(&mantenimiento,  costoHospedaje,  costoComida,  costoTransporte,  aumento, &aumentoEuropa);

		 	            		 //mantenimiento=costoHospedaje+costoTransporte+costoComida;
		 	            		 printf("hospedaje: %f", costoHospedaje);
		 	            		printf("El mantenimiento es %.2f\n", mantenimiento);

		 	            		flag++;

		 	            	}else
		 	            	{

		 	            		printf("Ingrese la opcion 1 o 2\n");

		 	            	}



		 	            	break;
		 	            case 4:

		 	            	if(flag >2)
		 	            	{
		 	            	 mostrarDatos(promedioConmebol,  promedioAfc,   promedioCaf,  promedioConcacaf, promedioUefa, promedioOfc,  aumento,  mantenimiento, aumentoEuropa);


		 	            	}else
		 	            	{
		 	            		printf("Ingrese la opcion 1 o 2\n");


		 	            	}



		 	            break;


		 	        }
		 	    }while(option!=5);
	return EXIT_SUCCESS;
}
