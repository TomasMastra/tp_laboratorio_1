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

int initPassengers(Passenger list[], int len);      //

int addPassengers(Passenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);      //

int findPassengerById(Passenger list[], int len,int id);

int removePassenger(Passenger list[], int len, int id);

int sortPassengers(Passenger list[], int len, int order);

int printPassengers(Passenger list[], int length);

int sortPassengersByCode(Passenger list[], int len, int order);


void printPassenger(Passenger list);

int modifyPassengers(Passenger list[], int len);

int askPassengers(Passenger list[], int len, int id);

int confirmPassengers(char *message);

int searchEmptyPassenger(Passenger list[], int len);

int printSubMenu(Passenger list[], int len);

float calculateAverage(Passenger list[], int len);

int printAverage(Passenger list[], int len);

#endif /* ARRAYPASSENGER_H_ */
