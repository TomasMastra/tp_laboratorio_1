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

	char id[20];
	char nombre[50];
	char edad[20];
	char posicion[50];
	char nacionalidad[50];
	char idSeleccion[20];

	Jugador* unJugador;
	int cantidad;
	int ret=-1;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		ret = 1;
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]", id, nombre, edad, posicion, nacionalidad,idSeleccion);//scaneo falso para que se saltee la primera linea
		while(!feof(pFile))
		{

			cantidad = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,],%[^\n]", id, nombre, edad, posicion, nacionalidad,idSeleccion);

			if(cantidad == 6)
			{



			unJugador = jug_newParametros(id, nombre, edad, posicion, nacionalidad, idSeleccion);


			ll_add(pArrayListJugador, unJugador);



			}else
			{
				jug_delete(unJugador);
			}
		}


	}

	return ret;
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
	int ret = -1;


		if(pFile != NULL && pArrayListJugador != NULL)
		{
			printf("%20s %30s %30s %30s %30s\n","ID", "NOMBRE", "POSICION", "NACIONALIDAD", "EDAD");

			while(!feof(pFile))
			{
				unJugador = jug_new();

			  if(fread(unJugador, sizeof(Jugador), 1, pFile)==1)
			  {
					ll_add(pArrayListJugador, unJugador);

					jug_print(unJugador);
					ret = 1;

			  }else
			  {
				  jug_delete(unJugador);
			  }

			 if(feof(pFile))
			 {
				 break;
			 }




			}

		}



	return ret;
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
	char pais[40];
	char confederacion[40];
	char convocados[40];


		Seleccion* unaSeleccion;
		int cantidad;
		int ret=-1;

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

			ret=1;
		}

		return ret;
}

