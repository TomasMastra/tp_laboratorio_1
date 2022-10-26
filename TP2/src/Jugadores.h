/*
 * Jugadores.h
 *
 *  Created on: 25 oct. 2022
 *      Author: Tomas Mastra
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_

typedef struct
{

	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;

}eJugador;

void Jugador_inicializar(eJugador jugador[], int tamJugador);
void Jugador_harcodear(eJugador jugador[], int cantidad);
int Jugador_buscarLibre(eJugador jugador[], int tamJugador);

int Jugador_buscarPorId(eJugador jugador[], int tamJugador, int id);

void Jugador_ordenarPorNombreYConfederacion(eJugador jugador[], int tamJugador);


#endif /* JUGADORES_H_ */
