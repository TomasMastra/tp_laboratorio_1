/*
 * Input.h
 *
 *  Created on: 6 jun. 2022
 *      Author: Tomas Mastra
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>   //MASTRAPASQUA TOMAS B
#include <string.h>
#include <stdlib.h>
#include <ctype.h>





/**
 * @fn int getInt(int*, char*, char*, int, int)
 * @brief
 *
 * @param integer recive un puntero a un int
 * @param message recive un mensaje para mostrar
 * @param messageError recive un mensaje de error para mostrar
 * @param min recive un numero indicando el valor minimo
 * @param max recive un numero indicando el valor maximo
 * @return ret 0 si salio bien o -1 si salio mal
 */
int getInt(int* integer, char* message, char* messageError, int min, int max);

/**
 * @fn int getFloat(float*, char*, char*, int, int)
 * @brief
 *
 * @param floating recive un puntero a un float
 * @param message recive un mensaje para mostrar
 * @param messageError recive un mensaje de error para mostrar
 * @param min recive un numero indicando el valor minimo
 * @param max recive un numero indicando el valor maximo
 * @return ret 0 si salio bien o -1 si salio mal
 */
int getFloat(float* floating, char* message, char* messageError, int min, int max);

/**
 * @fn int getInt(char*, char*, char*, int)
 * @brief
 *
 * @param string recive un puntero a un char
 * @param message recive un mensaje para mostrar
 * @param messageError recive un mensaje de error para mostrar
 * @param min recive un numero indicando el tamaño maximo para el string
 * @return ret 0 si salio bien o -1 si salio mal
 */
int getString(char* string, char* message, char* messageError, int max);

/**
 * @fn int getInt(char*, char*)
 * @brief
 *
 * @param character recive un puntero a un char
 * @param message recive un mensaje para mostrar
 * @return ret 0 si salio bien o -1 si salio mal
 */
int getChar(char* character, char* message);

/**
 * @fn int getInt(char*)
 * @brief
 *
 * @param string recive un puntero a un char, lo cual deberia devolver el string con la primer letra mayuscula y el resto minuscula
 * @return ret 0 si salio bien o -1 si salio mal
 */
int tolowerString(char* string);

/**
 * @fn int getInt(char*)
 * @brief
 *
 * @param string recive un puntero a un char y determina si alguna de sus letras no es una letra minuscula, mayuscula o un espacio
 * @return ret 0 si salio bien o -1 si salio mal
 */
int validateLetters(char* string);

/**
 * @fn int validateInt(char*)
 * @brief determina si se ingreso un numero
 *
 * @param integer recive un puntero a un char
 * @return ret 0 si salio bien o -1 si salio mal
 */
int validateInt(char* integer);




int getName(char *string, char *message, char *messageError, int max);

int isValidFecha(int dia, int mes, int anio);



#endif /* FUNCIONES_H_ */
