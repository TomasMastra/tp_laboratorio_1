/*
 * Equipo.h
 *
 *  Created on: 13 sep. 2022
 *      Author: Tomas Mastra
 */

#ifndef EQUIPO_H_
#define EQUIPO_H_






/**
 * @brief recive el costo de mantenimiento en cada sector (hospedaje, comida y transporte)
 *
 * @param float* costoHospedaje
 * @param float* costoComida
 * @param float* costoTransporte
 * @return ret 1 si salio bien y -1 su hubo un error
 */
int ingresarCostos(float* costoHospedaje, float* costoComida, float* costoTransporte);//

/**
 * @brief pide el ingreso de datos al usuario en su respectiva funcion con su validacion
 *
 * @param int cantidadJugadores: total de jugadores
 * @param int cantidadPosicion[] : Cantidad de jugadores que estan en una posicion para poder sumarle 1 en la posicion en la que se ingresa el jugador
 * @param int cantidadConfederacion[] : Cantidad de jugadores que estan en una confederacion para poder sumarle 1 en la confederacion en la que se ingresa el jugador
 * @param
 *
 * @return ret 1 si salio bien y -1 su hubo un error
 */
int cargarJugadores(int* cantidadJugadores, int cantidadPosicion[],int cantidadConfederacion[]);//


/**
 * @brief pide el ingreso de la posicion del jugador
 *
 * @param int cantidadPosicion[] : Cantidad de jugadores que estan en una posicion para poder sumarle 1 en la posicion en la que se ingresa el jugador
 *
 * @return ret 1 si salio bien
 */
int pedirPosicion(int *cantidadArqueros, int *cantidadDefensores, int *cantidadDelanteros, int *cantidadMediocampistas);//

/**
 * @brief pide el ingreso de la confederacion del jugador
 *
 * @param int cantidadConfederacion[] : Cantidad de jugadores que estan en una confederacion para poder sumarle 1 en la posicion en la que se ingresa el jugador
 *
 * @return ret 1 si salio bien
 */
int pedirConfederacion(int *cantidadConcacaf, int *cantidadConmebol, int *cantidadUefa, int *cantidadCaf, int *cantidadAfc, int *cantidadOfc);//


int pedirNumero();


/**
 * @brief se le pasa la posicion del jugador y se le suma +1 a cantidadPosicion (si es aruqero se le suma +1 al arquero)
 *
 * @param int cantidadPosicion[] : Cantidad de jugadores que estan en una posicion para poder sumarle 1 en la posicion en la que se ingresa el jugador
 * @param int opcion : Posicion que ingreso el jugador para poder entrar al switch
 *
 * @return ret 1 si salio bien y -1 su hubo un error
 */
int calcularCantidad(int* cantidadArquero, int* cantidadDefensor, int* cantidadDelantero, int* cantidadMediocampista, int opcion);//

/**
 * @brief recive la cantidad de cada posicion y la posicion ingresada
 *
 * @param int cantidadPosicion[] : Cantidad de jugadores que estan en una posicion para poder validar que no supere el limite de esa misma posicion (Por ejemplo el limite de arqueros es de 2)
 * @param int opcion: posicion del jugador que se acaba de ingresar
 *
 * @return ret 1 si salio bien y -1 su hubo un error
 */
int validarPosicion(int* cantidadArqueros,int* cantidadDefensores, int* cantidadDelanteros, int* cantidadMediocampistas,int opcion);//

/**
 * @brief recive la cantidad de jugadores ingresados de cada confederacion y la confederacion ingresada
 *
 * @param int cantidadPosicion[] : Cantidad de jugadores que estan en una confederacion para poder sumarle 1 en la confederacion en que ingrese el jugador
 * @param int opcion: la confederacion ingresada
 *
 * @return ret 1 si salio bien y -1 su hubo un error
 */
int validarConfederacion(int* cantidadAfc, int* cantidadUefa,int* cantidadCaf, int* cantidadOfc, int* cantidadConmebol, int* cantidadConcacaf, int opcion);//


/**
 * @brief recive el promedio y devuelve por referencia el promedio de cada confederacion
 *

 * @param int cantidadConfederacion[]
 * @param float* promedioConmebol
 * @param float* promedioAfc
 * @param float* promedioCaf
 * @param float* promedioConcacaf
 * @param float* promedioUefa
 * @param float* promedioOfc
 *
 * @return ret 1 si la mayoria es de Europa, -1 si no se cumple
 */
int calcularPromedioJugadores(int cantidadConcacaf, int cantidadConmebol, int cantidadUefa, int cantidadAfc, int cantidadCaf, int cantidadOfc, float* promedioConmebol, float* promedioAfc,  float* promedioCaf, float* promedioConcacaf, float* promedioUefa, float* promedioOfc);

/**
 * @brief recive el costo de mantenimiento y los suma
 *
 * @param float* mantenimiento: suma de los 3 costos
 * @param float costoHospedaje
 * @param float costoComida
 * @param float costoTransporte
 * @param int aumento : 1 si es de Europa y -1 si no lo es
 * @param float* aumentoEuropa: el mantenimiento si la mayoria es de Europa
 *
 * @return ret 1 si la mayoria es de Europa, -1 si no se cumple
 */
int calcularMantenimiento(float* mantenimiento, float costoHospedaje, float costoComida, float costoTransporte, int aumento, float* aumentoEuropa);

/**
 * @brief recive el promedio de jugadores de cada confederacion, el total del mantenimiento y el mantenimiento en caso de que sea la mayoria de Europa
 *
 * @param float promedioConmebol: promedio de jugadores que juegan en Conmebol
 * @param float promedioAfc: promedio de jugadores que juegan en Afc
 * @param float promedioCaf: promedio de jugadores que juegan en Caf
 * @param float promedioConcacaf: promedio de jugadores que juegan en Concacaf
 * @param float promedioUefa: promedio de jugadores que juegan en Uefa
 * @param float promedioOfc: promedio de jugadores que juegan en Ofc
 * @param int aumento: si es 1 muestra el aumento del 35%
 * @param float mantenimiento: suma de los 3 costos (hospedaje, comida y transporte)
 * @param float aumentoEuropa: costo de mantenimiento con el aumento del 35%
 *
 * @return ret 1 si entro en la funcion
 */
int mostrarDatos(float promedioConmebol, float promedioAfc,  float promedioCaf, float promedioConcacaf,float promedioUefa,float promedioOfc, int aumento, float mantenimiento, float aumentoEuropa);


#endif /* EQUIPO_H_ */
