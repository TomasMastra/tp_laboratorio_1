/*
 * Equipo.c
 *
 *  Created on: 13 sep. 2022
 *      Author: Tomas Mastra
 */

#include "stdio.h"
#include "Equipo.h"
#include "Funciones.h"
#define VACIO -1





int ingresarCostos(float *costoHospedaje, float* costoComida, float* costoTransporte)
{
	int ret=-1;
	int option;
	float costo;
	int guardar;

	do
	{


	getInt(&option,
	"Ingrese Costo de:\n"
	"1. Hospedaje\n"
	"2. Comida\n"
	"3. Transporte\n"
	"4. Volver al menu principal: "
	"Ingrese una opcion: ",
	"ERROR, Ingrese Costo de:\n"
	"1. Hospedaje\n"
	"2. Comida\n"
	"3. Transporte\n"
	"4. Volver al menu principal: "
	"Ingrese una opcion: ",1,4);
	switch(option)
	{
	case 1:
		getFloat(&costo, "Ingrese el costo de hospedaje\n","Ingrese el costo de hospedaje\n", 0, 1000000);
		getInt(&guardar, "Ingrese 1 para guardar el costo: ", "ERROR, Ingrese 1 para guardar el costo: ", 1, 900);
		if(guardar==1)
		{
				*costoHospedaje=costo;
				printf("El costo de hospedaje actualizado es: %.4f\n", *costoHospedaje);
				ret=1;
		}else
		{
			printf("El costo de hospedaje seguira siendo: %.4f\n", *costoHospedaje);

		}


		break;


	case 2:
		getFloat(&costo, "Ingrese el costo de comida\n","Ingrese el costo de comida\n", 0, 1000000);
		getInt(&guardar, "Ingrese 1 para guardar el costo: ", "ERROR, Ingrese 1 para guardar el costo: ", 1, 900);
		if(guardar==1)
		{
				*costoComida=costo;
				printf("El costo de comida actualizado es: %.4f\n", *costoComida);
				ret=1;
		}else
		{
			printf("El costo de comida seguira siendo: %.4f\n", *costoComida);

		}

		break;


	case 3:
		getFloat(&costo, "Ingrese el costo de transporte\n","Ingrese el costo de transporte\n", 0, 1000000);
		getInt(&guardar, "Ingrese 1 para guardar el costo: ", "ERROR, Ingrese 1 para guardar el costo: ", 1, 900);
		if(guardar==1)
		{
				*costoTransporte=costo;
				printf("El costo de transporte actualizado es: %.4f\n", *costoTransporte);
				ret=1;
		}else
		{
			printf("El costo de transporte seguira siendo: %.4f\n", *costoTransporte);

		}

		break;


	}
	}while(option!=4);




	return ret;

}



 int pedirNumero()
 {
	 int numero;
	getInt(&numero, "Ingrese el numero del jugador: ", "ERROR, Ingrese el numero del jugador: ", 1, 30);

	return numero;

 }
int pedirPosicion(int* cantidadArqueros, int* cantidadDefensores, int* cantidadDelanteros, int* cantidadMediocampistas)
{
	int opcion;

	opcion = 5;

	while(validarPosicion(cantidadArqueros, cantidadDefensores, cantidadDelanteros, cantidadMediocampistas,  opcion)==1)
	{
		getInt(&opcion, "Posicion del jugador\n"
				"1: arquero\n"
				"2: defensor\n"
				"3: mediocampista\n"
				"4: delantero\n"
				"Ingrese una opcion: ",
				"ERROR, Ingrese la posicion del jugador\n"
				"1: arquero\n"
				"2: defensor\n"
				"3: mediocampista\n"
				"4: delantero\n"
				"Ingrese una opcion: ", 1, 4);

	}
	 calcularCantidadPosicion(cantidadArqueros, cantidadDefensores, cantidadDelanteros, cantidadMediocampistas, opcion);

	return opcion;
}

int pedirConfederacion(int *cantidadConcacaf, int *cantidadConmebol, int *cantidadUefa, int *cantidadCaf, int *cantidadAfc, int *cantidadOfc)
{
	int opcion;

	getInt(&opcion, "Ingrese la confederacion del jugador\n"
			"1.Afc\n"
			"2.Caf\n"
			"3.Concacaf\n"
			"4.Conmebol\n"
			"5.Ofc\n"
			"6.Uefa\n"
			"Ingrese una opcion: ",
			"ERROR, Reingrese la confederacion del jugador\n"
			"1.Afc\n"
			"2.Caf\n"
			"3.Concacaf\n"
			"4.Conmebol\n"
			"5.Ofc\n"
			"6.Uefa\n"
			"Ingrese una opcion", 1,6);
	 calcularCantidadConfederacion(cantidadAfc, cantidadUefa,cantidadCaf, cantidadOfc, cantidadConmebol, cantidadConcacaf,  opcion);



	return opcion;
}

int calcularCantidadConfederacion(int* cantidadAfc, int* cantidadUefa,int* cantidadCaf, int* cantidadOfc, int* cantidadConmebol, int* cantidadConcacaf, int opcion)
{
	int ret = -1;

	switch(opcion)
		{
		case 1:
		(*cantidadAfc)++;



		break;
		case 2:
			(*cantidadCaf)++;
		break;

		case 3:
			(*cantidadConcacaf)++;


			break;

		case 4:
			(*cantidadConmebol)++;
			break;


	case 5:
		(*cantidadOfc)++;


	break;
	case 6:
		(*cantidadUefa)++;

		break;
		}







	return ret;
}

int calcularCantidadPosicion(int* cantidadArqueros, int* cantidadDefensores, int* cantidadDelanteros, int* cantidadMediocampistas, int opcion)
{
	int ret=-1;


	switch(opcion)
	{
	case 1:

		(*cantidadArqueros)++;

		break;
	case 2:
		(*cantidadDefensores)++;

	break;

	case 3:

		(*cantidadMediocampistas)++;


		break;

	case 4:
		(*cantidadDelanteros)++;

		break;

	}




	return ret;

}

int validarPosicion(int* cantidadArqueros, int* cantidadDefensores, int* cantidadDelanteros, int* cantidadMediocampistas, int opcion)
{
	int ret=-1;

	switch(opcion)
		{
		case 1:

			if(*cantidadArqueros == 2)
			{
				printf("Ya hay 2 arqueros\n");
				ret = 1;
			}

			break;
		case 2:

			if(*cantidadDefensores == 8)
			{
				printf("Ya hay 8 defensores\n");
				ret = 1;
			}

		break;

		case 3:


			if(*cantidadMediocampistas == 8)
			{
				printf("Ya hay 8 mediocampista\n");
				ret = 1;
			}


			break;

		case 4:
			if(*cantidadDelanteros == 4)
			{
				printf("Ya hay 4 delanteros\n");
				ret = 1;
			}
			break;
		case 5:
			ret = 1;
			break;





		}




	return ret;
}




int calcularPromedioJugadores(int cantidadConcacaf, int cantidadConmebol, int cantidadUefa, int cantidadAfc, int cantidadCaf, int cantidadOfc, float* promedioConmebol, float* promedioAfc,  float* promedioCaf, float* promedioConcacaf, float* promedioUefa, float* promedioOfc)
{
	int ret=-1;
	int totalJugadores;




	totalJugadores=(float)cantidadUefa+cantidadConmebol+cantidadConcacaf+cantidadCaf+cantidadAfc+cantidadOfc;



	if(totalJugadores>0)
	{
	*promedioAfc  = (float)cantidadAfc/totalJugadores;
	*promedioCaf = (float) cantidadCaf/totalJugadores;
	*promedioConcacaf=(float)cantidadConcacaf/totalJugadores;
	*promedioConmebol=(float)cantidadConmebol/totalJugadores;
	*promedioUefa=(float)cantidadUefa/totalJugadores;
	*promedioOfc=(float)cantidadOfc/totalJugadores;
	}



	if(cantidadUefa>(totalJugadores-cantidadUefa))//si uefa representa mas del 50% de jugadores, es decir mas de la mitad
	{
		ret = 1;
	}

	printf("Ya se calculo todo!!!\n\n");
	return ret;
}

int calcularMantenimiento(float* mantenimiento,  float costoHospedaje, float costoComida, float costoTransporte, int aumento, float* aumentoEuropa)
{
	int ret=-1;

	*mantenimiento=costoHospedaje+costoComida+costoTransporte;
	if(aumento==1)
		{
			*aumentoEuropa = *mantenimiento*1.35;
		}




	return ret;
}

int mostrarDatos(float promedioConmebol, float promedioAfc,  float promedioCaf, float promedioConcacaf,float promedioUefa,float promedioOfc, int aumento, float mantenimiento, float aumentoEuropa)
{
	int ret=1;

	printf("-------------------------\n");

	printf("promedio afc: %.2f\n",promedioAfc);
	printf("promedio caf: %.2f\n",promedioCaf);
	printf("promedio concacaf: %.2f\n",promedioConcacaf);
	printf("promedio conmebol: %.2f\n",promedioConmebol);
	printf("promedio uefa: %.2f\n",promedioUefa);
	printf("promedio ofc: %.2f\n",promedioOfc);


	printf("El mantenimiento es %.2f\n", mantenimiento);

	if(aumento==1)//en caso de que sea la mayoria de europa muestra, caso contrario no muestra
	{
		printf("Con aumento del 35º/º: %.2f\n", aumentoEuropa);
	}else
	{
		printf("No hay aumento del 35º/º, debido a que la mayoria de los jugadores no son de uefa\n");
	}

	printf("-------------------------\n");


	return ret;
}
