/*
 * Input.h
 *
 *  Created on: 26 abr. 2022
 *      Author: Tomas Mastra
 */

#ifndef INPUT_H_
#define INPUT_H_

/** \brief receive a pointer int
*
* \param integer int*
* \param char message*
* \param char messageError*
* \param int min
* \param int max
* \return void
*
*/
int getInt(int* integer, char* message, char* messageError, int min, int max);

/** \brief receive a pointer float
*
* \param floating float*
* \param char message*
* \param char messageError*
* \param int min
* \param int max
* \return void
*
*/
int getFloat(float* floating, char* message, char* messageError, int min, int max);

/** \brief receive a pointer char (string)
*
* \param char string*
* \param char message*
* \param char messageError*
* \param int min
* \param int max
* \return void
*
*/
int getString(char* string, char* message, char* messageError, int max);

/** \brief receive a pointer char
*
* \param char character*
* \param char message*
* \return void
*
*/
int getChar(char* character, char* message);

/** \brief Put the first letter of the string in a capital letter and the rest in lower case
*
* \param char string*
* \return void
*
*/
int tolowerString(char* string);

/** \brief validate if the string has a symbol or a number
*
* \param char string*
* \return void
*
*/
int validateLetters(char *string);

/** \brief receive a pointer num
*
* \param string char*
* \param char message*
* \param char messageError*
* \param int max
* \return void
*
*/
int getName(char *string, char *message, char *messageError, int max);


#endif /* INPUT_H_ */
