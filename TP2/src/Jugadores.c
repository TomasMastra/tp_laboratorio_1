/*
 * Jugadores.c
 *
 *  Created on: 25 oct. 2022
 *      Author: Tomas Mastra
 */


/*
 * Jugadores.c
 *
 *  Created on: 22 oct. 2022
 *      Author: Tomas Mastra
 */

#ifndef JUGADORES_C_
#define JUGADORES_C_
#include <string.h>

#include "Jugadores.h"
#include "Funciones.h"



void Jugador_inicializar(eJugador jugador[], int tamJugador)
{

	for(int i=0;i<tamJugador;i++)
	{
		jugador[i].isEmpty = -1;
	}

}


void Jugador_harcodear(eJugador jugador[], int cantidad)
{

	eJugador auxJugador[6] = {{1994, "Lionel Messi", "Delantero", 10, 4, 90000000, 6, 1}, {1995, "Kylian Mbappe", "Delantero", 7, 6, 70000000, 4, 1},{1996, "Cristiano Ronaldo", "Delantero", 7, 6, 80000000, 3, 1},{1997, "Keylor Navas", "Arquero", 1, 3, 45000000, 1, 1},{1998, "Nicolas Otamendi", "Defensor", 30, 4, 20000000, 2, 1}, {1999, "Shinji Kagawa", "Mediocampista", 7, 1, 10000000, 4, 1}};

	for(int i=0;i<6;i++)
	{
		jugador[i] = auxJugador[i];
	}


}

int Jugador_buscarPorId(eJugador jugador[], int tamJugador, int id)
{
	int ret = -1;

	for(int i=0;i<tamJugador; i++)
	{
		if(jugador[i].id == id)
		{
			ret = i;
			break;
		}
	}



			return ret;


}


int Jugador_buscarLibre(eJugador jugador[], int tamJugador)
{
	int ret = -1;

	int i;

	for(i=0;i<tamJugador;i++)
	{
		if(jugador[i].isEmpty==-1)
		{
			ret=i;
			break;
		}
	}

	return ret;
}

void Jugador_ordenarPorNombreYConfederacion(eJugador jugador[], int tamJugador)
{
	int i;
	int j;
	eJugador auxJugador;


		for(i=0; i<tamJugador-1; i++)
		{
			for(j=i+1; j<tamJugador; j++)
			{
				if(jugador[i].idConfederacion > jugador[j].idConfederacion)
				{
					auxJugador = jugador[i];
					jugador[i] = jugador[j];
					jugador[j] = auxJugador;
				}else
					if(jugador[i].idConfederacion == jugador[j].idConfederacion)
					{
						if(strcmp(jugador[i].nombre, jugador[j].nombre)==1)
						{
							auxJugador = jugador[i];
							jugador[i] = jugador[j];
							jugador[j] = auxJugador;
						}
					}

			}
		}



}

#endif /* JUGADORES_C_ */
