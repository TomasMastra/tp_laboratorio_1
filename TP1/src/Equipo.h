/*
 * Equipo.h
 *
 *  Created on: 13 sep. 2022
 *      Author: Tomas Mastra
 */

#ifndef EQUIPO_H_
#define EQUIPO_H_



int inicializarCantidadYCosto(int cantidadPosicion[], int cantidadConfederacion[]);//
int ingresarCostos(float* costoHospedaje, float* costoComida, float* costoTransporte);//
int cargarJugadores(int* cantidadJugadores, int cantidadPosicion[],int cantidadConfederacion[]);//
int pedirPosicion(int cantidadPosicion[]);//
int pedirConfederacion(int cantidadConfederacion[]);//
int calcularCantidad(int cantidadPosicion[], int option);//
int validarPosicion(int cantidadPosicion[],int option);//
int validarConfederacion(int cantidadConfederacion[],int option);//


int calcularPromedioJugadores(int cantidadConfederacion[], float* promedioConmebol, float* promedioAfc,  float* promedioCaf, float* promedioConcacaf,float* promedioUefa,float* promedioOfc);
int calcularMantenimiento(float* mantenimiento, float costoHospedaje, float costoComida, float costoTransporte, int aumento, float* aumentoEuropa);
int mostrarDatos(float promedioConmebol, float promedioAfc,  float promedioCaf, float promedioConcacaf,float promedioUefa,float promedioOfc, int aumento, float mantenimiento, float aumentoEuropa);


#endif /* EQUIPO_H_ */
