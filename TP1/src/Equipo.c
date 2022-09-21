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


int inicializarEquipo(sEquipo equipo[], int tamEquipo)
{
	int ret = -1;
	int i;

	for(i=0;i<tamEquipo;i++)
	{
		equipo[i].isEmpty = VACIO;

	}


	return ret;
}

int inicializarCantidadYCosto(int cantidadPosicion[], int costoMantenimiento[])
{
	int ret = -1;
	int i;

	for(i=0;i<4;i++)
	{
		cantidadPosicion[i]=0;
		costoMantenimiento[i]=0;
	}


	return ret;
}

int ingresarCostos(float *costoHospedaje, float* costoComida, float* costoTransporte)
{
	int ret=-1;
	int option;
	float costo;

	do
	{


	printf("Ingrese Costo de:\n"
			"1. Hospedaje\n"
			"2. Comida\n"
			"3. Transporte\n"
			"4. Volver al menu prncipal");

	scanf("%d", &option);
	switch(option)
	{
	case 1:
		getFloat(&costo, "Ingrese el costo de hospedaje\n","Ingrese el costo de hospedaje\n", 0, 1000000);
		*costoHospedaje=*costoHospedaje+costo;


		break;


	case 2:
		getFloat(&costo, "Ingrese el costo de comida\n","Ingrese el costo de comida\n", 0, 1000000);
				*costoComida=*costoComida+costo;

		break;


	case 3:
		getFloat(&costo, "Ingrese el costo de transporte\n","Ingrese el costo de transporte\n", 0, 1000000);
				*costoTransporte=*costoTransporte+costo;

		break;


	}
	}while(option!=4);




	return ret;

}

int buscarLibre(sEquipo equipo[], int tamEquipo)
{
	int i;
	int index = VACIO;

	for(i=0;i<tamEquipo;i++)
	{
		if(equipo[i].isEmpty == VACIO)
		{
			index = i;
			printf("i vale %d\n", i);
			break;
		}else
			if(i == tamEquipo)
			{
				printf("No hay mas espacio\n");
			}

	}




	return index;


}
int cargarJugadores(sEquipo equipo[], int tamEquipo, int cantidadPosicion[])
{
	int ret = -1;
	int i;


	i = buscarLibre(equipo, tamEquipo);

	if(i!=VACIO)
	{
	getInt(&equipo[i].numero, "Ingrese el numero del jugador\n", "ERROR, Ingrese el numero del jugador\n", 1, 30);

	pedirPosicion(equipo, tamEquipo, i, cantidadPosicion);

	pedirConfederacion(equipo,  tamEquipo,  i); //Pedir numero y validar

	equipo[i].isEmpty = 1;

	mostrarJugador(equipo, i);
	}



	return ret;
}

int pedirPosicion(sEquipo equipo[], int tamEquipo, int index, int cantidadPosicion[])
{
	int ret = -1;
	int option;

	getInt(&option, "Ingrese la posicion del jugador (1: defensor - 2: mediocampista - 3: arquero- 4: delantero)\n", "ERROR, Ingrese la posicion del jugador\n", 1, 4);

	validarPosicion(equipo,  tamEquipo, cantidadPosicion,  index, option);
	calcularCantidad(equipo, index, cantidadPosicion, option);

	return ret;
}

int pedirConfederacion(sEquipo equipo[], int tamEquipo, int index)
{
	int ret = -1;
	int option;

	getInt(&option, "Ingrese la confederacion del jugador\n", "ERROR, Ingrese la confederacion del jugador\n", 1,6);
	validarConfederacion(equipo, tamEquipo, index, option);

	return ret;
}

int validarConfederacion(sEquipo equipo[], int tamEquipo, int index, int option)
{
	int ret = -1;

	switch(option)
		{
		case 1:

		strcpy(equipo[index].confederacion, "AFC");

		break;
		case 2:
			strcpy(equipo[index].confederacion, "CAF");

		break;

		case 3:
			strcpy(equipo[index].confederacion, "CONCACAF");



			break;

		case 4:
			strcpy(equipo[index].confederacion, "CONMEBOL");

			break;


	case 5:
		strcpy(equipo[index].confederacion, "UEFA");



	break;
	case 6:
		strcpy(equipo[index].confederacion, "OFC");

		break;
		}

		equipo[index].idConfederacion = option;



	return ret;
}

int calcularCantidad(sEquipo equipo[], int index, int cantidadPosicion[], int option)
{
	int ret=-1;
	//int cantidadPosicion[4];


	switch(option)
	{
	case 1:

		cantidadPosicion[0]++;

		break;
	case 2:
		cantidadPosicion[1]++;

	break;

	case 3:

		cantidadPosicion[2]++;
		//printf("%d\n",cantidadPosicion[2]);


		break;

	case 4:
		cantidadPosicion[3]++;

		break;

	}



	return ret;

}

int validarPosicion(sEquipo equipo[], int tamEquipo, int cantidadPosicion[], int index, int option)
{
	int ret=-1;

	switch(option)
		{
		case 1:

			if(cantidadPosicion[0] == 8)
			{
				printf("Ya hay 8 defensores\n");
				ret = 1;
			}else
			{
				strcpy(equipo[index].posicion, "Defensor");
			}

			break;
		case 2:

			if(cantidadPosicion[1] == 8)
			{
				printf("Ya hay 8 mediocampistas\n");
				ret = 1;
			}else
			{
				strcpy(equipo[index].posicion, "Mediocampista");
			}

		break;

		case 3:


			if(cantidadPosicion[2] == 2)
			{
				printf("Ya hay 2 arqueros\n");
				ret = 1;
			}else
			{
				strcpy(equipo[index].posicion, "Arquero");
			}


			break;

		case 4:
			if(cantidadPosicion[3] == 4)
			{
				printf("Ya hay 4 delanteros\n");
				ret = 1;
			}else
			{
				strcpy(equipo[index].posicion, "Delantero");
			}


			break;

			ret = 1;
		}




	return ret;
}


void mostrarJugador(sEquipo equipo[], int index)
{

	printf("%d - %s - %s\n", equipo[index].numero, equipo[index].posicion, equipo[index].confederacion);

}

int calcularPromedioJugadores(sEquipo equipo[], int tamEquipo, float* promedioConmebol, float* promedioAfc,  float* promedioCaf, float* promedioConcacaf,float* promedioUefa,float* promedioOfc)
{
	int ret=-1;

	int i;
	int cantidadAfc=0;
	int cantidadCaf=0;
	int cantidadConcacaf=0;
	int cantidadConmebol=0;
	int cantidadUefa=0;
	int cantidadOfc=0;
	int total;



	for(i = 0;i<tamEquipo;i++)
	{


		if(equipo[i].isEmpty!=-1)
		{
			printf("%d\n",equipo[i].idConfederacion);

		switch(equipo[i].idConfederacion)
		{

		case 1:

			cantidadAfc++;


			break;

		case 2:

			cantidadCaf++;

			break;

		case 3:

			cantidadConcacaf++;

			break;

		case 4:

			cantidadConmebol++;

			break;

		case 5:

			cantidadUefa++;

			break;

		case 6:

			cantidadOfc++;

			break;
		}
		}
	}




	total=cantidadAfc+cantidadCaf+cantidadConcacaf+cantidadConmebol+cantidadUefa+cantidadOfc;


	*promedioAfc=(cantidadAfc*100)/total;
	*promedioCaf=(cantidadCaf*100)/total;
	*promedioConcacaf=(cantidadConcacaf*100)/total;
	*promedioConmebol=(cantidadConmebol*100)/total;
	*promedioUefa=(cantidadUefa*100)/total;
	*promedioOfc=(cantidadOfc*100)/total;





	if(cantidadUefa>(total-cantidadUefa))
	{
		ret = 1;
	}


	return ret;
}

int mostrarDatos(float promedioConmebol, float promedioAfc,  float promedioCaf, float promedioConcacaf,float promedioUefa,float promedioOfc, int aumento, float mantenimiento)
{
	int ret=-1;
	float aumentoEuropa;

	printf("promedio afc: %.2f\n",promedioAfc);//mostrar en el punto 4
	printf("cantidad caf: %.2f\n",promedioCaf);
	printf("cantidad concacaf: %.2f\n",promedioConcacaf);
	printf("cantidad conmebol: %.2f\n",promedioConmebol);
	printf("cantidad uefa: %.2f\n",promedioUefa);
	printf("cantidad ofc: %.2f\n",promedioOfc);

	printf("El mantenimiento es %.2f\n", mantenimiento);
	if(aumento==1)
	{
		aumentoEuropa = mantenimiento*1.35;
		printf("Con aumento del 35: %.2f\n", aumentoEuropa);//no me deja poner el %
	}



	return ret;
}
