/*
 * Confederaciones.c
 *
 *  Created on: 24 oct. 2022
 *      Author: Tomas Mastra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Confederaciones.h"
#include "Funciones.h"


void confederacion_inicializar(eConfederacion confederacion[], int tamConfederacion)
{

	for(int i=0;i<tamConfederacion;i++)
	{
		confederacion[i].isEmpty = -1;
	}

}
void harcodearConfederacion(eConfederacion confederacion[], int tamConfederacion)
{

	eConfederacion auxConfederacion[6] = {{1,"AFC", "Asia", 1954,1}, {2, "CAF", "Africa", 1957,1},{3, "Concacaf","Norteamerica y Centroamerica",1961,1},{4,"Conmebol","Sudamerica",1916,1},{5, "OFC", "Oceania",1966,1},{6, "UEFA", "Europa",1954,1}};

	for(int i=0;i<6;i++)
	{
		confederacion[i] = auxConfederacion[i];
	}
}

int Confederacion_BuscarPorId(eConfederacion confederacion[], int tamConfederacion, int id)
{
	int ret=-1;
		for(int i=0;i<tamConfederacion; i++)
		{
			if(confederacion[i].id == id && confederacion[i].isEmpty!=-1)
			{
				ret = i;
				break;
			}
		}



		return ret;
}


void mostrarConfederacion(eConfederacion confederacion)
{
	printf("| %-5d | %-10s  | %-30s | %-d     |\n", confederacion.id, confederacion.nombre, confederacion.region, confederacion.anioCreacion);
}

void mostrarConfederaciones(eConfederacion confederacion[], int tamConfederacion)
{

	printf("|-----------------------------------------------------------------|\n");
	printf("| %-5s | %-11s | %-30s | %-s |\n", "ID", "NOMBRE", "REGION", "CREACION");
	printf("|-----------------------------------------------------------------|\n");

	for(int i = 0;i<tamConfederacion;i++)
	{
		if(confederacion[i].isEmpty !=-1)
		{
		mostrarConfederacion(confederacion[i]);
		}
	}
	printf("|-----------------------------------------------------------------|\n");



}


int confederacion_buscarLibre(eConfederacion confederacion[], int tamConfederacion)
{
	int ret = -1;

	int i;

	for(i=0;i<tamConfederacion;i++)
	{
		if(confederacion[i].isEmpty==-1)
		{
			ret=i;
			break;
		}
	}

	return ret;
}


int confederacion_agregar(eConfederacion confederacion[], int tamConfederacion)
{
	int ret = -1;
	int i;
	int opcion;

	 i = confederacion_buscarLibre(confederacion,  tamConfederacion);


	 if(i!=-1)
	 {

		 confederacion[i].id = 8+i;
	getName(confederacion[i].nombre, "Ingrese el nombre de la confederacion: ", "ERROR, Ingrese el nombre de la confederacion, solo letras y menos de 50: ",50);
	getName(confederacion[i].region, "Ingrese la region de la confederacion: ", "ERROR, Ingrese la region de la confederacion, solo letras y menos de 50: ",50);
	getInt(&confederacion[i].anioCreacion, "Ingrese el año de creacion de la confederacion: ", "ERROR, Ingrese el año de creacion de la confederacion, solo letras y menos de 50: ",1850,2022);




	getInt(&opcion, "Ingrese 1 para guardar o 2 para cancelar: ", "ERROR, Ingrese 1 para guardar o 2 para cancelar: ",1,2);

		if(opcion==1)
		{
			confederacion[i].isEmpty = 1;
			ret = 1;
		}
	 }






	return ret;

}


int eliminarConfederacion(eConfederacion confederacion[], int tamConfederacion)
{

	int id;
		int confirmar;
		int index;
		int ret = -1;

		 mostrarConfederaciones(confederacion,  tamConfederacion);
		getInt(&id,"Ingrese ID para eliminar: ","ERROR, Ingrese ID para eliminar: ",0,5000);
		index = Confederacion_BuscarPorId(confederacion,  tamConfederacion,  id);

		if(index!= -1)
		{
			getInt(&confirmar, "Ingrese 1 para eliminar o 2 para cancelar: ", "ERROR, Ingrese 1 para eliminar: ", 1, 2);
			if(confirmar == 1)
			{
				confederacion[index].isEmpty=-1;
				printf("confederacion eliminada con exito\n");
				ret = 1;
			}

		}else
		{
			printf("ERROR, No se encontro esa confederacion\n");
		}



		return ret;


}
int modificarConfederacion(eConfederacion confederacion[], int tamConfederacion)
{


	int index;
	int id;


	mostrarConfederaciones(confederacion,  tamConfederacion);
	getInt(&id,"Ingrese ID de la confederacion para modificar: ","ERROR, Ingrese ID de la confederacion para modificar: ",0,5000);
	index = Confederacion_BuscarPorId(confederacion,  tamConfederacion,  id);

	if(index!=-1)
	{
	 confederacion_mostrarMenuModificar(confederacion,  tamConfederacion,  index);
	}else
	{
		printf("ERROR, No se encontro esa confederacion\n");
	}



	return index;
}

int confederacion_mostrarMenuModificar(eConfederacion confederacion[], int tamConfederacion, int index)
{
	int ret = -1;
	int validar;
	int opcion;
	int auxInt;
	char auxString[51];

	if(index!= -1)
		{

		ret = 1;
		 getInt(&opcion, "-------------------------------------\n"
				 "1. NOMBRE\n"
				 "2. REGION\n"
				 "3. AÑO DE CREACION\n"
				 "-------------------------------------\n"
				 "Ingrese una opcion: ",
				 "-------------------------------------\n"
				 "1. NOMBRE\n"
				 "2. REGION\n"
				 "3. AÑO DE CREACION\n"
				 "-------------------------------------\n"
				 "ERROR, Ingrese una opcion: ", 1, 7);







		switch(opcion)
			{

			case 1:



			getName(auxString, "Ingrese el nombre: ", "Ingrese el nombre: ", 51);

			getInt(&validar, "Ingrese 1 para modificar el nombre: ", "Ingrese 1 para modificar el nombre: ", 1, 1000);
			if(validar==1)
			{
				strcpy(confederacion[index].nombre, auxString);
			}

			break;

			case 2:

			getName(auxString, "Ingrese la region de la confederacion: \n","ERROR, Ingrese la region de la confederacion, solo letras y menos de 50: \n",50);

			getInt(&validar, "Ingrese 1 para modificar la region: ", "Ingrese 1 para modificar la region: ", 1, 1000);
			if(validar==1)
			{
				strcpy(confederacion[index].region, auxString);
			}


			break;



			case 3:

			getInt(&auxInt, "Ingrese el año de creacion: ", "ERROR, Ingrese el año de creacion",1850,2022);

			getInt(&validar, "Ingrese 1 para modificar el año de creacion: ", "Ingrese 1 para modificar el año de creacion: ", 1, 1000);
			if(validar==1)
			{
				confederacion[index].anioCreacion = auxInt;
			}


			break;



			}

		}else
		{
			printf("No existe esa confederacion!!!\n");
		}





	return ret;
}

