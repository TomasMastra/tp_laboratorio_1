#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Jugador.h"
#include "Funciones.h"

void jug_delete(Jugador* this)
{
	free(this);
}

Jugador* jug_new()
{

	Jugador* unJugador;


	unJugador = (Jugador*)malloc(sizeof(Jugador));

	return unJugador;
}
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{
	Jugador* unJugador;
		int id;
		int edad;
		int idSeleccion;

		if(idStr!=NULL &&  nombreCompletoStr!=NULL && edadStr!=NULL && posicionStr!=NULL &&  nacionalidadStr!=NULL &&  idSeleccionStr!=NULL)
		{


			unJugador = jug_new();

			id = atoi(idStr);
			edad = atoi(edadStr);
			idSeleccion = atoi(idSeleccionStr);



			jug_setId(unJugador, id);
			jug_setNombreCompleto(unJugador, nombreCompletoStr);
			jug_setPosicion(unJugador, posicionStr);
			jug_setNacionalidad(unJugador, nacionalidadStr);
			jug_setEdad(unJugador, edad);
			jug_setIdSeleccion(unJugador, idSeleccion);




			/*if((jug_setId(unJugador, id)==0) || 	(jug_setNombreCompleto(unJugador, nombreCompletoStr)==0)  || (jug_setPosicion(unJugador, posicionStr)==0) || (jug_setNacionalidad(unJugador, nacionalidadStr)==0)	|| 	(jug_setEdad(unJugador, edad)==0) || 	(jug_setIdSeleccion(unJugador, idSeleccion)==0))
			{
				 //jug_delete(unJugador);
			}*/
		}


		return unJugador;
}

int jug_setId(Jugador* this,int id)
{
	int ret;
	ret = 0;
	if(this!=NULL && id>0)
	{

		this->id = id;
		//printf("%d\n",this->id);
		ret = 1;
	}


	return ret;
}
int jug_getId(Jugador* this,int* id)
{
	int ret;
	ret = 0;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		ret=1;
	}

	return ret;

}

int jug_setNombreCompleto(Jugador* this,char* nombre)
{
	int ret;
	ret = 0;


	if(this!=NULL && nombre>0)
	{
		strcpy(this->nombreCompleto, nombre);
		//printf("%s\n",this->nombreCompleto);

		ret = 1;
	}

	return ret;
}
int jug_getNombreCompleto(Jugador* this,char* nombre)
{
	int ret;
	ret = 0;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombreCompleto);

		ret=1;
	}

	return ret;
}




int jug_setPosicion(Jugador* this,char* posicion)
{
	int ret;
	ret = 0;


	if(this!=NULL && posicion>0)
	{
		strcpy(this->posicion, posicion);

		ret = 1;
	}

	return ret;
}
int jug_getPosicion(Jugador* this,char* posicion)
{
	int ret;
	ret = 0;
	if(this!=NULL && posicion!=NULL)
	{
		strcpy(posicion, this->posicion);

		ret=1;
	}

	return ret;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int ret;
	ret = 0;


	if(this!=NULL && nacionalidad>0)
	{
		strcpy(this->nacionalidad, nacionalidad);

		ret = 1;
	}

	return ret;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int ret;
	ret = 0;
	if(this!=NULL && nacionalidad!=NULL)
	{
		strcpy(nacionalidad, this->nacionalidad);

		ret=1;
	}

	return ret;
}

int jug_setEdad(Jugador* this,int edad)
{
	int ret;
	ret = 0;
	if(this!=NULL && edad>0)
	{
		this->edad = edad;
		ret = 1;
	}

	return ret;
}
int jug_getEdad(Jugador* this,int* edad)
{
	int ret;
	ret = 0;
	if(this!=NULL && edad!=NULL)
	{
		*edad = this->edad;
		ret=1;
	}

	return ret;

}





int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int ret;
	ret = 0;
	if(this!=NULL && idSeleccion>-1)
	{
		this->idSeleccion = idSeleccion;
		ret = 1;
	}

	return ret;
}
int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int ret;
	ret = 0;
	if(this!=NULL && idSeleccion!=NULL)
	{
		*idSeleccion = this->idSeleccion;
		ret=1;
	}

	return ret;

}


void jug_print(Jugador* this)
{
	int id;
	char nombreCompleto[21];
	char posicion[21];
	char nacionalidad[21];
	int edad;
	int idSeleccion;

	if(this!=NULL)
	{
		jug_getId(this, &id);
		jug_getNombreCompleto(this, nombreCompleto);
		jug_getNacionalidad(this, nacionalidad);
		jug_getPosicion(this, posicion);
		jug_getEdad(this, &edad);
		jug_getIdSeleccion(this, &idSeleccion);


		printf("%4d %10s %10s %10s %10d %10d\n", id, nombreCompleto, posicion, nacionalidad, edad, idSeleccion);
	}


}


void jug_printSubmenuModify(Jugador* this)
{
	int auxInt;
	char auxString[30];
	int opcion;
	int confirmar;


	getInt(&opcion,
											 "\n***************************\n"
											 "MODIFICAR\n"
											 "\n***************************\n"
											 "1. Modificar Nombre\n"
											 "2. Modificar Edad\n"
											 "3. Modificar Nacionalidad\n"
											 "4. Modificar Posicion\n"
											 "5. Volver al menu principal\n"
											 "Ingrese una opcion: " ,
											 "\n***************************\n"
											 "MODIFICAR\n"
											 "\n***************************\n"
											 "1. Modificar Nombre\n"
											 "2. Modificar Edad\n"
											 "3. Modificar Nacionalidad\n"
											 "4. Modificar Posicion\n"
											 "5. Volver al menu principal\n"
											 "Error, Ingrese de vuelta: " , 1, 5);

	switch(opcion)
	{
	case 1:
		getName(auxString, "Ingrese el nombre: ", "Error, Ingrese el nombre (Solo letras): ", 50);
		getInt(&confirmar, "Ingrese 1 para guardar: ", "Ingrese 1 para guardar: ", 0, 1000);

		if(confirmar == 1)
		{
			jug_setNombreCompleto(this, auxString);
			printf("Se modifico correctamente el nombre!!!\n");
		}

		break;


	case 2:
	getInt(&auxInt, "Ingrese la edad: ", "Error, Ingrese la edad: ", 16, 45);
	getInt(&confirmar, "Ingrese 1 para guardar: ", "Ingrese 1 para guardar: ", 0, 1000);

	if(confirmar == 1)
	{
		jug_setEdad(this, auxInt);
		printf("Se modifico correctamente la edad!!!\n");
	}

			break;


	case 3:
			getName(auxString, "Ingrese la nacionalidad: ", "Error, Ingrese la nacionalidad (Solo letras): ", 50);
			getInt(&confirmar, "Ingrese 1 para guardar: ", "Ingrese 1 para guardar: ", 0, 1000);

			if(confirmar == 1)
			{
				jug_setNacionalidad(this, auxString);
				printf("Se modifico correctamente la nacionalidad!!!\n");
			}

			break;


	case 4:
			getName(auxString, "Ingrese la posicion: ", "Error, Ingrese la posicion (Solo letras): ", 50);
			getInt(&confirmar, "Ingrese 1 para guardar: ", "Ingrese 1 para guardar: ", 0, 1000);

			if(confirmar == 1)
			{
				jug_setPosicion(this, auxString);
				printf("Se modifico correctamente la posicion!!!\n");
			}

			break;
	}



}

int jug_compararPorEdad(void* p1, void* p2)
{
	int compara=-1;
	Jugador* unJugador;
	Jugador* otroJugador;

	int edad;
	int otraEdad;
	if(p1!=NULL && p2!=NULL)
	{
	unJugador = (Jugador*) p1;
	otroJugador = (Jugador*) p2;


	jug_getEdad(unJugador,&edad);
	jug_getEdad(otroJugador,&otraEdad);



		if(edad>otraEdad)
		{
			compara = 1;
		}else
		if(edad<otraEdad)
				{
					compara = -1;
				}else
				{
					compara = 0;
				}
	}



	return compara;
}

int jug_compararPorNacionalidad(void* p1, void* p2)
{
	int compara;
	Jugador* unJugador;
	Jugador* otroJugador;

	char nacionalidad[41];
	char otraNacionalidad[41];

	if(p1!=NULL && p2!=NULL)
	{
	unJugador = (Jugador*) p1;
	otroJugador = (Jugador*) p2;

	jug_getNacionalidad(unJugador,nacionalidad);
	jug_getNacionalidad(otroJugador,otraNacionalidad);

	compara = strcmp(nacionalidad, otraNacionalidad);
	}



	return compara;
}


int jug_compararPorNombre(void* p1, void* p2)
{

	int compara;
	Jugador* unJugador;
	Jugador* otroJugador;

	char nombre[21];
	char otroNombre[21];

	if(p1!=NULL && p2!=NULL)
	{

	unJugador = (Jugador*) p1;
	otroJugador = (Jugador*) p2;

	jug_getNombreCompleto(unJugador,nombre);
	jug_getNombreCompleto(otroJugador,otroNombre);

	compara = strcmp(nombre, otroNombre);
	}

	//printf("nombre: %s / nombre2: %s / strcmp: %d \n",nombre,otroNombre,compara);

	//printf("%4d %10s %10s %10s %10d %10d\n", unJugador->id, unJugador->nombreCompleto, unJugador->posicion, unJugador->nacionalidad, unJugador->edad, unJugador->idSeleccion);
	//printf("%4d %10s %10s %10s %10d %10d\n", otroJugador->id, otroJugador->nombreCompleto, otroJugador->posicion, otroJugador->nacionalidad, otroJugador->edad, otroJugador->idSeleccion);





	return compara;
}
