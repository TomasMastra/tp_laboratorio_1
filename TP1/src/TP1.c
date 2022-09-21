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
	sEquipo equipo[22];
	//sCantidad cantidad;
	int cantidadPosicion[4];
	int tamEquipo = TAM;
	int option;
	int flag = 0;
	int costoMantenimiento[3];

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
	float mantenimiento;


	 inicializarEquipo(equipo,  tamEquipo);
	 inicializarCantidadYCosto(cantidadPosicion, costoMantenimiento);

		//printf("%d\n",cantidad.arqueros);

	do
		 	    {

		 	    	getInt(&option, "-------------------------------------\n"
		 	    								 "1. INGRESO COSTO DE MANTENIMIENTO\n"
		 	    								 "2. CARGA JUGADORES\n"
		 	    								 "3. REALIZAR CALCULOS\n"
		 	    								 "4. MOSTRAR RESULTADOS\n"
		 	    								 "5. SALIR\n"
		 	    								 "-------------------------------------\n",
		 	    								 "Ingrese una opcion: "
		 	    								 "-------------------------------------\n"
												 "1. INGRESO COSTO DE MANTENIMIENTO\n"
												 "2. CARGA JUGADORES\n"
												 "3. REALIZAR CALCULOS\n"
												 "4. MOSTRAR RESULTADOS\n"
												 "5. SALIR\n"
		 	    								 "-------------------------------------\n"
		 	    								 "ERROR, Ingrese una opcion: ", 1, 5);


		 	        switch(option)
		 	        {
		 	            case 1:
		 	            	 ingresarCostos(&costoHospedaje, &costoComida, &costoTransporte);


		            	flag++;

		 	            break;
		 	            case 2:

		 	             cargarJugadores(equipo,  tamEquipo, cantidadPosicion);

		 	             flag++;

		 	            break;
		 	            case 3:
		 	            	if(flag>1)
		 	            	{

		 	            		 aumento=calcularPromedioJugadores(equipo,  tamEquipo, &promedioConmebol, &promedioAfc,  &promedioCaf, &promedioConcacaf,&promedioUefa,&promedioOfc);
		 	            		 mantenimiento=costoHospedaje+costoTransporte+costoComida;
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
		 	            	 mostrarDatos(promedioConmebol,  promedioAfc,   promedioCaf,  promedioConcacaf, promedioUefa, promedioOfc,  aumento,  mantenimiento);


		 	            	}else
		 	            	{
		 	            		printf("Ingrese la opcion 1 o 2\n");


		 	            	}



		 	            break;


		 	        }
		 	    }while(option!=5);
	return EXIT_SUCCESS;
}
