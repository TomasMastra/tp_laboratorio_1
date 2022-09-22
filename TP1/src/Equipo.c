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



int inicializarCantidadYCosto(int cantidadPosicion[], int cantidadConfederacion[])
{
	int ret = -1;
	int i;

	for(i=0;i<6;i++)
	{
		cantidadPosicion[i]=0;
		cantidadConfederacion[i]=0;
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


int cargarJugadores(int* cantidadJugadores, int cantidadPosicion[], int cantidadConfederacion[])
{

	int numero;
	int ret=-1;


	printf("%d\n",*cantidadJugadores);


	if(*cantidadJugadores<23)
	{

		ret=1;
	getInt(&numero, "Ingrese el numero del jugador\n", "ERROR, Ingrese el numero del jugador\n", 1, 30);

	pedirPosicion(cantidadPosicion);

	pedirConfederacion(cantidadConfederacion); //Pedir numero y validar


	cantidadJugadores++;
	}



	return ret;
}

int pedirPosicion(int cantidadPosicion[])
{
	int ret = -1;
	int option;

	getInt(&option, "Ingrese la posicion del jugador (1: arquero - 2: defensor - 3: mediocampista- 4: delantero)\n", "ERROR, Ingrese la posicion del jugador\n", 1, 4);


	while(validarPosicion(cantidadPosicion, option)==1)
	{
		getInt(&option, "Ingrese la posicion del jugador (1: arquero - 2: defensor - 3: mediocampista- 4: delantero)\n", "ERROR, Ingrese la posicion del jugador\n", 1, 4);

	}
	calcularCantidad(cantidadPosicion, option);

	return ret;
}

int pedirConfederacion(int cantidadConfederacion[])
{
	int ret = -1;
	int option;

	getInt(&option, "Ingrese la confederacion del jugador\n", "ERROR, Ingrese la confederacion del jugador\n", 1,6);
	validarConfederacion(cantidadConfederacion, option);

	return ret;
}

int validarConfederacion(int cantidadConfederacion[],int option)
{
	int ret = -1;

	switch(option)
		{
		case 1:
			cantidadConfederacion[0]++;



		break;
		case 2:
			cantidadConfederacion[1]++;
		break;

		case 3:
			cantidadConfederacion[2]++;


			break;

		case 4:
			cantidadConfederacion[3]++;
			break;


	case 5:
		cantidadConfederacion[4]++;


	break;
	case 6:
		cantidadConfederacion[5]++;
		break;
		}




	return ret;
}

int calcularCantidad(int cantidadPosicion[], int option)
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

int validarPosicion(int cantidadPosicion[], int option)
{
	int ret=-1;

	switch(option)
		{
		case 1:

			if(cantidadPosicion[0] == 2)//arquero
			{
				printf("Ya hay 2 arqueros\n");
				ret = 1;
			}else
			{
				//strcpy(equipo[index].posicion, "Arquero");
			}

			break;
		case 2:

			if(cantidadPosicion[1] == 8)
			{
				printf("Ya hay 8 defensores\n");
				ret = 1;
			}else
			{
				//strcpy(equipo[index].posicion, "Defensor");
			}

		break;

		case 3:


			if(cantidadPosicion[2] == 8)
			{
				printf("Ya hay 8 mediocampista\n");
				ret = 1;
			}else
			{
				//strcpy(equipo[index].posicion, "Mediocampista");
			}


			break;

		case 4:
			if(cantidadPosicion[3] == 4)
			{
				printf("Ya hay 4 delanteros\n");
				ret = 1;
			}else
			{
				//strcpy(equipo[index].posicion, "Delantero");
			}


			break;


		}




	return ret;
}




int calcularPromedioJugadores(int cantidadConfederacion[], float* promedioConmebol, float* promedioAfc,  float* promedioCaf, float* promedioConcacaf,float* promedioUefa,float* promedioOfc)
{
	int ret=-1;
	int total;




	total=(float)cantidadConfederacion[0]+cantidadConfederacion[1]+cantidadConfederacion[2]+cantidadConfederacion[3]+cantidadConfederacion[4]+cantidadConfederacion[5];


	*promedioAfc  = (float)(cantidadConfederacion[0]*100)/total;
	*promedioCaf = (float) (cantidadConfederacion[1]*100)/total;
	*promedioConcacaf=(float)(cantidadConfederacion[2]*100)/total;
	*promedioConmebol=(float)(cantidadConfederacion[3]*100)/total;
	*promedioUefa=(float)(cantidadConfederacion[4]*100)/total;
	*promedioOfc=(float)(cantidadConfederacion[5]*100)/total;





	if(cantidadConfederacion[4]>(total-cantidadConfederacion[4]))
	{
		ret = 1;
	}


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
	int ret=-1;
	//float aumentoEuropa;

	printf("-------------------------\n");

	printf("promedio afc: %.2f\n",promedioAfc);//mostrar en el punto 4
	printf("cantidad caf: %.2f\n",promedioCaf);
	printf("cantidad concacaf: %.2f\n",promedioConcacaf);
	printf("cantidad conmebol: %.2f\n",promedioConmebol);
	printf("cantidad uefa: %.2f\n",promedioUefa);
	printf("cantidad ofc: %.2f\n",promedioOfc);

	printf("El mantenimiento es %.2f\n", mantenimiento);
	if(aumento==1)
	{
		printf("Con aumento del 35: %.2f\n", aumentoEuropa);//no me deja poner el %
	}

	printf("-------------------------\n");


	return ret;
}
