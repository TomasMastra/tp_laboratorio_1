/*
 * Input.c
 *
 *  Created on: 6 jun. 2022
 *      Author: Tomas Mastra
 */

#ifndef INPUT_C_
#define INPUT_C_
#include <stdio.h>   //MASTRAPASQUA TOMAS B
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Input.h"

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

		while((auxNumber < min || auxNumber > max) && (validateInt(number)==0))
		{
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

				if(validateCaps[i] < 48  ||  validateCaps[i]!=57)
				{
					ret = 0;

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

int getChar(char* character, char* message)
{
	int ret = -1;

	if(character != NULL && message != NULL)
	{
		printf("%s", message);
		fflush(stdin);
		//__fpurge(stdin);

		*character = getchar();
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

	}
	buffer[0] = toupper(buffer[0]);

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

			if((validateCaps[i] < 97 && validateCaps[i]!=32) || (validateCaps[i] > 122 && validateCaps[i]!=32))
			{
				ret = 0;

			}

		}


	return ret;
}





#endif /* INPUT_C_ */
