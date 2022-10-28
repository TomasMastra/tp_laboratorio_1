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

/**
 * @fn Jugador_inicializar(eJugador, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array

 * @return void
 */
void Jugador_inicializar(eJugador jugador[], int tamJugador);

/**
 * @fn Jugador_harcodear(eJugador, int) harcodea algunos jugadores
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @return void
 */
void Jugador_harcodear(eJugador jugador[], int cantidad);

/**
 * @fn Jugador_buscarLibre(eJugador, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @return primera posicion libre que encuentre
 */
int Jugador_buscarLibre(eJugador jugador[], int tamJugador);

/**
 * @fn Jugador_buscarPorId(eJugador, int ,int) busca la posicion de un jugador
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param int id: id del jugador al que queremos obtener su posicion
 * @return posicion del jugador
 */
int Jugador_buscarPorId(eJugador jugador[], int tamJugador, int id);

/**
 * @fn Jugador_ordenarPorNombreYConfederacion(eJugador, int ,eConfederacion, int, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @return void
 */
void Jugador_ordenarPorNombreYConfederacion(eJugador jugador[], int tamJugador);


#endif /* JUGADORES_H_ */
