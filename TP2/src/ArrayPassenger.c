/*
 * ArrayPassenger.c
 *
 *  Created on: 26 abr. 2022
 *      Author: Tomas Mastra
 */

#ifndef ARRAYPASSENGER_C_
#define ARRAYPASSENGER_C_
#define EMPTY -1
#include "ArrayPassenger.h"
#include "Input.h"

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int initPassengers(Passenger list[], int len)
{
	int ret;
	int i;
	ret = -1;

	for(i=0;i<len;i++)
	{
		list[i].isEmpty = EMPTY;
		ret = 0;
	}



	return ret;
}

int searchEmptyPassenger(Passenger list[], int len)
{
	int i;
	int index;

	index = EMPTY;

	for(i=0;i<len;i++)
		{

			if(list[i].isEmpty == EMPTY)
			{
				index = i;



				break;
			}
		}

	printf("i vale %d\n", index);

	return index;

}

int askPassengers(Passenger list[], int len, int id)
{

	int ret;

	//int id;
	float price;
	char name[51];
	char lastName[51];
	int typePassenger;
	char flycode[21];

    ret = -1;


    			getName(name, "Ingresa el nombre (50 caracteres y letras): ", "ERROR, Ingrese el nombre (50 caracteres y letras):", 51);

				getName(lastName, "Ingresa el apellido (50 caracteres y letras): ", "ERROR, Ingresa el apellido (50 caracteres y letras): ", 51);

				getFloat(&price, "Ingresa el precio (10000 - 300000):\n","ERROR, Ingresa el precio (10000 - 300000) :\n", 10000, 300000);

				getInt(&typePassenger, "Ingresa el tipo de pasajero (10 - 50):\n","ERROR, Ingresa el tipo de pasajero (10 - 50) :\n", 10, 50);

				getString(flycode, "Ingresa el codigo de vuelo:\n","ERROR, Ingresa el codigo de vuelo:\n", 10);




				addPassengers( list,  len,  id,  name,  lastName,  price,  typePassenger, flycode);



	return ret;



}


int addPassengers(Passenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
{

	int ret=-1;
	int index;
	index = EMPTY;


	index = searchEmptyPassenger(list, len);
	printf("i vale %d\n", index);

	//confirm = confirmPassengers();


				if(index!= EMPTY)
				{

					if(confirmPassengers("Ingrese s para guardar el pasajero: ") == 0)
					{
					printf("%d\n",index);
					list[index].id=id;
					strcpy(list[index].name,name);
					strcpy(list[index].lastName,lastName);
					list[index].price=price;
					list[index].typePassenger=typePassenger;
					strcpy(list[index].flycode,flycode);

					list[index].isEmpty = 1;
					list[index].statusFlight = 1;
					printf("\n id es %d\n", list[index].id);

					ret=0;
					}



				}
				else
				{
				printf("\nERROR, no hay mas espacio en la lista\n");
				}



		return ret;
}

int confirmPassengers(char *message)
{

	int ret;
	char confirm;
	ret = -1;

    //getChar(&confirm, "Ingrese S para guardar el pasajero: ");
    printf("%s", message);
    fflush(stdin);
    scanf("%c", &confirm);


	if(confirm ==  's' || confirm == 'S')
	 {
		 ret = 0;
	 }


	return ret;
}

int findPassengerById(Passenger list[], int len,int id)
{
	int ret;
    int i;

    ret = EMPTY;

    for(i=0;i<len;i++)
    {

    	if(list[i].id == id)
    	{
    		ret = i;
    		break;

    	}
    }

	return ret;

}
int removePassenger(Passenger list[], int len, int id)
{
	int ret;
	int index;
	//int confirm;

	printPassengers(list, len);
	getInt(&id, "Ingrese el ID a eliminar: ", "ERROR, Ingrese el ID a eliminar: ", 10000, 12000);

	 index = findPassengerById(list,  len, id);

	 if(index != EMPTY)
	 {
			//getInt(&confirm, "Estas seguro que queres borrar el ID? (1 = si / 2 = no): ", "Estas seguro que queres borrar el ID? (1 = si / 2 = no): ", 1, 2);
			if(confirmPassengers("Estas seguro que queres borrar el pasajero?: ")==0)
			{
				list[index].isEmpty = EMPTY;
				ret = 0;
				printf("Se elimino con exito!!!\n");
			}
			else
			{

				printf("No se elimino\n");
			}


	 }else
	 {
		 printf("No se encontro el ID\n");
	 }


	return ret;

}

int modifyPassengers(Passenger list[], int len)
{
	int ret;
	int index;
	int id;
	int option;

	char name[21];
	char lastName[21];
	int typePassenger;
	char flycode[10];
	float price;

	ret = EMPTY;

	//confirm = EMPTY;


		printPassengers(list, len);

		getInt(&id, "Ingrese el ID a modificar: ", "ERROR, Ingrese el ID a modificar: ", 10000, 12000);

		 index = findPassengerById(list,  len, id);

		 if(index != EMPTY)
		 {
				getInt(&option, "Ingrese lo que va a modificar: (1.nombre 2.apellido 3.precio 4.tipo de pasajero 5. codigo de vuelo)", "ERROR, Ingrese lo que va a modificar: (1.nombre 2.apellido 3.precio 4.tipo de pasajero 5. codigo de vuelo): ", 1, 5);
				switch(option)
				{
				case 1:
					getName(name, "Ingrese el nombre a modificar: ", "ERROR, Ingrese el nombre a modificar: ", 51);
										if(confirmPassengers("Ingrese s para modificar: ")==0)
										{
											strcpy(list[index].name, name);

										}
					break;

				case 2:
					getName(lastName, "Ingrese el apellido a modificar: ", "ERROR, Ingrese el apellido a modificar: ", 51);
										if(confirmPassengers("Ingrese s para modificar: ")==0)
										{
											strcpy(list[index].lastName, lastName);

										}
					break;

				case 3:
					getFloat(&price, "Ingrese el precio a modificar: ", "ERROR, Ingrese el precio a modificar: ", 10, 50);
										if(confirmPassengers("Ingrese s para modificar: ")==0)
										{
											list[index].price = price;
										}

					break;

				case 4:
					getInt(&typePassenger, "Ingrese el tipo de pasajero a modificar: ", "ERROR, Ingrese el tipo de pasajero a modificar: ", 10, 50);
					if(confirmPassengers("Ingrese s para modificar: ")==0)
					{
						list[index].typePassenger = typePassenger;
					}



					break;

				case 5:
					getString(flycode, "Ingrese el codigo de vuelo a modificar: ", "ERROR, Ingrese el codigo de vuelo a modificar: ", 10);
										if(confirmPassengers("Ingrese s para modificar: ")==0)
										{
											strcpy(list[index].flycode, flycode);

										}
					break;
				}


		 }else
		 {
			 printf("No se encontro el ID\n");
		 }


	return ret;


}

void printPassenger(Passenger list)
{
	printf("%-5d %-20s %-20s %-20.2f %-20.2d %-20s\n", list.id, list.lastName, list.name, list.price, list.typePassenger, list.flycode);

}

int printPassengers(Passenger list[], int length)
{

	int ret;
	int i;


	for(i=0;i<length;i++)
	{

		if(list[i].isEmpty != EMPTY)
				{


					printPassenger(list[i]);
						ret = 1;

				}

	}

	return ret;
}

int sortPassengers(Passenger list[], int len, int order)
{
	int ret;

	ret=0;
		Passenger auxPassenger;
		order=0;

		getInt(&order, "Orden (1.asc 0.desc)", "Orden (1,asc, 0.desc)", 0,1);

		if(order==1)
		{
				for(int i = 0; i < len-1; i++)
				{
					for(int j = i+1; j<len; j++)
					{
						if(list[i].isEmpty != -1 && list[j].isEmpty)
						{
						if(strcmp(list[i].lastName, list[j].lastName)>0)

						{
							auxPassenger = list[i];
							list[i] = list[j];
							list[j] = auxPassenger;
						}else
						{
							if(strcmp(list[i].lastName, list[j].lastName)==0)
							{
								if(list[i].typePassenger>list[j].typePassenger)
								{
									auxPassenger = list[i];
									list[i] = list[j];
									list[j] = auxPassenger;
								}
							}
						}


						}
					}
				}
		}else
		{
			if(order==0)
			{
				for(int i = 0; i < len-1; i++)
								{
									for(int j = i+1; j<len; j++)
									{
										if(list[i].isEmpty != -1 && list[j].isEmpty)
										{
										if(strcmp(list[i].lastName, list[j].lastName)<0)

										{
											auxPassenger = list[i];
											list[i] = list[j];
											list[j] = auxPassenger;
										}else
										{
											if(strcmp(list[i].lastName, list[j].lastName)==0)
											{
												if(list[i].typePassenger<list[j].typePassenger)
												{
													auxPassenger = list[i];
													list[i] = list[j];
													list[j] = auxPassenger;
												}
											}
										}


										}
									}
			}
		}


		}



	return ret;


}

int sortPassengersByCode(Passenger list[], int len, int order)
{

	int ret;

		ret=0;
			Passenger auxPassenger;
			order=0;

			getInt(&order, "Orden (1.asc 0.desc)", "Orden (1,asc, 0.desc)", 0,1);

			if(order==1)
			{
					for(int i = 0; i < len-1; i++)
					{
						for(int j = i+1; j<len; j++)
						{
							if(list[i].isEmpty != -1 && list[j].isEmpty)
							{
							if(strcmp(list[i].flycode, list[j].flycode)>0)

							{
								auxPassenger = list[i];
								list[i] = list[j];
								list[j] = auxPassenger;
							}


							}
						}
					}
			}else
			{
				if(order==0)
				{
					for(int i = 0; i < len-1; i++)
									{
										for(int j = i+1; j<len; j++)
										{
											if(list[i].isEmpty != -1 && list[j].isEmpty)
											{
											if(strcmp(list[i].flycode, list[j].flycode)<0)

											{
												auxPassenger = list[i];
												list[i] = list[j];
												list[j] = auxPassenger;
											}


											}
										}
				}
			}


			}



		return ret;


}

float calculateAverage(Passenger list[], int len)
{

	float average;
	int i;
	float sumaPrecios;

	int cantidadVuelos = 0;

		sumaPrecios = 0;
		average = 0;


		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty != EMPTY)
			{

			sumaPrecios = sumaPrecios + list[i].price;
			cantidadVuelos++;

			}

		}


		average = sumaPrecios/cantidadVuelos;

		printf("Promedio de los precios de los vuelos: %.2f\n\n", average);
		printf("Suma de los promedios de los vuelos: %.2f\n\n", sumaPrecios);



		return average;

}

int printAverage(Passenger list[], int len)
{
	int ret;
	float average;
	int i;

	average=0;
	ret=0;


	average = calculateAverage(list,  len);
	//printf("Promedio de los precios de los vuelos: %.2f\n\n", average);

	printf("Pasajeros que superan el promedio:\n");
	for(i = 0;i<len;i++)
	{
		if(list[i].isEmpty!=-1)
		{
			if(list[i].price > average)
			{
				printPassenger(list[i]);
			}
		}
	}


	return ret;


}

int printSubMenu(Passenger list[], int len)
{
	int ret;
	int option;

	ret=0;

	do{
	getInt(&option, "------------------------------------------------------------------------------------------------\n"
		 	    	"1. MOSTRAR ORDENADOS POR APELLIDO Y TIPO DE PASAJERO\n"
		 	    	"2. TOTAL Y PROMEDIO DE LOS PRECIOS DE LOS PASAJES Y CUANTOS PASAJEROS SUPERAN EL PRECIO PROMEDIO\n"
		 	    	"3. LISTADO PASAJEROS POR CODIGO DE VUELO Y ESTADO DE VUELO ACTIVO\n"
					"4. VOLVEL AL MENU PRINCIPAL\n"
					"-------------------------------------------------------------------------------------------------\n",
					"-------------------------------------------------------------------------------------------------\n"
					"1. MOSTRAR ORDENADOS POR APELLIDO Y TIPO DE PASAJERO\n"
					"2. TOTAL Y PROMEDIO DE LOS PRECIOS DE LOS PASAJES Y CUANTOS PASAJEROS SUPERAN EL PRECIO PROMEDIO\n"
					"3. LISTADO PASAJEROS POR CODIGO DE VUELO Y ESTADO DE VUELO ACTIVO\n"
					"4. VOLVEL AL MENU PRINCIPAL\n"
					"--------------------------------------------------------------------------------------------------\n", 1, 4);


	switch(option)
	{
	case 1:
		sortPassengers(list,  len,  1);
		printPassengers(list, len);

		break;


	case 2:

		printAverage(list, len);



		break;


	case 3:
		sortPassengersByCode(list,  len,  1);
		printPassengers(list, len);


		break;


	}
	}while(option!=4);

	return ret;

}

#endif /* ARRAYPASSENGER_C_ */
