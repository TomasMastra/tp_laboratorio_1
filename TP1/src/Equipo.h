/*
 * Equipo.h
 *
 *  Created on: 13 sep. 2022
 *      Author: Tomas Mastra
 */

#ifndef EQUIPO_H_
#define EQUIPO_H_

typedef struct
{
	int numero;
	char posicion[21];
	char confederacion[21];
	int idConfederacion;


	int isEmpty;

}sEquipo;

typedef struct
{
	int arqueros;
	int mediocampistas;
	int delanteros;
	int defensores;

}sCantidad;

typedef struct
{
	int hospedaje;
	int comida;
	int transporte;



}sCostos;

int inicializarEquipo(sEquipo equipo[], int tamEquipo);
int inicializarCantidadYCosto(int cantidadPosicion[], int costoMantenimiento[]);
int ingresarCostos(float* costoHospedaje, float* costoComida, float* costoTransporte);
int buscarLibre(sEquipo equipo[], int tamEquipo);
int cargarJugadores(sEquipo equipo[], int tamEquipo, int cantidadPosicion[]);
int pedirPosicion(sEquipo equipo[], int tamEquipo, int index, int cantidadPosicion[]);
int pedirConfederacion(sEquipo equipo[], int tamEquipo, int index);
int calcularCantidad(sEquipo equipo[], int index, int cantidadPosicion[], int option);
int validarPosicion(sEquipo equipo[], int tamEquipo, int cantidadPosicion[], int index, int option);
int validarConfederacion(sEquipo equipo[], int tamEquipo, int index, int option);

void mostrarJugador(sEquipo equipo[], int index);

int calcularPromedioJugadores(sEquipo equipo[], int tamEquipo, float* promedioConmebol, float* promedioAfc,  float* promedioCaf, float* promedioConcacaf,float* promedioUefa,float* promedioOfc);
int mostrarDatos(float promedioConmebol, float promedioAfc,  float promedioCaf, float promedioConcacaf,float promedioUefa,float promedioOfc, int aumento, float mantenimiento);


#endif /* EQUIPO_H_ */
