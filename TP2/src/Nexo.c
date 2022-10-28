/*
 * Nexo.c
 *
 *  Created on: 24 oct. 2022
 *      Author: Tomas Mastra
 */


#ifndef NEXO_C_
#define NEXO_C_

#include "Jugadores.h"
#include "Funciones.h"
#include "Confederaciones.h"
#include "Nexo.h"

int Jugador_agregar(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int id)
{
	int ret = -1;
	int i;
	int opcion;

	 i = Jugador_buscarLibre(jugador,  tamJugador);


	 if(i!=-1)
	 {

		 jugador[i].id = id;
	getName(jugador[i].nombre, "Ingrese el nombre del jugador: ", "ERROR, Ingrese el nombre deel jugador, solo letras y menos de 50: ",50);
	getName(jugador[i].posicion, "Ingrese la posicion del jugador: \n"
			"Arquero\n"
			"Mediocampista\n"
			"Defensor\n"
			"Delantero\n",
			"ERROR, Ingrese la posicion del jugador, solo letras y menos de 50: \n"
			"Arquero\n"
			"Mediocampista\n"
			"Defensor\n"
			"Delantero\n",50);

	getShort(&jugador[i].numeroCamiseta, "Ingrese el numero de la camiseta: ", "ERROR, Ingrese el numero de la camiseta: ",1,30);
	getFloat(&jugador[i].salario, "Ingrese el salario: ", "ERROR, Ingrese el salario: ",100,1000000);
	getShort(&jugador[i].aniosContrato, "Ingrese los anios de contrato: ", "ERROR, Ingrese los anios de contrato: ",1,25);

	pedirConfederacion(jugador,  confederacion,  tamConfederacion,  i);




	getInt(&opcion, "Ingrese 1 para guardar o 2 para cancelar: ", "ERROR, Ingrese 1 para guardar o 2 para cancelar: ",1,2);

		if(opcion==1)
		{
			jugador[i].isEmpty = 1;
			ret = 1;
		}
	 }






	return ret;

}



int pedirConfederacion(eJugador jugador[], eConfederacion confederacion[], int tamConfederacion, int index)
{
	int ret = -1;
	int id;

	 mostrarConfederaciones(confederacion, tamConfederacion);
	 getInt(&id,"Ingrese la confederacion correspondiente: \n"
			 "1. AFC\n"
			 "2. CAF\n"
			 "3. Concacaf\n"
			 "4. Conmebol\n"
			 "5. OFC\n"
			 "6. UEFA\n",
			 "ERROR, Ingrese la confederacion correspondiente: \n"
			 "1. AFC\n"
			 "2. CAF\n"
			 "3. Concacaf\n"
			 "4. Conmebol\n"
			 "5. OFC\n"
			 "6. UEFA\n", 1, 6);



		 jugador[index].idConfederacion = id;




	return ret;
}


int eliminarJugador(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion)
{
	int id;
	int confirmar;
	int index;
	int ret = -1;

	 listarJugadores_Confederacion(jugador,  tamJugador, confederacion,  tamConfederacion);
	getInt(&id,"Ingrese ID para eliminar: ","ERROR, Ingrese ID para eliminar: ",1000,5000);
	index = Jugador_buscarPorId(jugador,  tamJugador,  id);

	if(index!= -1)
	{
		getInt(&confirmar, "Ingrese 1 para eliminar o 2 para cancelar: ", "ERROR, Ingrese 1 para eliminar: ", 1, 2);
		if(confirmar == 1)
		{
			jugador[index].isEmpty=-1;
			printf("Jugador eliminado con exito\n");
			ret = 1;
		}

	}else
	{
		printf("ERROR, No se encontro ese jugador\n");
	}



	return ret;
}

int modificarJugador(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion)
{
	int index;
	int id;


	listarJugadores_Confederacion(jugador,  tamJugador, confederacion,  tamConfederacion);
	getInt(&id,"Ingrese ID del jugador para modificar: ","ERROR, Ingrese ID del jugador para modificar: ",1000,5000);
	index = Jugador_buscarPorId(jugador,  tamJugador,  id);

	printf("%d\n",index);
	if(index>-1)
	{
	 mostrarMenuModificar(jugador,  tamJugador, confederacion,  tamConfederacion,  index);

	}else
	{
		printf("ERROR, No se encontro ese jugador\n");
	}



	return index;
}

int mostrarMenuModificar(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int index)
{
	int ret = -1;
	int validar;
	int opcion;
	int auxInt;
	float auxFloat;
	char auxString[51];


		ret = 1;
		 getInt(&opcion, "-------------------------------------\n"
				 "1. NOMBRE\n"
				 "2. POSICION\n"
				 "3. NUMERO DE CAMISETA\n"
				 "4. CONFEDERACION\n"
				 "5. SALARIO\n"
				 "6. AÑOS DE CONTRATO\n"
				 "-------------------------------------\n"
				 "Ingrese una opcion: ",
				 "-------------------------------------\n"
				 "1. NOMBRE\n"
				 "2. POSICION\n"
				 "3. NUMERO DE CAMISETA\n"
				 "4. CONFEDERACION\n"
				 "5. SALARIO\n"
				 "6. AÑOS DE CONTRATO\n"
				 "-------------------------------------\n"
				 "ERROR, Ingrese una opcion: ", 1, 7);







		switch(opcion)
			{

			case 1:



			getName(auxString, "Ingrese el nombre: ", "Ingrese el nombre: ", 51);

			getInt(&validar, "Ingrese 1 para modificar el nombre: ", "Ingrese 1 para modificar el nombre: ", 1, 1000);
			if(validar==1)
			{
				strcpy(jugador[index].nombre, auxString);
			}

			break;

			case 2:

			getName(auxString, "Ingrese la posicion del jugador: \n"
										"Arquero\n"
										"Mediocampista\n"
										"Defensor\n"
										"Delantero\n",
										"ERROR, Ingrese la posicion del jugador, solo letras y menos de 50: \n"
										"Arquero\n"
										"Mediocampista\n"
										"Defensor\n"
										"Delantero\n",50);

			getInt(&validar, "Ingrese 1 para modificar la posicion: ", "Ingrese 1 para modificar la posicion: ", 1, 1000);
			if(validar==1)
			{
				strcpy(jugador[index].posicion, auxString);
			}


			break;



			case 3:

			getInt(&auxInt, "Ingrese el numero de camiseta: ", "ERROR, Ingrese el numero de camiseta",1,30);

			getInt(&validar, "Ingrese 1 para modificar el numero de camiseta: ", "Ingrese 1 para modificar el numero de camiseta: ", 1, 1000);
			if(validar==1)
			{
				jugador[index].numeroCamiseta = auxInt;
			}


			break;

			case 4:

			 listarJugadores_Confederacion(jugador, tamJugador,  confederacion,  tamConfederacion);

			getInt(&auxInt, "Ingrese la confederacion: ", "ERROR, Ingrese la confederacion",1,30);

			getInt(&validar, "Ingrese 1 para modificar la confederacion: ", "Ingrese 1 para modificar la confederacion: ", 1, 1000);
			if(validar==1)
			{
				jugador[index].idConfederacion = auxInt;
			}


					break;

			case 5:

						getFloat(&auxFloat, "Ingrese el salario: ", "ERROR, Ingrese el salario: ",100,100000000);

						getInt(&validar, "Ingrese 1 para modificar el salario: ", "Ingrese 1 para modificar el salario: ", 1, 1000);
						if(validar==1)
						{
							jugador[index].salario = auxInt;
						}


						break;



			case 6:

						getInt(&auxInt, "Ingrese los años de contrato: ", "ERROR, Ingrese los años de contrato:",1,30);

						getInt(&validar, "Ingrese 1 para modificar los años de contrato: ", "Ingrese 1 para modificar los años de contrato: ", 1, 1000);
						if(validar==1)
						{
							jugador[index].aniosContrato = auxInt;
						}


						break;

			}







	return ret;
}



void listarJugador_Confederacion(eJugador jugador, eConfederacion confederacion)
{
	printf("|%-20d | %-20s | %-15s |%-10d |%20.2f |%-20d |%15s|\n", jugador.id, jugador.nombre, jugador.posicion, jugador.numeroCamiseta, jugador.salario, jugador.aniosContrato, confederacion.nombre);


}
void listarJugadores_Confederacion(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion)
{
	int i;
	int j;

	printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");

	printf("|Lista de jugadores...\n"
							   "|%-20s | %-20s | %-15s |%-10s |%20s |%-20s |%15s|\n", "ID", "NOMBRE", "POSICION", "NUMERO", "SALARIO", "AÑOS CONTRATO", "CONFEDERACION");
	printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");

	for(i=0;i<tamJugador;i++)
	{
		j = compararJugador_Confederacion(confederacion,  tamConfederacion,  jugador[i]);

		if(j!=-1)
		{
		listarJugador_Confederacion(jugador[i], confederacion[j]);
		}

	}


}


int compararJugador_Confederacion(eConfederacion confederacion[], int tamConfederacion, eJugador jugador)
{
	int ret=-1;

	for(int i=0;i<tamConfederacion;i++)
	{
		if(jugador.idConfederacion == confederacion[i].id  && jugador.isEmpty!=-1 && confederacion[i].isEmpty!=-1)
		{
			ret = i;
			break;
		}
	}


	return ret;
}


void listarConfederacionesConSusJugadores(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion)
{

	int jugadorCargado = -1;
	printf("|Lista de jugadores...\n");
	for(int i=0;i<tamConfederacion;i++)
	{
		if(confederacion[i].isEmpty!=-1)
		{
		jugadorCargado = -1;
		printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|%d - %-130s|\n", confederacion[i].id, confederacion[i].nombre);
		 printf("|%-20s | %-20s | %-15s |%-10s |%20s |%-20s |%15s|\n", "ID", "NOMBRE", "POSICION", "NUMERO", "SALARIO", "AÑOS CONTRATO", "CONFEDERACION");

			for(int j=0;j<tamJugador;j++)
			{


				if(jugador[j].idConfederacion == confederacion[i].id && jugador[j].isEmpty!=-1 && confederacion[i].isEmpty!=-1)
				{
					listarJugador_Confederacion(jugador[j], confederacion[i]);
					jugadorCargado = 0;

				}else
				if(jugadorCargado == -1 && j == tamJugador -1 && confederacion[i].isEmpty!=-1)
				{
					printf("|No tiene jugadores cargados %-105s |\n", confederacion[i].nombre);
				}

				//printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");
				//printf("\n\n");

			}
		}

	}



}

void calcularPromedioSalario(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int cantidadJugadores)
{
	float sumaSalario = 0;
	float promedio = 0;


	for(int i =0;i<tamJugador;i++)
	{
		if(jugador[i].isEmpty!=-1)
		{
			sumaSalario = sumaSalario + jugador[i].salario;
		}
	}

	promedio = sumaSalario/cantidadJugadores;
	printf("Total: %.2f\nPromedio: %.2f\n\n", sumaSalario, promedio);
	mostrarJugadoresMasPromedio(jugador,  tamJugador,  confederacion,  tamConfederacion,  promedio);

}
void mostrarJugadoresMasPromedio(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, float promedio)
{

	int j;

	printf("Lista de jugadores que superan el promedio...\n"
								   "|%-20s | %-20s | %-15s |%-10s |%20s |%-20s |%15s|\n", "ID", "NOMBRE", "POSICION", "NUMERO", "SALARIO", "AÑOS CONTRATO", "CONFEDERACION");
	for(int i=0;i<tamJugador;i++)
	{
		j = compararJugador_Confederacion(confederacion,  tamConfederacion,  jugador[i]);
		if(j!=-1 && jugador[i].salario >=promedio && jugador[i].isEmpty!=-1 && confederacion[j].isEmpty!=-1)
		{
			listarJugador_Confederacion(jugador[i], confederacion[j]);

		}

	}
}

void calcularMasAniosContrato(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion)
{

	int cantidadConfederacion;
	int masCantidad = 0;
	int index = -1;
	int mostrar = -1;

	printf("\n\n\n---------------------------\n");
	for(int i=0;i<tamConfederacion;i++)
	{
		cantidadConfederacion = 0;
		for(int j =0;j<tamJugador;j++)
		{
			if(confederacion[i].id == jugador[j].idConfederacion && jugador[j].isEmpty!=-1)
			{
				cantidadConfederacion = cantidadConfederacion + jugador[j].aniosContrato;
			}

		}

		if(confederacion[i].isEmpty!=-1)
		{
		printf("cantidad %s: %d\n", confederacion[i].nombre, cantidadConfederacion);

			if(cantidadConfederacion>masCantidad)
			{
				index = i;
				masCantidad = cantidadConfederacion;
				mostrar = 0;

			}else
				if(cantidadConfederacion>0 && cantidadConfederacion==masCantidad)
				{
					mostrar =1;
				}
		}




	}

	if(mostrar == 0)
			{
			printf("Confederacion con mas cantidad de años de contrato total: %s | Total de años de contrato: %d\n\n\n", confederacion[index].nombre, masCantidad);
			}else
			{
				printf("Hay mas de 1 confederacion con la misma cantidad de años de contrato \n\n\n");
			}

}


void calcularPorcentajeConfederacion(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int jugadores)
{

	float porcentaje;
	int totalConfederacion;
	 printf("Jugadores: %d\n" ,jugadores);


	//totalDiagnosticados = CalcularServiciosDiagnosticados(servicio,  mecanico,  tamServicio,  tamMecanico);

	for(int i=0;i<tamConfederacion;i++)
	{

	 totalConfederacion = calcularCantidadConfederacion(jugador,  tamJugador, confederacion[i]);
	 porcentaje = (float) (totalConfederacion*100)/jugadores;
	 if(confederacion[i].isEmpty!=-1)
	 {
	 printf("Porcentaje de %s: %.2f   \n", confederacion[i].nombre, porcentaje);
	 }

	}


}

int calcularCantidadConfederacion(eJugador jugador[], int tamJugador, eConfederacion confederacion)
{

	int cantidad=0;
	for(int i=0;i<tamJugador;i++)
	{
		if(confederacion.id == jugador[i].idConfederacion && jugador[i].isEmpty !=-1)
		{
			cantidad++;
		}
	}

	return cantidad;

}

void informarRegionMasJugadores(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion)
{

	int totalConfederacion;
	int regionMasJugadores = 0;
	int mostrar = -1;
	int idConfederacion;
	int index = -1;

	for(int i=0;i<tamConfederacion;i++)
		{

			if(confederacion[i].isEmpty!=-1)
			{
			 totalConfederacion = calcularCantidadConfederacion(jugador,  tamJugador, confederacion[i]);
			 printf("Total de %s: %d\n", confederacion[i].nombre, totalConfederacion);

				 if(totalConfederacion>regionMasJugadores && confederacion[i].isEmpty!=-1)
				 {
					 regionMasJugadores = totalConfederacion;
					 idConfederacion = confederacion[i].id;
					 index = i;
					 mostrar = 0;

				 }else
				 {
						if(totalConfederacion>0 && totalConfederacion==regionMasJugadores)
						{
							mostrar = 1;
						}
				 }
			}
		}


	if(mostrar==1)
	{
		printf("Hay mas de 1 region con la misma cantidad de jugadores\n\n");

	}else
	{
		printf("Region con mas jugadores es: %s\n", confederacion[index].nombre);
		listarJugadoresDeUnaConfederacion(jugador,  tamJugador,  confederacion,  tamConfederacion,  idConfederacion);

	}




}


void listarJugadoresDeUnaConfederacion(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int idConfederacion)
{
	int i;
	int j;

	printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");

	printf("|Lista de jugadores para la confederacion...\n"
							   "|%-20s | %-20s | %-15s |%-10s |%20s |%-20s |%15s|\n", "ID", "NOMBRE", "POSICION", "NUMERO", "SALARIO", "AÑOS CONTRATO", "CONFEDERACION");
	printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");

	for(i=0;i<tamJugador;i++)
	{
		j = compararJugador_Confederacion(confederacion,  tamConfederacion,  jugador[i]);

		if(j!=-1 && confederacion[j].id == idConfederacion)
		{
		listarJugador_Confederacion(jugador[i], confederacion[j]);
		}

	}


}


void mostrarSubmenu(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int cantidadJugadores)
{

	int opcion;

	do{
	 getInt(&opcion, "-------------------------------------\n"
			 "1. Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.\n"
			 "2. Listado de confederaciones con sus jugadores.\n"
			 "3. Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.\n"
			 "4. Informar la confederación con mayor cantidad de años de contratos total.\n"
			 "5. Informar porcentaje de jugadores por cada confederación.\n"
			 "6. Informar cual es la región con más jugadores y el listado de los mismos.\n"
			 "7. Salir\n"
			 "-------------------------------------\n"
			 "Ingrese una opcion: ",
			 "-------------------------------------\n"
			 "1. Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.\n"
			 "2. Listado de confederaciones con sus jugadores.\n"
			 "3. Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.\n"
			 "4. Informar la confederación con mayor cantidad de años de contratos total.\n"
			 "5. Informar porcentaje de jugadores por cada confederación.\n"
			 "6. Informar cual es la región con más jugadores y el listado de los mismos.\n"
			 "7. Salir\n"
			 "-------------------------------------\n"
			 "ERROR, Ingrese una opcion: ", 1, 7);


	 switch(opcion)
	 {

	 case 1:
		 Jugador_ordenarPorNombreYConfederacion(jugador, tamJugador);
		listarJugadores_Confederacion(jugador,  tamJugador, confederacion,  tamConfederacion);


		 break;

	 case 2:

		  listarConfederacionesConSusJugadores(jugador,  tamJugador,  confederacion,  tamConfederacion);


		 break;

	 case 3:
		  calcularPromedioSalario(jugador,  tamJugador, confederacion,  tamConfederacion,  cantidadJugadores);

		 break;

	 case 4:

		  calcularMasAniosContrato(jugador,  tamJugador,  confederacion,  tamConfederacion);

		 break;

	 case 5:

		  calcularPorcentajeConfederacion(jugador,  tamJugador,  confederacion,  tamConfederacion,  cantidadJugadores);

		 break;

	 case 6:


		 informarRegionMasJugadores(jugador,  tamJugador, confederacion,  tamConfederacion);


		 break;
	 }

	}while(opcion!=7);


}


#endif /* NEXO_C_ */
