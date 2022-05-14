/*
 * ArrayPassenger.h
 *
 *  Created on: 26 abr. 2022
 *      Author: Tomas Mastra
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10]; //codigo de vuelo alfanumerico
	int typePassenger;  //tipo de pasajero
	int statusFlight;
	int isEmpty;


}Passenger;


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger[]
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger list[], int len);      //


/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger[]
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassengers(Passenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight);      //


/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger[]
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger list[], int len,int id);


/** \brief Remove a Passenger by Id (put isEmpty Flag in -1)
*
* \param list Passenger[]
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger list[], int len, int id);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger[]
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger list[], int len, int order);

/** \brief print the content of passengers array
*
* \param list Passenger[]
* \param length int
* \return int
*
*/
int printPassengers(Passenger list[], int length);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger[]
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
*/
int sortPassengersByCode(Passenger list[], int len, int order);

/** \brief print the content of passengers array
*
* \param list Passenger
* \return void
*
*/
void printPassenger(Passenger list);


/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger[]
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int modifyPassengers(Passenger list[], int len);

/** \brief ask for the information of the passenger
*
* \param list Passenger[]
* \param length int
* \param id int
* \return int
*/
int askPassengers(Passenger list[], int len, int id);

/** \brief confirm if you want to add the passenger
*
* \param message* char
* \return int
*
*/
int confirmPassengers(char *message);

/** \brief looks for an empty space and returns the index if not found returns -1
*
* \param list passenger[]
* \param len int
* \return int
*
*/
int searchEmptyPassenger(Passenger list[], int len);

/** \brief print a submenu with more options
*
* \param list Passenger
* \param len int
* \return void
*
*/
int printSubMenu(Passenger list[], int len);

/** \brief Calculate the average of all the prices, print the sum of the prices and the average
*
* \param list Passenger
* \param len int
* \return void
*
*/
float calculateAverage(Passenger list[], int len);

/** \brief receive the average of the price and print passengers with higher than average price
*
* \param list Passenger
* \param len int
* \return void
*
*/
int printAverage(Passenger list[], int len);

int validatePassengers(Passenger list[], int len);

int pintPassengerStatusFlight(Passenger list[], int len);

#endif /* ARRAYPASSENGER_H_ */
