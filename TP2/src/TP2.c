/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"
#include "Jugadores.h"
#include "Confederaciones.h"
#include "Nexo.h"

//Mastrapasqua Tomas D

int main(void) {

	setbuf(stdout, NULL);
	int opcion;
	//int banderaAltaJugador=0;
	int id = 2000;
	int jugadores = 0;

	int tamConfederacion = 6;
	eConfederacion confederacion[tamConfederacion];

	int tamJugador = 3000;
	eJugador jugador[tamJugador];

	 harcodearConfederacion(confederacion,  tamConfederacion);
	 Jugador_inicializar(jugador, tamJugador);
	 Jugador_harcodear(jugador,  6);
	 jugadores = 6;


	 do{
		 printf("Jugadores: %d\n" ,jugadores);

		 getInt(&opcion, "-------------------------------------\n"
		 		 	    								 "1. ALTA JUGADOR\n"
		 		 	    								 "2. BAJA JUGADOR\n"
		 		 	    								 "3. MODIFICAR JUGADOR\n"
		 		 	    								 "4. INFORMES\n"
				 	 	 	 	 	 	 	 	 	 	 "5. SALIR\n"
		 		 	    								 "-------------------------------------\n"
		 		 	    								 "Ingrese una opcion: ",
		 		 	    								 "-------------------------------------\n"
		 												 "1. ALTA JUGADOR\n"
		 												 "2. BAJA JUGADOR\n"
		 												 "3. MODIFICAR JUGADOR\n"
		 												 "4. INFORMES\n"
														 "5. SALIR\n"
		 		 	    								 "-------------------------------------\n"
		 		 	    								 "ERROR, Ingrese una opcion: ", 1, 5);



		 switch(opcion)
		 {

			case 1:

			if(Jugador_agregar(jugador,  tamJugador,  confederacion, tamConfederacion, id)==1)
			{
			id++;
			jugadores++;
			}

			break;
			case 2:
				if(jugadores > 0)
				{
				 if(eliminarJugador(jugador, tamJugador,  confederacion,  tamConfederacion) == 1)
				 {
					 jugadores--;
					 printf("Hola\n");
				 }



				}else
				{
					printf("Actualmente hay %d jugadores, debe ingresar uno!!!\n", jugadores);
				}

			break;
			case 3:

			if(jugadores > 0)
			{
				 modificarJugador(jugador,  tamJugador,  confederacion,  tamConfederacion);

			}else
			{
				printf("Actualmente hay %d jugadores, debe ingresar uno!!!\n", jugadores);
			}


			break;
			case 4:


			if(jugadores > 0)
			{
				 mostrarSubmenu(jugador,  tamJugador, confederacion,  tamConfederacion, jugadores);

			}else
			{
				printf("Actualmente hay %d jugadores, debe ingresar uno!!!\n", jugadores);
			}



			break;
			case 5:
				printf("Saliendo...\n");
			break;
		 }



	 }while(opcion!=5);





	return EXIT_SUCCESS;

}
