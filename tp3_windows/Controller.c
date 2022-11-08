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


				if(pFile!=NULL)
				{


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



	id = (jug_obtenerId("ultimaId.csv")+1);
	if(pArrayListJugador!=NULL)
	{

	getName(nombre, "Ingrese el nombre: ", "ERROR, Ingrese el nombre (Solo letras): ", 50);
	getName(posicion, "Ingrese la posicion: ", "ERROR, Ingrese la posicion (Solo letras): ", 50);//mostrar menu
	getInt(&edad, "Ingrese la edad: ", "ERROR, Ingrese la edad", 17, 45);
	getName(nacionalidad, "Ingrese la nacionalidad: ", "ERROR, Ingrese la nacionalidad (Solo letras): ", 50);//mostrar menu
	idSeleccion = 0;




	itoa(id, idStr, 10);
	itoa(edad, edadStr, 10);
	itoa(idSeleccion, idSeleccionStr, 10);


	unJugador = jug_newParametros(idStr, nombre, edadStr, posicion, nacionalidad, idSeleccionStr);

	ll_add(pArrayListJugador,unJugador);
	 jug_guardarUltimaId("ultimaId.csv",  id);

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
		   controller_listarJugadores(pArrayListJugador);

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
					break;

				}

		   }

		   if(index!=-1)
		   {
			   ll_remove(pArrayListJugador, index);//Preguntar si quiere eliminarlo
			   jug_delete(unJugador);
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
		Jugador* listaJugadores=NULL;
		int len;
		if(pArrayListJugador != NULL)
		{
			len = ll_len(pArrayListJugador);
			printf("\n%-5s %-20s %-20s %-20s %-20s %-20s\n\n","ID","NOMBRE","EDAD","POSICION","NACIONALIDAD","ID SELECCION");
			for(int i=0;i<len;i++)
			{
				listaJugadores=ll_get(pArrayListJugador, i);


				 jug_print(listaJugadores);



			}
		}



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
		printf("Ya se ordeno...\n");
		break;

	case 2:

			ll_sort(pArrayListJugador, jug_compararPorNacionalidad, 0);
			printf("Ya se ordeno...\n");

			break;
	case 3:

			ll_sort(pArrayListSeleccion, selec_compararPorConfederacion, 1);
			printf("Ya se ordeno...\n");

			break;
	case 4:

			ll_sort(pArrayListSeleccion, selec_compararPorConfederacion, 0);
			printf("Ya se ordeno...\n");

			break;
	case 5:

			ll_sort(pArrayListJugador, jug_compararPorEdad, 1);
			printf("Ya se ordeno...\n");

			break;
	case 6:

			ll_sort(pArrayListJugador, jug_compararPorEdad, 0);
			printf("Ya se ordeno...\n");

			break;
	case 7:

			ll_sort(pArrayListJugador, jug_compararPorNombre, 1);//puede que haya nombres que empieza con minuscula
			printf("Ya se ordeno...\n");
			break;
	case 8:

			ll_sort(pArrayListJugador, jug_compararPorNombre, 0);
			printf("Ya se ordeno...\n");

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
		char nombreCompleto[40];
		int edad;
		char posicion[40];
		char nacionalidad[30];
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
					printf("Cantidad de jugadores guardados: %d\n",len);


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
	Seleccion* unaSeleccion;
	int len;
	int lenSelecciones;
	FILE* pFile;
	char confederacion[21];
	char confederacionSeleccion[21];
	int idSeleccion;
	int seleccion;


	pFile = fopen(path, "wb");

	len = ll_len(pArrayListJugador);
	lenSelecciones= ll_len(pArrayListSeleccion);

	 controller_listarSelecciones(pArrayListSeleccion);

	getString(confederacion, "Ingrese la Confederacion (Nombre y sus mayusculas): ", "ERROR, Ingrese la confederacion (Nombre y sus mayusculas): ", 50);
	printf("La confederacion es %s\n",confederacion);
	if(pArrayListJugador != NULL && path!= NULL)
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

				break;
				}
			}



		}

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

	Seleccion* listaSelecciones=NULL;
	int len;
	if(pArrayListSeleccion != NULL)
	{
		len = ll_len(pArrayListSeleccion);
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
	int lenJugadores = ll_len(pArrayListJugador);
	int lenSelecciones = ll_len(pArrayListSeleccion);
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
		if(lenJugadores>0)
		{
		 controller_listarJugadores(pArrayListJugador);
		}else
		{
			printf("No cargo los jugadores!!!\n");
		}
		break;
	case 2:
		if(lenSelecciones>0)
		{
		 controller_listarSelecciones(pArrayListSeleccion);
		}			printf("No cargo las selecciones, el punto 9 SOLO carga jugadores!!!\n");

	break;
	case 3:
		if(lenJugadores>0)
		{
	 controller_listarJugadoresConvocados(pArrayListJugador,  pArrayListSeleccion);
		}else
		{
			printf("No cargo los jugadores!!!\n");

		}


	break;
	}


	return 1;


}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
		Jugador* listaJugadores=NULL;
		Seleccion* listaSelecciones=NULL;

		int len;
		int lenSelecciones;
		int idSeleccion;
		int seleccion;
		char confederacion[21];


		if(pArrayListJugador != NULL)
		{


			len = ll_len(pArrayListJugador);
			lenSelecciones = ll_len(pArrayListSeleccion);

			for(int i=0;i<len;i++)
			{

				listaJugadores=ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(listaJugadores, &idSeleccion);

				for(int j=0;j<lenSelecciones;j++)
				{
					listaSelecciones=ll_get(pArrayListSeleccion, j);
					selec_getId(listaSelecciones, &seleccion);

					if(idSeleccion == seleccion)
					{
						printf("××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××\n");
						printf("%10s %5s %30s %20s %25s %17s %20s\n", "CONFEDERACION", "ID", "NOMBRE", "POSICION", "NACIONALIDAD", "EDAD", "ID SELECCION");
						selec_getConfederacion(listaSelecciones, confederacion);

						printf("%-14s ", confederacion);
						jug_print(listaJugadores);

						//printf("××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××\n");



					}
				}



			}
		}



	return 1;
}


int controller_mostrarMenuConvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opcion;
	getInt(&opcion,
				"1. Convocar\n"
				"2. Quitar de la seleccion\n"
				"3. Volver al menu\n"
				"Elija una opcion: \n",
				"1. Convocar\n"
				"2. Quitar de la seleccion\n"
				"3. Volver al menu\n"
				"Elija una opcion: \n",1,3);


		switch(opcion)
		{
		case 1:

		controller_convocarJugadores(pArrayListJugador, pArrayListSeleccion);

		break;


		case 2:

			 controller_quitarJugadorDeSeleccion(pArrayListJugador,pArrayListSeleccion);

		break;




		}

	return 1;
}

int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int id;
	int idJugador;
	int idSeleccion;
	int seleccionJugador;
	int cantidadConvocados;
	int lenJugadores;
	int lenSelecciones;
	int confirmar;
	Jugador* unJugador;
	Seleccion* unaSeleccion;

	lenJugadores = ll_len(pArrayListJugador);
	lenSelecciones = ll_len(pArrayListSeleccion);


	controller_listarJugadores(pArrayListJugador);

	getInt(&id, "Ingrese el id del jugador: ","Ingrese el id del jugador: ",1,1000);


				for(int i=0;i<lenJugadores;i++)
				{
					unJugador = ll_get(pArrayListJugador, i);
					jug_getId(unJugador,&idJugador);
					if(idJugador == id)
					{
						jug_getIdSeleccion(unJugador, &seleccionJugador);

						controller_listarSelecciones(pArrayListSeleccion);
						getInt(&id, "Elija la seleccion a la que sera convocado: ", "ERROR, Elija la seleccion a la que sera convocado: ",1,35);

						//id = 5;
						for(int j=0;j<lenSelecciones;j++)
						{
							unaSeleccion = ll_get(pArrayListSeleccion, j);
							selec_getId(unaSeleccion,&idSeleccion);
							selec_getConvocados(unaSeleccion,&cantidadConvocados);


							if(idSeleccion == id && seleccionJugador == 0 && cantidadConvocados <23)
							{
								getInt(&confirmar, "Ingrese 1 para confirmar: ", "Ingrese 1 para confirmar: ",1,10000);

								if(confirmar == 1)
								{
								 selec_disminuirConvocados(unaSeleccion,1);
								 jug_setIdSeleccion(unJugador, id);
								 break;
								}

							}else
							if(j == lenSelecciones-1)
							{
								printf("*\nPosibles errores:\n1. No existe esa seleccion\n2. El jugador ya esta convocado o no existe\n3.La seleccion llego al limite de convocados\n*\n");
								break;
							}
						}
						break;

					}


				}

			return 1;

}


int controller_quitarJugadorDeSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int id;
	int idJugador;
	int idSeleccion;
	int seleccionJugador;
	int confirmar;
	int lenJugadores;
	int lenSelecciones;
	Jugador* unJugador;
	Seleccion* unaSeleccion;

		lenJugadores = ll_len(pArrayListJugador);
		lenSelecciones = ll_len(pArrayListSeleccion);


		controller_listarJugadores(pArrayListJugador);

		getInt(&id, "Ingrese el id del jugador para sacarlo de la seleccion: ","Ingrese el id del jugador para sacarlo de la seleccion: ",1,1000);


					for(int i=0;i<lenJugadores;i++)
					{
						unJugador = ll_get(pArrayListJugador, i);
						jug_getId(unJugador,&idJugador);
						if(idJugador == id)
						{

							jug_getIdSeleccion(unJugador,&seleccionJugador);

							for(int j=0;j<lenSelecciones;j++)
							{
								unaSeleccion = ll_get(pArrayListSeleccion, j);
								selec_getId(unaSeleccion,&idSeleccion);


								if(idSeleccion == seleccionJugador)
								{

									getInt(&confirmar, "Ingrese 1 para confirmar: ", "Ingrese 1 para confirmar: ",1,10000);

									if(confirmar==1)
									{
									 selec_disminuirConvocados(unaSeleccion,0);
									 jug_setIdSeleccion(unJugador, 0);
									 break;
									}


								}else
									if(j == lenSelecciones-1)
								{
										printf("No se encontro la selecion/jugador o el jugador no esta convocado\n");
								}

							}

						}



					}






				return 1;

}



