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



int parser_SaveJugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{

	Jugador* unJugador;
	int len = ll_len(pArrayListJugador);
	int id;
	char nombreCompleto[41];
	char nacionalidad[31];
	char posicion[41];
	int edad;
	int idSeleccion;
	int ret = -1;

	fprintf(pFile, "%s", "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
	if(pFile!=NULL && pArrayListJugador!=NULL)
	{
		ret=1;
		for(int i=0;i<len;i++)
		{

			unJugador=ll_get(pArrayListJugador, i);

			jug_getId(unJugador, &id);
			jug_getNombreCompleto(unJugador, nombreCompleto);
			jug_getNacionalidad(unJugador, nacionalidad);
			jug_getPosicion(unJugador, posicion);
			jug_getEdad(unJugador, &edad);
			jug_getIdSeleccion(unJugador, &idSeleccion);
			fprintf(pFile, "%d,%s,%d,%s,%s,%d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
			//jug_print(unJugador);


		}
		unJugador=NULL;
		printf("Cantidad de jugadores guardados: %d\n",len);
	}

	return ret;
}


int parser_SaveJugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion,char* confederacion)
{
	Jugador* unJugador;
	Seleccion* unaSeleccion;
	int len = ll_len(pArrayListJugador);
	int lenSelecciones = ll_len(pArrayListSeleccion);
	char confederacionSeleccion[21];
	int seleccion;
	int ret = -1;


	int idSeleccion;

	if(pFile!=NULL && pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			unJugador=ll_get(pArrayListJugador, i);
			jug_getIdSeleccion(unJugador, &idSeleccion);


			for(int j=0;j<lenSelecciones;j++)
			{
				unaSeleccion=ll_get(pArrayListSeleccion, j);

				selec_getConfederacion(unaSeleccion, confederacionSeleccion);
				selec_getId(unaSeleccion, &seleccion);


				if((strcmp(confederacionSeleccion, confederacion)==0) && seleccion == idSeleccion)
				{

				fwrite(unJugador, sizeof(Jugador), 1, pFile);
				jug_print(unJugador);

				break;
				}
			}

		}
	}

	return ret;
}



int parser_SaveSeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	Seleccion* unaSeleccion;
	int len = ll_len(pArrayListSeleccion);
	int id;
	int convocados;
	char confederacion[31];
	char pais[41];
	int ret=-1;

	fprintf(pFile, "%s", "id,pais,confederacion,convocados\n");
	if(pFile!=NULL && pArrayListSeleccion!=NULL)
	{
					for(int i=0;i<len;i++)
					{

						unaSeleccion=ll_get(pArrayListSeleccion, i);

						selec_getId(unaSeleccion, &id);
						selec_getPais(unaSeleccion, pais);
						selec_getConfederacion(unaSeleccion, confederacion);
						selec_getConvocados(unaSeleccion, &convocados);

						fprintf(pFile, "%d,%s,%s,%d\n",id,pais,confederacion,convocados);



					}
					unaSeleccion=NULL;

					ret = 1;
					printf("Cantidad de selecciones guardadas: %d\n",len);
	}


	return ret;
}

