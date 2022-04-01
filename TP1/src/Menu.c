/*
 * Menu.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Tomas Mastra
 */

#ifndef MENU_C_
#define MENU_C_

#include "Menu.h"
#include "Calculos.h"

void PedirOpcionMenu(int opcion)
{







	    int numero1;
	    int numero2;
	    int suma;
	    int resta;
	    float division;
	    int multiplicacion;
	    long factorial;
	    long factorial2;


	    //para que en el menu no se muestre un numero cualquiera
	   numero1=0;
	    numero2=0;



	/*
	 *
	 * Aca hago un do while con las opciones de la calculadora, muestro en la pantala los resultados de los 2 numeros A Y B
	 * los numeros se inicializan en 0 en caso de que el usuario no ingrese nada, lo equivalente a no calcular nada, si se ingresa
	 * un solo numero se mostraria solo ese numero
	 *
	 *
	 */





	    do
	    {


	        printf("\n1. ingresar primer operando A= %d \n", numero1);
	        printf("2. ingresar segundo operando B= %d \n", numero2);
	        printf("3. calcular operaciones\n");
	        printf("4. mostrar resultados\n");
	        printf("5. Salir\n");
	        printf("Elija una opcion:\n");
	        scanf("%d", &opcion);

	        switch(opcion)
	        {
	        	case 1:
	        	numero1 = PedirNumero1(numero1);

	            break;
	            case 2:
	            numero2 = PedirNumero2(numero2);

	            break;
	            case 3:
	            suma=Sumar(suma, numero1, numero2);
	            resta=Restar(resta, numero1, numero2);
	            multiplicacion=Multiplicar(multiplicacion, numero1, numero2);
	            division=Dividir(division, numero1, numero2);
	            factorial=FactorialPrimerOperando(factorial, numero1);
	            factorial2=FactorialSegundoOperando(factorial, numero2);

	            break;
	            case 4:
	            	MostrarEcuaciones(suma, resta, multiplicacion, factorial, factorial2, division, numero1, numero2);
	            break;
	        }


	    }while(opcion!=5);


}

#endif /* MENU_C_ */
