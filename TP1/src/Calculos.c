/*
 * calculos.c
 *
 *  Aca estan las funciones para pedir los numeos y realizar las operaciones
 */

#ifndef CALCULOS_C_
#define CALCULOS_C_
#include "calculos.h"
#include "Menu.h"


int PedirNumero1(int numero1)
{

	numero1=0;
	printf("ingrese el primer numero: ");
    scanf("%d", &numero1);

    printf("el numero 1 es %d \n", numero1);


    return numero1;
}

int PedirNumero2(int numero2)
{
	numero2=0;
    printf("ingrese el segundo numero: ");
    scanf("%d", &numero2);

    printf("el numero 2 es %d \n", numero2);



    return numero2;
}


int Sumar(int suma, int numero1, int numero2)
{



	suma=numero1+numero2;


	return suma;
}

int Restar(int resta, int numero1, int numero2)
{
    resta=numero1-numero2;


    return resta;
}

float Dividir(float division, int numero1, int numero2)
{
    division=((float)numero1/numero2);


    return division;
}

int Multiplicar(int multiplicacion, int numero1, int numero2)
{

    multiplicacion=numero1*numero2;




    return multiplicacion;
}

long FactorialPrimerOperando(long factorial, int numero1)
{
    int i=0;
    factorial=1;



    /*
     * esta funcion es para el factorial y por cada iteracion i se resta un numero
     * factorial va a ser multiplicado por i mientras que se le va restando 1
     *
     * por ejemplo, el factorial que esta inicializado en 1 se multiplica por el numero que es 5, a la variable i se le resta 1 numero y
     * a el factorial se lo multiplica por ese numero hasta llegar a 1.
     *
     * Lo mismo para el otro factorial
     *
     *
     */
    for (i = numero1; i > 1; i--)
    {
    factorial = factorial * i;
    }
   ;



    return factorial;
}

long FactorialSegundoOperando(long factorial2, int numero2)
{
    int i;
    factorial2=1;






    for (i = numero2; i > 1; i--)
    {
    factorial2 = factorial2 * i;
    }



    return factorial2;


}

void MostrarEcuaciones(int suma, int resta, int multiplicacion, long factorial, long factorial2, float division, int numero1, int numero2)
{






	printf("la suma A+B es %d \n", suma);
	printf("la resta A-B es %d \n", resta);
	printf("la multiplicacion de A*B es %d \n", multiplicacion);


	/*
	 * Aca valido que el numero2 no sea 0 porque no tiene solucion, en caso de que sea 0 tira un mensaje advirtiendo al usuario
	 *
	 *
	 *
	 */
	if(numero2==0)
	{
		printf("No se puede dividir por 0 \n");
	}
	else
	{
	printf("la division de A/B es %.2f \n", division);
	}


	/*
	 *
	 * Aca valido que el numero no sea negativo y que no sea 0
	 *
	 */
	if(numero1>-1)
	{
		printf("El factorial de A es %ld ", factorial);
	}else
	{
		printf("No se puede realizar el factorial de A");
	}

	if(numero2>-1)
		{
			printf(" y el factorial de B es %ld \n", factorial2);
		}else
		{
			printf(" y no se puede realizar el factorial de B \n");
		}
	//printf("el factorial de A es %d y el de B es %d \n", factorial, factorial2);

}



#endif /* CALCULOS_C_ */
