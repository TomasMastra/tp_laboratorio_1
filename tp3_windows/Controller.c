#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"
#include "Funciones.h"




/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* pFile;

		pFile = fopen(path, "r");

			if(path!=NULL && pArrayListJugador!=NULL)
			{
				printf("1\n");
				if(pFile!=NULL)
				{
					printf("2\n");

					parser_JugadorFromText(pFile,  pArrayListJugador);

				fclose(pFile);
				pFile = NULL;
				}else
				{
					printf("No se encontro el archivo\n");
				}
			}


	    return 1;

}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)//ver
{
	FILE* pFile;

	pFile = fopen(path, "rb");

		if(path!=NULL && pArrayListJugador!=NULL)
		{
			if(pFile!=NULL)
			{
				parser_JugadorFromBinary(pFile,  pArrayListJugador);

			fclose(pFile);
			pFile = NULL;
			}else
			{
				printf("No se encontro el archivo\n");
			}
		}


	return 1;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{


	char idStr[22];
	char nombre[20];
	char nacionalidad[20];
	char edadStr[20];
	char posicion[20];
	char idSeleccionStr[20];

	int edad;
	int idSeleccion;
	int id;
	Jugador* unJugador;
	unJugador = jug_new();



	//id = 1009;//id autoincremental
	if(pArrayListJugador!=NULL)
	{

		getInt(&id, "Ingrese el id: ", "ERROR, Ingrese el id", 1000, 450000);//borrar

	getName(nombre, "Ingrese el nombre: ", "ERROR, Ingrese el nombre (Solo letras): ", 50);
	getName(posicion, "Ingrese la posicion: ", "ERROR, Ingrese la posicion (Solo letras): ", 50);//mostrar menu
	getInt(&edad, "Ingrese la edad: ", "ERROR, Ingrese la edad", 17, 45);
	getInt(&idSeleccion, "Ingrese el id de la seleccion: ", "ERROR, Ingrese el id de la seleccion", 0, 45);
	getName(nacionalidad, "Ingrese la nacionalidad: ", "ERROR, Ingrese la nacionalidad (Solo letras): ", 50);//mostrar menu





	itoa(id, idStr, 10);
	itoa(edad, edadStr, 10);
	itoa(idSeleccion, idSeleccionStr, 10);

	unJugador = jug_newParametros(idStr, nombre, edadStr, posicion, nacionalidad, idSeleccionStr);

	ll_add(pArrayListJugador,unJugador);
	jug_print(unJugador);
	}

	return 1;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int id;
	int index = -1;
	int len;
	//int option;
	Jugador* unJugador;


	   if(pArrayListJugador!=NULL)
	   {
		   controller_listarJugadores(pArrayListJugador);

		   getInt(&id, "Ingrese el ID del jugador para modificar: ", "ERROR, Ingrese el ID del jugador para modificar: ",1, 20000);
			len=ll_len(pArrayListJugador);

		   for(int i=0;i<len;i++)
		   {

				unJugador=(Jugador*)ll_get(pArrayListJugador, i);

				if(unJugador->id == id)
				{

					index = i;
					break;

				}


		   }

	   }

	   if(index>-1)
	   {
		   jug_printSubmenuModify(unJugador);
	   }else
	   {
		   printf("No se encontro el ID %d\n", id);
	   }


	return 1;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	 int id;
	 int auxId;

	 int seleccion;
	 int idSeleccion;
	 int index = -1;
	 int len;
	 int lenSeleccion;
	 Jugador* unJugador;
	 Seleccion* unaSeleccion;


	   if(pArrayListJugador!=NULL)
	   {
		   //controller_ListPassenger(pArrayListJugador);

		   getInt(&id, "Ingrese el ID del jugador para eliminar: ", "ERROR, Ingrese el ID del jugador para eliminar: ",1, 20000);
			len=ll_len(pArrayListJugador);
			lenSeleccion=ll_len(pArrayListSeleccion);


		   for(int i=0;i<len;i++)
		   {
				unJugador=(Jugador*)ll_get(pArrayListJugador, i);
				jug_getId(unJugador, &auxId);
				if(auxId == id)
				{
					index = i;
					jug_getIdSeleccion(unJugador, &idSeleccion);

				}

		   }

		   if(index!=-1)
		   {
			   ll_remove(pArrayListJugador, index);//Preguntar si quiere eliminarlo
			   unJugador = NULL;
			   for(int j=0;j<lenSeleccion;j++)
			   {
					unaSeleccion=(Seleccion*)ll_get(pArrayListSeleccion, j);
					selec_getId(unaSeleccion, &seleccion);

				   if(idSeleccion == seleccion)
				   {
					selec_disminuirConvocados(unaSeleccion, 0);
				   }
			   }

			   printf("Se elimino el jugador de ID %d\n", id);
		   }else
		   {
			   printf("No se encontro el ID %d\n", id);
		   }
	   }

		return 1;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	//int ret=1;
			Jugador* listaJugadores=NULL;
			int len;
			if(pArrayListJugador != NULL)
			{
				len = ll_len(pArrayListJugador);
				//printf("%d\n", len);
				//printf("\n%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","APELLIDO","PRECIO");
				for(int i=0;i<len;i++)
				{
					listaJugadores=ll_get(pArrayListJugador, i);


			 	 	 jug_print(listaJugadores);
						//printf("%4d %10s %10s %4.2f %10s %10s %10s\n", listaPasajeros->id, listaPasajeros->nombre, listaPasajeros->apellido, listaPasajeros->precio, listaPasajeros->tipoPasajero, listaPasajeros->codigoVuelo, listaPasajeros->estadoVuelo);



				}
			}

			//printf("------------------------------");


		return 1;

}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)//cambiar nombre
{

	int opcion;
	getInt(&opcion,
			"1. Jugadores por nacionalidad (A -> Z)\n"
			"2. Jugadores por nacionalidad (Z -> A)\n"
			"3. Selecciones por confedeeracion (A -> Z)\n"
			"4. Selecciones por confederacion (Z -> A)\n"
			"5. jugadores por Edad (1 -> 9)\n"
			"6, Jugadores por Edad (9 -> 1)\n"
			"7. Jugadores por Nombre (A -> Z)\n"
			"8. jugadores por Nombre (Z -> A)\n"
			"9. Salir\n"
			"Ingrese una opcion: ",
			"1. Jugadores por nacionalidad (A -> Z)\n"
			"2. Jugadores por nacionalidad (Z -> A)\n"
			"3. Selecciones por confedeeracion (A -> Z)\n"
			"4. Selecciones por confederacion (Z -> A)\n"
			"5. jugadores por Edad (1 -> 9)\n"
			"6, Jugadores por Edad (9 -> 1)\n"
			"7. Jugadores por Nombre (A -> Z)\n"
			"8. jugadores por Nombre (Z -> A)\n"
			"9. Salir\n"
			"ERROR: Ingrese una opcion:",1,9);

	switch(opcion)
	{

	case 1:

		ll_sort(pArrayListJugador, jug_compararPorNacionalidad, 1);
		break;

	case 2:

			ll_sort(pArrayListJugador, jug_compararPorNacionalidad, 0);
			break;
	case 3:

			ll_sort(pArrayListSeleccion, selec_compararPorConfederacion, 1);
			break;
	case 4:

			ll_sort(pArrayListSeleccion, selec_compararPorConfederacion, 0);
			break;
	case 5:

			ll_sort(pArrayListJugador, jug_compararPorEdad, 1);//si
			break;
	case 6:

			ll_sort(pArrayListJugador, jug_compararPorEdad, 0);//si
			break;
	case 7:

			ll_sort(pArrayListJugador, jug_compararPorNombre, 1);//no
			break;
	case 8:

			ll_sort(pArrayListJugador, jug_compararPorNombre, 0);
			break;

	}
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int len;
		Jugador* unJugador;

		FILE* pFile;
		pFile = fopen(path, "w");
		int id;
		char nombreCompleto[20];
		int edad;
		char posicion[20];
		char nacionalidad[20];
		int idSeleccion;


		len = ll_len(pArrayListJugador);

			if(path!=NULL && pArrayListJugador!=NULL && pFile!=NULL)
			{

					fprintf(pFile, "%s", "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
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



					}
					printf("Cantidad de selecciones guardadas: %d\n",len);

					fclose(pFile);
					pFile=NULL;
					unJugador=NULL;


			}else
			{
				printf("No se encontro el archivo\n");
			}

	    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	Jugador* unJugador;
	int len;
	FILE* pFile;
	int idConfederacion;



	pFile = fopen(path, "wb");

	len = ll_len(pArrayListJugador);

	 controller_listarSelecciones(pArrayListSeleccion);

	getInt(&idConfederacion, "Ingrese la Confederacion: ", "ERROR, Ingrese la confederacion: ", 0, 50);
	if(pArrayListJugador != NULL && path!= NULL)
	{

		for(int i=0;i<len;i++)
		{
			unJugador=ll_get(pArrayListJugador, i);

			fwrite(unJugador, sizeof(Jugador), 1, pFile);
			jug_print(unJugador);



		}
		printf("Cantidad de jugadores guardados: %d\n",len);

	}

	fclose(pFile);


	return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* pFile;

	pFile = fopen(path, "r");

		if(path!=NULL && pArrayListSeleccion!=NULL)
		{
			if(pFile!=NULL)
			{
				printf("Abriendo el archivo\n\n");
				parser_SeleccionFromText(pFile,  pArrayListSeleccion);

			fclose(pFile);
			pFile = NULL;
			}else
			{
				printf("No se encontro el archivo\n");
			}
		}


	return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	//printf("hola\n");

	Seleccion* listaSelecciones=NULL;
	int len;
	if(pArrayListSeleccion != NULL)
	{
		len = ll_len(pArrayListSeleccion);
		//printf("\n%-5s %-20s %-10s %-10s\n\n","ID","PAIS","CONFEDERACION","CONVOCADOS");
		for(int i=0;i<len;i++)
		{
			listaSelecciones=ll_get(pArrayListSeleccion, i);

			 selec_print(listaSelecciones);




		}
	}


return 1;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int len;
	Seleccion* unaSeleccion;

	FILE* pFile;
	pFile = fopen(path, "w");
	int id;
	char pais[20];
	char confederacion[20];
	int convocados;


	len = ll_len(pArrayListSeleccion);

		if(path!=NULL && pArrayListSeleccion!=NULL && pFile!=NULL)
		{

				fprintf(pFile, "%s", "id,pais,confederacion,convocados\n");
				for(int i=0;i<len;i++)
				{

					unaSeleccion=ll_get(pArrayListSeleccion, i);

					selec_getId(unaSeleccion, &id);
					selec_getPais(unaSeleccion, pais);
					selec_getConfederacion(unaSeleccion, confederacion);
					selec_getConvocados(unaSeleccion, &convocados);

					fprintf(pFile, "%d,%s,%s,%d\n",id,pais,confederacion,convocados);



				}
				printf("Cantidad de selecciones guardadas: %d\n",len);

				fclose(pFile);
				pFile=NULL;
				unaSeleccion=NULL;


		}else
		{
			printf("No se encontro el archivo\n");
		}

    return 1;
}

int controller_mostrarMenuListar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opcion;
	getInt(&opcion,
			"1. MOSTRAR JUGADORES\n"
			"2. MOSTRAR SELECCIONES\n"
			"3. MOSTRAR JUGADORES CONVOCADOS\n"
			"4. REGRESAR AL MENU\n"
			"Ingrese una opcion: \n",
			"1.MOSTRAR JUGADORES\n"
			"2. MOSTRAR SELECCIONES\n"
			"3. MOSTRAR JUGADORES CONVOCADOS\n"
			"4. REGRESAR AL MENU\n"
			"ERROR, Ingrese una opcion: \n",1,4);

	switch(opcion)
	{
	case 1:
		 controller_listarJugadores(pArrayListJugador);
		break;
	case 2:
		 controller_listarSelecciones(pArrayListSeleccion);
	break;
	case 3:
	 controller_listarJugadoresConvocados(pArrayListJugador);
	 //controller_listarJugadores(pArrayListJugador);



	break;
	}


	return 1;


}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador)
{
		Jugador* listaJugadores=NULL;
		int len;
		int idSeleccion;
		if(pArrayListJugador != NULL)
		{
			len = ll_len(pArrayListJugador);
			//printf("\n%-5s %-20s %-10s %-10s\n\n","ID","NOMBRE","POSICION","NACIONALIDAD");
			for(int i=0;i<len;i++)
			{

				listaJugadores=ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(listaJugadores, &idSeleccion);

				if(idSeleccion>0)
				{
				 jug_print(listaJugadores);
				}



			}
		}

		//printf("------------------------------");


	return 1;
}



