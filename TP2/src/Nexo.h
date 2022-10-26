/*
 * Nexo.h
 *
 *  Created on: 24 oct. 2022
 *      Author: Tomas Mastra
 */

#ifndef NEXO_H_
#define NEXO_H_


int Jugador_agregar(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int id);
int pedirConfederacion(eJugador jugador[], eConfederacion confederacion[], int tamConfederacion, int index);

int eliminarJugador(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion);
int modificarJugador(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion);
int mostrarMenuModificar(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int index);

void listarJugador_Confederacion(eJugador jugador, eConfederacion confederacion);
void listarJugadores_Confederacion(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion);
int compararJugador_Confederacion(eConfederacion confederacion[], int tamConfederacion, eJugador jugador);

void mostrarSubmenu(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int cantidadJugadores);

void listarConfederacionesConSusJugadores(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion);

void calcularPromedioSalario(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int cantidadJugadores);
void mostrarJugadoresMasPromedio(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, float promedio);

void calcularMasAniosContrato(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion);

void calcularPorcentajeConfederacion(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int jugadores);

int calcularCantidadConfederacion(eJugador jugador[], int tamJugador, eConfederacion confederacion);



#endif /* NEXO_H_ */
