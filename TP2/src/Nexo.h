/*
 * Nexo.h
 *
 *  Created on: 24 oct. 2022
 *      Author: Tomas Mastra
 */

#ifndef NEXO_H_
#define NEXO_H_

/**
 * @fn Jugador_agregar(eJugador, int ,eConfederacion, int, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @param int id el id que se le asigna al nuevo jugador
 * @return 1 si se agrego y 0 si no se agrego
 */
int Jugador_agregar(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int id);

/**
 * @fn pedirConfederacion(eJugador ,eConfederacion, int, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @param int index posicion del array jugador en la que se guardara la confederacion
 * @return void
 */
void pedirConfederacion(eJugador jugador[], eConfederacion confederacion[], int tamConfederacion, int index);


/**
 * @fn eliminarJugador(eJugador, int ,eConfederacion, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return 1 si se elimino y -1 si no se elimino el jugador
 */
int eliminarJugador(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion);

/**
 * @fn modificarJugador(eJugador, int ,eConfederacion, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return index, la posicion
 */
int modificarJugador(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion);

/**
 * @fn mostrarMenuModificar(eJugador, int ,eConfederacion, int, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @param int index
 * @return 1 si se modifico y -1 si no se modifico el jugador
 */
int mostrarMenuModificar(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int index);


/**
 * @fn listarJugador_Confederacion(eJugador ,eConfederacion)
 * @brief
 *
 * @param eJugador elemento de los jugadores
 * @param eConfederacion  elemento de la  confederacion
 * @return void
 */
void listarJugador_Confederacion(eJugador jugador, eConfederacion confederacion);

/**
 * @fn listarJugadores_Confederacion(eJugador, int ,eConfederacion, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return void
 */
void listarJugadores_Confederacion(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion);

/**
 * @fn compararJugador_Confederacion(eJugador, int ,eConfederacion, int, int)
 * @brief
 *
 * @param eJugador el jugador que usamos para comparar con la confederacion
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return j posicion de la confederacion
 */
int compararJugador_Confederacion(eConfederacion confederacion[], int tamConfederacion, eJugador jugador);


/**
 * @fn mostrarSubMenu(eJugador, int ,eConfederacion, int, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @param int cantidadJugadores
 * @return void
 */
void mostrarSubmenu(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int cantidadJugadores);

/**
 * @fn listarConfederacionesConSusJugadores(eJugador, int ,eConfederacion, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return void
 */
void listarConfederacionesConSusJugadores(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion);

/**
 * @fn calcularPromedioSalario(eJugador, int ,eConfederacion, int, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @param int cantidadJugadores
 * @return void
 */
void calcularPromedioSalario(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int cantidadJugadores);

/**
 * @fn mostrarJugadoresPromedio(eJugador, int ,eConfederacion, int, float)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @param float promedio es el promedio que se usa para mostrar los jugadores que lo superan
 * @return void
 */
void mostrarJugadoresMasPromedio(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, float promedio);

/**
 * @fn calcularMasAniosContrato(eJugador, int ,eConfederacion, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return void
 */
void calcularMasAniosContrato(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion);

/**
 * @fn calcularPorcentajeConfederacion(eJugador, int ,eConfederacion, int, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @param int jugadores: la cantidad de jugadores cargados
 * @return void
 */
void calcularPorcentajeConfederacion(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int jugadores);

/**
 * @fn calcularCantidadConfederacion(eJugador, int ,eConfederacion)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @return cantidad de jugadores que pertenecen a esa confederacion
 */
int calcularCantidadConfederacion(eJugador jugador[], int tamJugador, eConfederacion confederacion);

/**
 * @fn informarRegionMasJugadores(eJugador, int ,eConfederacion, int)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @return void
 */
void informarRegionMasJugadores(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion);

/**
 * @fn mostrarMenuModificar(eJugador, int ,eConfederacion, int, int) muestra los jugadores de la confederacion que le pasamos por parametro (el id)
 * @brief
 *
 * @param eJugador array de jugador
 * @param int tamJugador tamaño del array
 * @param eConfederacion array de confederacion
 * @param int tamConfederacion tamaño del array
 * @param int idConfederacion: id utilizado para validar que el jugador pertenezca solo a la confederacion esa, compara ambos id
 * @return void
 */
void listarJugadoresDeUnaConfederacion(eJugador jugador[], int tamJugador, eConfederacion confederacion[], int tamConfederacion, int idConfederacion);

#endif /* NEXO_H_ */
