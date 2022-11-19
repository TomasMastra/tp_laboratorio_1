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
	int option;
	int cantidadJugadores=0;

	float costoHospedaje=0;
	float costoComida=0;
	float costoTransporte=0;
	float promedioAfc=0;
	float promedioCaf=0;
	float promedioConcacaf=0;
	float promedioConmebol=0;
	float promedioUefa=0;
	float promedioOfc=0;
	int aumento=0;
	float aumentoEuropa;
	float mantenimiento;

	int cantidadArqueros=0;
	int cantidadDelanteros=0;
	int cantidadDefensores=0;
	int cantidadMediocampistas=0;

	int cantidadConmebol=0;
	int cantidadCaf=0;
	int cantidadUefa=0;
	int cantidadConcacaf=0;
	int cantidadAfc=0;
	int cantidadOfc=0;

	int flagJugadores = 0;
	int flagCosto = 0;
	int flagCalculos=0;




	do
	{









		printf( "-----------------------------------------\n"
				"1. INGRESO DE LOS COSTOS DE MANTENIMIENTO\n"
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
				 "\n", costoHospedaje, costoComida, costoTransporte, cantidadArqueros, cantidadDefensores, cantidadMediocampistas, cantidadDelanteros);

		 	    	getInt(&option, "Ingrese una opcion: \n\n", "ERROR, Ingrese una opcion: \n", 1, 5);


		 	        switch(option)
		 	        {
		 	            case 1:
		 	            	 ingresarCostos(&costoHospedaje, &costoComida, &costoTransporte);
		 	            	 flagCosto = 1;


		 	            break;
		 	            case 2:


		 	            pedirNumero();
		 	            pedirConfederacion(&cantidadConcacaf, &cantidadConmebol, &cantidadUefa,&cantidadCaf, &cantidadAfc, &cantidadOfc);//
		 	            pedirPosicion(&cantidadArqueros, &cantidadDefensores, &cantidadDelanteros,&cantidadMediocampistas);//
		 	            cantidadJugadores++;
		 	             flagJugadores = 1;

		 	            break;
		 	            case 3:
		 	            	if(flagJugadores==1 && flagCosto == 1)
		 	            	{

		 	            		 aumento=calcularPromedioJugadores(cantidadConcacaf, cantidadConmebol, cantidadUefa, cantidadAfc, cantidadCaf, cantidadOfc, &promedioConmebol, &promedioAfc,  &promedioCaf, &promedioConcacaf,&promedioUefa,&promedioOfc);
		 	            		 calcularMantenimiento(&mantenimiento,  costoHospedaje,  costoComida,  costoTransporte,  aumento, &aumentoEuropa);



		 	            		flagCalculos=1;

		 	            	}else
		 	            	{

		 	            		printf("Ingrese la opcion 1 y 2\n");

		 	            	}



		 	            	break;
		 	            case 4:

		 	            	if(flagCalculos == 1)
		 	            	{
		 	            	 mostrarDatos(promedioConmebol,  promedioAfc,   promedioCaf,  promedioConcacaf, promedioUefa, promedioOfc,  aumento,  mantenimiento, aumentoEuropa);


		 	            	}else
		 	            	{
		 	            		printf("Ingrese los jugadores, el costo y realize los calculos\n");


		 	            	}



		 	            break;


		 	        }
		 	    }while(option!=5);
	return EXIT_SUCCESS;
}
