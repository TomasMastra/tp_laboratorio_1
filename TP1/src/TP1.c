#include <stdio.h>
#include "calculos.h"
//#include "validar.h"

int PedirNumero1(int);
int PedirNumero2(int);


int main() //Mastrapasqua Tomas
{

    setbuf(stdout, NULL);
    int opcion;





    int numero1;
    int numero2;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorial;
    int factorial2;


    //para el menu
    numero1=0;
    numero2=0;




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
            	MostrarEcuaciones(suma, resta, multiplicacion, factorial, factorial2, division, numero2, numero1);
            break;
        }


    }while(opcion!=5);

    return 0;
 }

/////////////////////////////////////////////////////////////////////




