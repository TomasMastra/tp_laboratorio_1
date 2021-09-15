

#ifndef CALCULOS_C_
#define CALCULOS_C_
#include "calculos.h"

int PedirNumero1(int numero1)
{

	printf("ingrese el primer numero:");
    scanf("%d", &numero1);

    printf("el numero 1 es %d \n", numero1);


    return numero1;
}

int PedirNumero2(int numero2)
{
    printf("ingrese el segundo numero");
    scanf("%d", &numero2);

    printf("el numero 2 es %d \n", numero2);



    return numero2;
}


int Sumar(int suma, int numero1, int numero2)
{

    //int numero1;
    //int numero2;
	//numero1=PedirNumero1(numero1);
	//numero2=PedirNumero2(numero2);

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

int FactorialPrimerOperando(int factorial, int numero1)
{
	int i;
	    factorial=1;






	    for (i = numero1; i > 1; i--)
	    {
	    factorial = factorial * i;
	    }



	    return factorial;

}

int FactorialSegundoOperando(int factorial2, int numero2)
{
    int i;
    factorial2=1;





if(numero2>0 || numero2<90){
    for (i = numero2; i > 1; i--)
    {
    factorial2 = factorial2 * i;
    }
}



    return factorial2;


}

void MostrarEcuaciones(int suma, int resta, int multiplicacion, int factorial, int factorial2, float division, int numero2, int numero1)
{






	printf("la suma A+B es %d \n", suma);
	printf("la resta A-B es %d \n", resta);
	printf("la multiplicacion de A*B es %d \n", multiplicacion);


	/**
	 *
	 * Si el segundo numero es 0, no se puede dividir ya que no tiene solucion
	 *
	 */
	if(numero2==0)
	{
	printf("No se puede dividir entre cero \n");
	}
	else
	{
		printf("la division de A/B es %.2f \n", division);

	}

	/*
	 *
	 * Aca valido que no sea un numero negativo y que no sea superior a 32 ya que es la capacidad maxima de int
	 *
	 */
	if(numero1>0 && numero1<13)
	{
		printf("el factorial de A es %d", factorial);
	}
	else
	{
		printf("El factorial de A no se pudo realizar");

	}


	if(numero2>0 && numero2<13)
		{
			printf("el factorial de B es %d ", factorial2);
		}
		else
		{
			printf(" y el factorial de B no se pudo realizar");

		}


	//printf("el factorial de A es %d y el de B es %d \n", factorial, factorial2);

}



#endif /* CALCULOS_C_ */
