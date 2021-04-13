
/*
 * calculos.c
 *
 *  Created on: 9 abr. 2021
 *      Author: Compumar
 */

#ifndef CALCULOS_C_
#define CALCULOS_C_
#include "calculos.h"

int PedirNumero1(int numero1)
{
	//Pedir primer numero
	printf("ingrese el primer numero:");
    scanf("%d", &numero1);




    return numero1;
}

int PedirNumero2(int numero2)
{
	//pedir segundo numero
    printf("ingrese el segundo numero");
    scanf("%d", &numero2);





    return numero2;
}


int Sumar(int suma, int numero1, int numero2)
{

	//sumar A+B

	suma=numero1+numero2;


	return suma;
}

int Restar(int resta, int numero1, int numero2)
{
	//restas A-B
    resta=numero1-numero2;


    return resta;
}

float Dividir(float division, float numero1, float numero2)
{
	//Dividir A/B
    division=numero1/numero2;


    return division;
}

int Multiplicar(int multiplicacion, int numero1, int numero2)
{
	//Multiplicar A*B
    multiplicacion=numero1*numero2;




    return multiplicacion;
}

int FactorialPrimerOperando(int factorial, int numero1)
{
	//calcular factorial de A
	int i;
    factorial=1;

    for (i = numero1; i > 1; i--)    {
    factorial = factorial * numero1;

    }




    return factorial;
}

int FactorialSegundoOperando(int factorial2, int numero2)
{
	//Calcular factorial de B
    int i;
    factorial2=1;






    for (i = numero2; i > 1; i--)
    {
    factorial2 = factorial2 * i;
    }



    return factorial2;


}

void MostrarEcuaciones(int suma, int resta, int multiplicacion, int factorial, int factorial2, float division)
{



	//Mostrar resultado de las ecuaciones


	printf("la suma A+B es %d \n", suma);
	printf("la resta A-B es %d \n", resta);
	printf("la multiplicacion de A*B es %d \n", multiplicacion);
	printf("la division de A/B es %.2f \n", division);
	printf("el factorial de A es %d y el de B es %d \n", factorial, factorial2);

}



#endif /* CALCULOS_C_ */
