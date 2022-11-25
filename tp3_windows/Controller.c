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
	int ret = 0;



			if(path!=NULL && pArrayListJugador!=NULL)
			{

				pFile = fopen(path, "r");

				if(pFile!=NULL)
				{

					printf("Abriendo el archivo de jugadores.csv\n\n");
					parser_JugadorFromText(pFile,  pArrayListJugador);
					ret = 1;

				pFile = NULL;
				}else
				{
					printf("No se encontro el archivo de jugadores.csv\n");
				}
				fclose(pFile);

			}


	    return ret;

}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int ret -1 si hubo error y 1 si salio todo bien
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)//ver
{
	FILE* pFile;
	int ret = -1;


			if(path!=NULL && pArrayListJugador!=NULL)
			{
				pFile = fopen(path, "rb");

				if(pFile!=NULL)
				{

					ret = parser_JugadorFromBinary(pFile,  pArrayListJugador);

				pFile = NULL;
				}else
				{
					printf("No se encontro el archivo\n");

				}
				fclose(pFile);

			}


		return ret;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int ret 1 si se agrego el jugador y -1 si hubo un error
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
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
	int ret=-1;
	unJugador = jug_new();



	id = (jug_obtenerId("ultimaId.csv")+1);
	if(pArrayListJugador!=NULL && ll_len(pArrayListJugador) > 0)
	{

	getName(nombre, "Ingrese el nombre: ", "ERROR, Ingrese el nombre (Solo letras): ", 50);
	getInt(&edad, "Ingrese la edad (17 - 45): ", "ERROR, Ingrese la edad (17 - 45)", 17, 45);
	idSeleccion = 0;

	while(jug_validarPosicion(posicion,pArrayListJugador)==-1)//getname solo la primer letra en mayuscula
	{
		getString(posicion, "Ingrese la posicion (solo letras y mayuscula en la primer letra): ", "Ingrese la posicion (Solo letras y mayuscula en la primer letra): ", 50);

	}


	while(controller_validarNacionalidad(pArrayListSeleccion, nacionalidad)==-1)
	{
		getName(nacionalidad, "Ingrese la nacionalidad (solo letras): ", "Ingrese la nacionalidad (Solo letras): ", 50);//mostrar menu
	}





	itoa(id, idStr, 10);
	itoa(edad, edadStr, 10);
	itoa(idSeleccion, idSeleccionStr, 10);


	unJugador = jug_newParametros(idStr, nombre, edadStr, posicion, nacionalidad, idSeleccionStr);

	ll_add(pArrayListJugador,unJugador);
	 jug_guardarUltimaId("ultimaId.csv",  id);
	 ret = 1;

	}else
	{
		printf("No cargo los jugadores!!!\n");
	}

	return ret;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int 1 si se modifico y -1 si hubo error
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int id;
	int index = -1;
	int len;
	int ret = -1;
	Jugador* unJugador;


	   if(pArrayListJugador!=NULL && ll_len(pArrayListJugador)>0)
	   {
		   controller_listarJugadores(pArrayListJugador,  pArrayListSeleccion);

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

	   }else
	   {
		   printf("No cargo los jugadores!!!\n");
	   }

	   if(index>-1)
	   {
		   ret = jug_printSubmenuModify(unJugador);
	   }else
	   {
		   printf("No se encontro el ID %d\n", id);
	   }


	return ret;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int ret: 1 si se elimino y -1 si no se elimino
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	 int id;
	 int auxId;
	 int ret = -1;
	 int seleccion;
	 int idSeleccion;
	 int index = -1;
	 int len;
	 int lenSeleccion;
	 int eliminar;
	 Jugador* unJugador=NULL;
	 Seleccion* unaSeleccion=NULL;


	   if(pArrayListJugador!=NULL && ll_len(pArrayListJugador)>0)
	   {
		   controller_listarJugadores(pArrayListJugador,  pArrayListSeleccion);

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
			   getInt(&eliminar, "Estas seguro que queres eliminar el jugador?? (1 - para eliminar):", "Estas seguro que queres eliminar el jugador?? (1 - para eliminar):", 1,9000);
			   if(eliminar == 1)
			   {
			   ll_remove(pArrayListJugador, index);
			   jug_delete(unJugador);
			   unJugador = NULL;

			   	   for(int j=0;j<lenSeleccion;j++)
				   {
			   		   unaSeleccion=(Seleccion*)ll_get(pArrayListSeleccion, j);
						selec_getId(unaSeleccion, &seleccion);

					   if(idSeleccion == seleccion)
					   {
						selec_disminuirConvocados(unaSeleccion, 0);
						printf("La seleccion del jugador tiene 1 jugador menos\n");
					   }
				   }
				   printf("\nSe elimino el jugador de id %d!!!\n", id);
				   ret = 1;

			   }else
			   {
				   printf("\nNo se elimino el jugador!!!\n");
			   }

		   }else
		   {
			   printf("\nNo se encontro el ID %d\n", id);
		   }


	   }else
	   {
		   printf("No cargo los jugadores!!!\n");
	   }

		return ret;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
		Jugador* listaJugadores=NULL;
		Seleccion* listaSelecciones=NULL;
		int len;
		int lenSelecciones;
		int idSeleccion;
		int seleccion;
		char paisSeleccion[31];
		if(pArrayListJugador != NULL && ll_len(pArrayListJugador)>0)
		{
			len = ll_len(pArrayListJugador);
			lenSelecciones = ll_len(pArrayListSeleccion);
			printf("%s %20s %30s %30s %30s %30s\n","CONFEDERACION", "ID", "NOMBRE", "POSICION", "NACIONALIDAD", "EDAD");

			for(int i=0;i<len;i++)
			{
				listaJugadores=ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(listaJugadores,&idSeleccion);
				printf("******************************************************************************************************************************************\n");

				if(idSeleccion==0)
				{
					printf("No convocado");
					jug_print(listaJugadores);

				}else
				{
					for(int j=0;j<lenSelecciones;j++)
					{
						listaSelecciones=ll_get(pArrayListSeleccion, j);

						selec_getId(listaSelecciones, &seleccion);

						if(seleccion == idSeleccion)
						{
							selec_getPais(listaSelecciones, paisSeleccion);
							printf("%s    ",paisSeleccion);
							jug_print(listaJugadores);


						}
					}
				}
			}
		}else
		{
			printf("No cargo los jugadores!!!\n");
		}



		return 1;

}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return 1 si ordeno y -1 si hubo error
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)//cambiar nombre
{

	int opcion;
	int ret = -1;


		getInt(&opcion,
				"1. Jugadores por nacionalidad (A -> Z)\n"
				"2. Jugadores por nacionalidad (Z -> A)\n"
				"3. Selecciones por confederacion (A -> Z)\n"
				"4. Selecciones por confederacion (Z -> A)\n"
				"5. jugadores por Edad (1 -> 9)\n"
				"6, Jugadores por Edad (9 -> 1)\n"
				"7. Jugadores por Nombre (A -> Z)\n"
				"8. jugadores por Nombre (Z -> A)\n"
				"9. Salir\n"
				"Ingrese una opcion: ",
				"1. Jugadores por nacionalidad (A -> Z)\n"
				"2. Jugadores por nacionalidad (Z -> A)\n"
				"3. Selecciones por confederacion (A -> Z)\n"
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
				printf("Ya se ordeno...\n\nListado de jugadores ordenados:\n");
				controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
				ret = 1;
				break;

		case 2:

				ll_sort(pArrayListJugador, jug_compararPorNacionalidad, 0);
				printf("Ya se ordeno...\n\nListado de jugadores ordenados:\n");
				controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
				ret = 1;
				break;
		case 3:

				ll_sort(pArrayListSeleccion, selec_compararPorConfederacion, 1);
				printf("Ya se ordeno...\n\nListado de selecciones ordenadas:\n");
				controller_listarSelecciones(pArrayListSeleccion);
				ret = 1;
				break;
		case 4:

				ll_sort(pArrayListSeleccion, selec_compararPorConfederacion, 0);
				printf("Ya se ordeno...\n\nListado de selecciones ordenadas:\n");
				controller_listarSelecciones(pArrayListSeleccion);
				ret = 1;
				break;
		case 5:

				ll_sort(pArrayListJugador, jug_compararPorEdad, 1);
				printf("Ya se ordeno...\n\nListado de jugadores ordenados:\n");
				controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
				ret = 1;
				break;
		case 6:

				ll_sort(pArrayListJugador, jug_compararPorEdad, 0);
				printf("Ya se ordeno...\n\nListado de jugadores ordenados:\n");
				controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
				ret = 1;
				break;
		case 7:

				ll_sort(pArrayListJugador, jug_compararPorNombre, 1);//puede que haya nombres que empieza con minuscula
				printf("Ya se ordeno...\n\nListado de jugadores ordenados:\n");
				controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
				ret = 1;
				break;
		case 8:

				ll_sort(pArrayListJugador, jug_compararPorNombre, 0);
				printf("Ya se ordeno...\n\nListado de jugadores ordenados:\n");
				controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
				ret = 1;
				break;


		}

    return ret;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int ret 1 salio todo bien y -1 hubo error
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int len;

		FILE* pFile;

		int ret = -1;

		len = ll_len(pArrayListJugador);

			if(pArrayListJugador!=NULL &&  len > 0)
			{
				pFile = fopen(path, "w");
				if(path!=NULL && pFile!=NULL)
				{
				 parser_SaveJugadorFromText(pFile , pArrayListJugador);

					fclose(pFile);
					pFile=NULL;
					ret = 1;
				}


			}else
			{
				printf("No se encontro el archivo o no cargo los jugadores!\n");
			}

	    return ret;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinKedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
		FILE* pFile;
		char confederacion[21];
		int ret = -1;





		 controller_mostrarConfederaciones(pArrayListSeleccion);

		 while(selec_validarConfederacion(confederacion, pArrayListSeleccion)==-1)
		 {
				getString(confederacion, "Ingrese la Confederacion (Nombre y sus mayusculas): ", "Ingrese la confederacion (Nombre y sus mayusculas): ", 50);

		 }
		printf("Se guardaran los jugadores de la confederacion %s\n",confederacion);
		if(pArrayListJugador != NULL && path!= NULL && ll_len(pArrayListJugador))
		{
			pFile = fopen(path, "wb");

			if(pFile!=NULL)
			{
				 parser_SaveJugadorFromBinary(pFile , pArrayListJugador,  pArrayListSeleccion, confederacion);

			}

			fclose(pFile);
		}



		return ret;
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
	int ret = -1;
	pFile = fopen(path, "r");

		if(path!=NULL && pArrayListSeleccion!=NULL)
		{
			if(pFile!=NULL)
			{
				printf("Abriendo el archivo de selecciones.csv\n\n");
				ret = parser_SeleccionFromText(pFile,  pArrayListSeleccion);

			fclose(pFile);
			pFile = NULL;
			}else
			{
				printf("No se encontro el archivo de selecciones.csv\n");
			}
		}


	return ret;
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
	int ret = -1;
	Seleccion* listaSelecciones=NULL;

	if(pArrayListSeleccion != NULL && ll_len(pArrayListSeleccion)>0)
	{
		printf("%5s %20s %20s %10s\n", "ID", "PAIS", "CONFEDERACION", "CONVOCADOS");
		for(int i=0;i<ll_len(pArrayListSeleccion);i++)
		{
			listaSelecciones=ll_get(pArrayListSeleccion, i);
			 selec_print(listaSelecciones);
		}
		ret = 1;
	}


return ret;
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

	FILE* pFile;

	int ret = -1;


	len = ll_len(pArrayListSeleccion);

		if(path!=NULL && pArrayListSeleccion!=NULL && len>0)
		{
			pFile = fopen(path, "w");

			if(pFile!=NULL)
			{

				 parser_SaveSeleccionFromText(pFile , pArrayListSeleccion);


				fclose(pFile);
				pFile=NULL;
				ret = 1;
			}


		}else
		{
			printf("No se encontro el archivo o no cargo las selecciones\n");
		}

    return ret;
}

int controller_mostrarMenuListar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opcion;
	int lenJugadores = ll_len(pArrayListJugador);
	int lenSelecciones = ll_len(pArrayListSeleccion);
	int ret = -1;

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
			 controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
			 ret = 1;

			}else
			{
				printf("No cargo los jugadores!!!\n");
			}
			break;
		case 2:
			if(lenSelecciones>0)
			{
			 controller_listarSelecciones(pArrayListSeleccion);
			 ret = 1;

			}else
			{
				printf("No cargo las selecciones!!!\n");
			}

		break;
		case 3:
			if(lenJugadores>0)
			{
			controller_listarJugadoresConvocados(pArrayListJugador,  pArrayListSeleccion);
			ret = 1;

			}else
			{
				printf("No cargo los jugadores!!!\n");

			}


		break;
		}



	return ret;


}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
		Jugador* listaJugadores=NULL;
		Seleccion* listaSelecciones=NULL;

		int len;
		int lenSelecciones;
		int idSeleccion;
		int seleccion;
		char paisJugador[21];
		int ret = -1;


		if(pArrayListJugador != NULL)
		{


			len = ll_len(pArrayListJugador);
			lenSelecciones = ll_len(pArrayListSeleccion);
			printf("%s %20s %30s %30s %30s %30s \n", "SELECCION", "ID", "NOMBRE", "POSICION", "NACIONALIDAD", "EDAD" );

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
						selec_getPais(listaSelecciones, paisJugador);

						printf("%s ", paisJugador);
						jug_print(listaJugadores);

					}
				}



			}
			ret = 1;

		}



	return ret;
}


int controller_mostrarMenuConvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opcion;
	int ret = -1;
	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL && ll_len(pArrayListJugador)>0 && ll_len(pArrayListSeleccion)>0)
	{
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
		ret = 1;

	}else
	{
		printf("Hubo un error al cargar los datos!!!\n");
	}

	return ret;
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
	int ret = -1;
	Jugador* unJugador;
	Seleccion* unaSeleccion;

	lenJugadores = ll_len(pArrayListJugador);
	lenSelecciones = ll_len(pArrayListSeleccion);


	controller_listarJugadores(pArrayListJugador,  pArrayListSeleccion);

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

							if(seleccionJugador == 0)
							{
								if(idSeleccion == id)
								{

									if(cantidadConvocados < 22)
									{
										getInt(&confirmar, "Ingrese 1 para confirmar: ", "Ingrese 1 para confirmar: ",1,10000);

										if(confirmar == 1)
										{
										 selec_disminuirConvocados(unaSeleccion,1);
										 jug_setIdSeleccion(unJugador, id);
										 ret = 1;
										 printf("Se acaba de convocar el jugador\n");
										 break;
										}
										break;
									}else
									{
										printf("Esa seleccion ya tiene 22 convocados\n");
										break;
									}

								}else
								if(j == lenJugadores-1)
								{
									printf("No existe esa seleccion o ingreso un ID incorrecto!!\n");
								}
							}else
							{
								printf("Ese jugador ya esta convocado!!!\n");
								break;
							}
							/*if(j == lenSelecciones-1)
							{
								printf("*\nPosibles errores:\n1. No existe esa seleccion\n2. El jugador ya esta convocado o no existe\n3.La seleccion llego al limite de convocados\n*\n");
								break;
							}*/
						}
						break;

					}else
					if(i == lenJugadores-1)
					{
						printf("No existe ese jugador o ingreso un ID incorrecto!!!\n");
						break;
					}


				}

			return ret;

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
	int ret = -1;
	Jugador* unJugador;
	Seleccion* unaSeleccion;

		lenJugadores = ll_len(pArrayListJugador);
		lenSelecciones = ll_len(pArrayListSeleccion);




		if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
		{
			controller_listarJugadores(pArrayListJugador,  pArrayListSeleccion);
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
							 ret = 0;
							 printf("se quito el jugador %d de la seleccion\n",id);
							 break;
							}

							break;
						}else
							if(j == lenSelecciones-1)
						{
								printf("No se encontro la selecion/jugador o el jugador no esta convocado\n");
								break;
						}

					}
					break;
				}else
					if(i==lenJugadores-1)
				{
					printf("No coincide el id ingresado!\n");
					break;
				}



			}
		}else
		{
			printf("Hubo un error!!\n");
		}






				return ret;

}


int controller_mostrarConfederaciones(LinkedList* pArrayListSeleccion)
{
	int ret = -1;
	char confederacion[21];
	char confederacionAnterior[21]= "OFC";
	Seleccion* unaSeleccion;

	if(pArrayListSeleccion!=NULL && ll_len(pArrayListSeleccion)>0)
	{
		for(int i=0;i<ll_len(pArrayListSeleccion);i++)
		{
			unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
			selec_getConfederacion(unaSeleccion, confederacion);

			if(strcmp(confederacion,confederacionAnterior)!=0)
			{
				printf("%s\n",confederacion);
				strcpy(confederacionAnterior,confederacion);
			}
		}
		ret = 1;
	}else
	{
		printf("No cargo las selecciones!!!\n");
	}



	return ret;
}


int controller_validarNacionalidad(LinkedList* pArrayListSeleccion, char* nacionalidadIngresada)
{
	int ret=-1;
	Seleccion* unaSeleccion;
	char pais[41];

		for(int i=0;i<ll_len(pArrayListSeleccion);i++)
		{
			unaSeleccion = ll_get(pArrayListSeleccion, i);
			selec_getPais(unaSeleccion, pais);

			if(strcmp(nacionalidadIngresada, pais)==0)
			{
				ret = 1;
				break;
			}
		}


	return ret;
}
