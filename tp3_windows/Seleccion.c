#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"
#include "Funciones.h"

void selec_delete(Seleccion* this)
{
	free(this);
}

Seleccion* selec_new()
{

	Seleccion* unaSeleccion;


	unaSeleccion = (Seleccion*)malloc(sizeof(Seleccion));

	return unaSeleccion;
}
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* unaSeleccion;
	int id;
	int convocados;

		if(idStr!=NULL &&  paisStr!=NULL && confederacionStr!=NULL && convocadosStr!=NULL)
		{


			unaSeleccion = selec_new();

			id = atoi(idStr);
			convocados = atoi(convocadosStr);

			selec_setId(unaSeleccion, id);
			selec_setPais(unaSeleccion, paisStr);
			selec_setConfederacion(unaSeleccion, confederacionStr);
			selec_setConvocados(unaSeleccion, convocados);


			/*if((jug_setId(unJugador, id)==0) || 	(jug_setNombreCompleto(unJugador, nombreCompletoStr)==0)  || (jug_setPosicion(unJugador, posicionStr)==0) || (jug_setNacionalidad(unJugador, nacionalidadStr)==0)	|| 	(jug_setEdad(unJugador, edad)==0) || 	(jug_setIdSeleccion(unJugador, idSeleccion)==0))
			{
				 //jug_delete(unJugador);
			}*/
		}


		return unaSeleccion;
}




int selec_setId(Seleccion* this,int id)
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
int selec_getId(Seleccion* this,int* id)
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

int selec_setPais(Seleccion* this,char* pais)
{
	int ret;
	ret = 0;


	if(this!=NULL && pais>0)
	{

		strcpy(this->pais, pais);

		ret = 1;
	}

	return ret;
}
int selec_getPais(Seleccion* this,char* pais)
{
	int ret;
	ret = 0;
	if(this!=NULL && pais!=NULL)
	{
		strcpy(pais, this->pais);

		ret=1;
	}

	return ret;
}




int selec_setConfederacion(Seleccion* this,char* confederacion)
{
	int ret;
	ret = 0;


	if(this!=NULL && confederacion>0)
	{
		strcpy(this->confederacion, confederacion);

		ret = 1;
	}

	return ret;
}
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int ret;
	ret = 0;
	if(this!=NULL && confederacion!=NULL)
	{
		strcpy(confederacion, this->confederacion);

		ret=1;
	}

	return ret;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int ret;
	ret = 0;


	if(this!=NULL && convocados>-1)
	{
		this->convocados = convocados;

		ret = 1;
	}

	return ret;
}
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int ret;
	ret = 0;
	if(this!=NULL && convocados!=NULL)
	{
		*convocados = this->convocados;
		ret=1;
	}

	return ret;
}

void selec_print(Seleccion* this)
{
	int id;
	char pais[21];
	char confederacion[21];
	int convocados;

	if(this!=NULL)
	{
		selec_getId(this, &id);
		selec_getPais(this, pais);
		selec_getConfederacion(this, confederacion);
		selec_getConvocados(this, &convocados);




		printf("%5d %20s %20s %10d\n", id, pais, confederacion, convocados);
	}


}

int selec_compararPorConfederacion(void* p1, void* p2)
{
	int compara;
	Seleccion* unaSeleccion;
	Seleccion* otraSeleccion;

	char confederacion[21];
	char otraConfederacion[21];

	if(p1!=NULL && p2!=NULL)
	{
	unaSeleccion = (Seleccion*) p1;
	otraSeleccion = (Seleccion*) p2;

	selec_getConfederacion(unaSeleccion,confederacion);
	selec_getConfederacion(otraSeleccion,otraConfederacion);

	compara = strcmp(confederacion, otraConfederacion);
	}



	return compara;
}

void selec_disminuirConvocados(Seleccion* this, int cantidad)
{

	int convocados;
	printf("cantidad: %d\n", cantidad);

	if(cantidad==0)
	{
		selec_getConvocados(this, &convocados);
		selec_setConvocados(this, convocados-1);
		printf("convocados: %d\n", this->convocados);



	}else
	{
		selec_getConvocados(this, &convocados);
		selec_setConvocados(this, convocados+1);
		printf("convocados: %d\n", this->convocados);


	}

}
