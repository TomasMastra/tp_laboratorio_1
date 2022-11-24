#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Funciones.h"


//Mastrapasqua Tomas D
int main()
{
	setbuf(stdout,NULL);
    int opcion = 0;
    int banderaJugador=0;
    int banderaSeleccion = 0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();




    puts("funciona ok");




    do{

   		 getInt(&opcion,  "**************************************\n"
   		 								"MENU\n"
   		 								"**************************************\n"
   				 	 	 	 	 	 	"1. Cargar los datos de los Jugadores y selecciones desde el archivo data.csv (modo texto)\n"
										"2. Alta Jugador\n"
										"3. Modificar Jugador\n"
										"4. Eliminar Jugador\n"
										"5. Listar\n"
										"6. Convocar\n"
										"7. Ordenar Jugadores\n"
										"8. Guardar jugadores convocados de una confederacion ingresada (modo texto)\n"
										"9. Cargar jugadores convocados (modo binario)\n"
										"10. Guardar jugadores y selecciones (modo texto)\n"
   				 	 	 	 	 	 	"11. Salir\n"
   		 								"**************************************\n"
   		 								"Ingrese una opcion: ",

   		 								"**************************************\n"
   		 								"MENU\n"
   		 								"**************************************\n"
   		 								"1. Cargar los datos de los Jugadores y selecciones desde el archivo data.csv (modo texto)\n"
   		 								"2. Alta Jugador\n"
   		 								"3. Modificar Jugador\n"
   		 								"4. Eliminar Jugador\n"
   		 								"5. Listar\n"
   		 								"6. Convocar\n"
   		 								"7. Ordenar Jugadores\n"
   		 								"8. Guardar jugadores convocados de una confederacion ingresada (modo texto)\n"
   		 								"9. Cargar jugadores convocados (modo binario)\n"
   		 								"10. Guardar jugadores y selecciones (modo texto)\n"
										"11. Salir\n"
   		 								"**************************************\n"
   		 								"Opcion invalida, reingrese: ", 1, 11);


   		 switch(opcion)
   		 {

   		 case 1:

		 if(banderaSeleccion == 0 || banderaJugador == 0)
		 {
			 banderaJugador = controller_cargarJugadoresDesdeTexto("jugadores.csv" , listaJugadores);
			 banderaSeleccion = controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);
		 }else
		 {
			 printf("Ya cargo los archivos!!!\n\n");
		 }



   			 break;

   		 case 2:

   			 if(banderaJugador==1)
   			 {

   				 controller_agregarJugador(listaJugadores, listaSelecciones);
   			 }else
   			 {
   				 printf("Agregue un jugador!!!\n");
   			 }


   			 break;
   		 case 3:

   			 if(banderaJugador==1)
   			 {

   		 controller_editarJugador(listaJugadores, listaSelecciones);
   			 }else
   			 {
   				 printf("Agregue un jugador!!!\n");
   			 }


   			 break;
   		 case 4:

   			 if(banderaJugador == 1)
   			 {
   			 controller_removerJugador(listaJugadores, listaSelecciones);
   			 }else
   			 {
   				 printf("Agregue un jugador!!!\n");
   			 }



   			 break;

   		 case 5:

   			 if(banderaJugador == 1 && banderaSeleccion == 1)
   			 {
   			 controller_mostrarMenuListar(listaJugadores, listaSelecciones);
   			 }else
   			 {
   				 printf("No cargo los jugadores y selecciones!!!\n");
   			 }


   			 break;




   		 case 6:

   			 if(banderaSeleccion == 1 || banderaJugador == 1)
   			 {
   			 controller_mostrarMenuConvocar(listaJugadores,listaSelecciones);

   			 }else
   			 {
   				 printf("Cargue los jugadores y selecciones para poder convocar!!!\n");
   			 }



   			 break;

   		 case 7:

   			 if(banderaJugador==1 && banderaSeleccion==1)
   			 {
   			 controller_ordenarJugadores(listaJugadores, listaSelecciones);
   			 }else
   			 {
   				 printf("Cargue los jugadores para poder ordenar!!!\n");
   			 }



   			 break;

   		 case 8:
   			 if(banderaJugador == 1)
   			 {
   			   controller_guardarJugadoresModoBinario("jugadoresConvocados.bin", listaJugadores, listaSelecciones);
   			 }else
   			 {
   				 printf("Cargue los jugadores!!!\n");
   			 }


   			 break;



   		 case 9:

   			 if(banderaJugador == 0 && banderaSeleccion == 0)
   			 {
   			 banderaJugador=controller_cargarJugadoresDesdeBinario("jugadoresConvocados.bin", listaJugadores);
			 banderaSeleccion = controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);


   			 }else
   			 {
   				 printf("Ya cargo los jugadores y selecciones!!!\n");
   			 }




   			 break;

   		 case 10:
   			 if(banderaSeleccion == 1 || banderaJugador == 1)
   			 {
   			 controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
   			 controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones);
   			 }else
   			 {
   				 printf("Cargue los jugadores para poder guardar!!!\n");
   			 }



   			 break;

   		 case 11:

   			 getInt(&opcion, "Queres salir? (0 = si)", "Queres salir? (0 = si)", 0, 20000);
   			 if(opcion==0)
   			 {
   				 opcion = 12;

   				 printf("Saliendo...\n");
   			 }




   			 break;
   		 }

   	 }while(opcion!=12);



   /* do{
        switch(option)
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);

                break;
        }
    }while(option != 10);*/




    return 0;
}

