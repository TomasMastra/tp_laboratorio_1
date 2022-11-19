/*
 * Input.c
 *
 *  Created on: 6 jun. 2022
 *      Author: Tomas Mastra
 */

#ifndef FUNCIONES_C_
#define FUNCIONES_C_
#include <stdio.h>   //MASTRAPASQUA TOMAS B
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Funciones.h"

int getInt(int* integer, char* message, char* messageError, int min, int max)
{
	int ret = -1;
	char number[21];
	int auxNumber;

	if(integer != NULL && message != NULL && messageError != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%s", number);
		auxNumber = atoi(number);

		//printf("number: %d\n", auxNumber);
		while(!validateInt(number) || (auxNumber < min || auxNumber > max))
		{
// (!isNumber(numAux) && !validateSpace(message)) || (numIntAux>max||numIntAux<min)

			//printf("HOLA?????\n");
			printf("%s", messageError);
			fflush(stdin);
			scanf("%s", number);
			auxNumber = atoi(number);


		}

		*integer=auxNumber;
		//*integer = number;
		ret = 0;
	}

	return ret;
}

int validateInt(char* integer)
{
	int ret;
	int len;
	char validateCaps[256];

	ret = -1;

	len = strlen(integer);


			for(int i=0;i<len;i++)
			{

				validateCaps[i] = tolower(integer[i]);

				if(validateCaps[i] < 48  ||  validateCaps[i]>57)
				{
					ret = 0;

				}else
				{


				}

			}

		return ret;
}


int getFloat(float* floating, char* message, char* messageError, int min, int max)
{
	int ret = -1;
	char number[21];
	int auxNumber;

		if(floating != NULL && message != NULL && messageError != NULL && min < max)
		{
			printf("%s", message);
			fflush(stdin);
			scanf("%s", number);
			auxNumber = atoi(number);

			while((auxNumber < min || auxNumber > max) && (validateInt(number)==0))
			{
				printf("%s", messageError);
				fflush(stdin);
				scanf("%s", number);
				auxNumber = atoi(number);

			}

			*floating=auxNumber;
			ret = 0;
		}

		return ret;
}

int getString(char* string, char* message, char* messageError, int max)
{
	int ret = -1;
	char buffer[256];
	int len;

	int i;

	if(string != NULL && message != NULL && messageError != NULL && max > 0)
	{



		printf("%s", message);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		len = strlen(buffer);
		for(i=0;i<len;i++)
		{

			while(len>max)
			{
				printf("%s", messageError);
				fflush(stdin);
				//__fpurge(stdin);
				scanf("%[^\n]", buffer);

				len = strlen(buffer);

			}
		}

		strcpy(string, buffer);



		ret = 0;
	}



	return ret;
}



int getName(char *string, char *message, char *messageError, int max) // La diferencia es que getString es Alfanumerico y esta solo para pedir nombres (solo letras y que empieze por mayuscula)
{
	int ret;
	char buffer[51];
	int validarLetras;
	ret = 0;

	 getString(buffer, message, messageError, max);

	 validarLetras = validateLetters(buffer);

	 while(validarLetras == 0)
	 {
		 printf("ERROR, ");
		 getString(buffer, message, messageError, max);
		 validarLetras = validateLetters(buffer);

	 }


	 tolowerString(buffer);
	strcpy(string, buffer);



	return ret;



}


int tolowerString(char* string)
{

	int ret = -1;
	int i;
	char buffer[21];

	strcpy(buffer, string);


	for(i=0; buffer[i]!='\0' ; i++)
	{

        buffer[i] = tolower(buffer[i]);
        ret = 0;

        if(buffer[i-1] == 32 )
        {
        	buffer[i]= toupper(buffer[i]);
        	printf("%c",buffer[i]);

        }

	}
	buffer[0] = toupper(buffer[0]);
	//buffer[index] = toupper(buffer[index]);


	strcpy(string, buffer);

	return ret;
}



int validateLetters(char *string)
{
	int ret;
	int len;
	char validateCaps[256];

	ret = -1;

		len = strlen(string);

		//tolower(string);


		for(int i=0;i<len;i++)
		{

			validateCaps[i] = tolower(string[i]);

			if((validateCaps[i] < 97  && validateCaps[i]!=32) || (validateCaps[i] > 122  && validateCaps[i]!=32))
			{
				ret = 0;

			}

		}


	return ret;
}


int isValidFecha(int dia, int mes, int anio)
{
    int ret  = -1;
    if(dia > 0 && mes > 0 &&  anio > 0)
    {
        if(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) &&
                (dia > 0 && dia <= 31)) ||
                ((mes == 4 || mes == 6 || mes == 9 || mes == 11) &&
                 (dia > 0 && dia <= 30)) ||
                ((mes == 2 && (anio % 4) == 0) &&
                 (dia > 0 && dia <= 29)) ||
                ((mes == 2 && (anio % 4) != 0) &&
                 (dia > 0 && dia <= 28)))
        {
            ret = 1;
        }
    }
    return ret;
}


#endif /* FUNCIONES_C_ */
