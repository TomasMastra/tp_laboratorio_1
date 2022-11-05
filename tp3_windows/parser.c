#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Funciones.h"


/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	//printf("3\n");

	char id[20];
	char nombre[50];
	char edad[20];
	char posicion[50];
	char nacionalidad[50];
	char idSeleccion[20];

	Jugador* unJugador;
	int cantidad;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		//printf("4\n");

		fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]", id, nombre, edad, posicion, nacionalidad,idSeleccion);//scaneo falso para que se saltee la primera linea
		while(!feof(pFile))
		{
			//printf("5\n");

			cantidad = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,],%[^\n]", id, nombre, edad, posicion, nacionalidad,idSeleccion);
			//printf("%4s %10s %10s %10s %10s %10s\n", id, nombre, posicion, nacionalidad, edad, idSeleccion);

			if(cantidad == 6)
			{
				//printf("6\n");



			unJugador = jug_newParametros(id, nombre, edad, posicion, nacionalidad, idSeleccion);

			//printf("%4d %10s %10s %10s %10d %10d\n", unJugador->id, unJugador->nombreCompleto, unJugador->posicion, unJugador->nacionalidad, unJugador->edad, unJugador->idSeleccion);

			ll_add(pArrayListJugador, unJugador);
			//jug_print(unJugador);






			}
		}


	}

	return 1;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* unJugador;


			if(pFile != NULL && pArrayListJugador != NULL)
			{

				while(!feof(pFile))
				{


					 fread(unJugador, sizeof(Jugador), 1, pFile);
					 unJugador = jug_new();
					 if(feof(pFile))

					 {
						 break;
					 }

					ll_add(pArrayListJugador, unJugador);

					//jug_print(unJugador);



				}
				fclose(pFile);

			}



	    return 1;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	char id[20];
	char pais[20];
	char confederacion[20];
	char convocados[40];


		Seleccion* unaSeleccion;
		int cantidad;

		if(pFile != NULL && pArrayListSeleccion != NULL)
		{

			fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]", id, pais, confederacion, convocados);
			while(!feof(pFile))
			{
				cantidad = fscanf(pFile,"%[^,], %[^,], %[^,],%[^\n]", id, pais, confederacion, convocados);

				if(cantidad == 4)
				{

				unaSeleccion = selec_newParametros(id, pais, confederacion, convocados);
				 //selec_print(unaSeleccion);

				ll_add(pArrayListSeleccion, unaSeleccion);





				}
			}


		}

		return 1;
}

