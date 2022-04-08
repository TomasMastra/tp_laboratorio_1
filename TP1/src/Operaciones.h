/*
 * Operaciones.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Tomas Mastra
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_



#endif /* OPERACIONES_H_ */


float CalcularDebitoLatam(float precioLatam);  //Esta funcion calcula el viaje de Latam con un 10% de descuento usando una tarjeta de debito, multiplico el precio del viaje * 0.90
float CalcularCreditoLatam(float precioLatam); 	//Esta funcion calcula el viaje de Latam con un 25% de descuento usando una tarjeta de credito, multiplico el precio del pasaje * 1.25
float CalcularBitCoinLatam(float precioLatam);  //Esta funcion calcula el viaje de Latam en Bitcoins (1BTC -> 4606954.55 Pesos Argentinos)
float CalcularPrecioUnitarioLatam(float precioLatam, int kilometros); //Calcula el precio por cada kilometro de la aerolinea Latam (COSTO DEL VIAJE / KILOMETROS)

float CalcularDebitoAerolineas(float precioAerolineas); //Esta funcion calcula el viaje de Aerolineas con un 10% de descuento usando una tarjeta de debito, multiplico el precio del viaje * 0.90
float CalcularCreditoAerolineas(float precioAerolineas);	//Esta funcion calcula el viaje de Aerolineas con un 25% de descuento usando una tarjeta de credito, multiplico el precio del pasaje * 1.25
float CalcularBitCoinAerolineas(float precioAerolineas);	//Esta funcion calcula el viaje de Aerolineas en Bitcoins (1BTC -> 4606954.55 Pesos Argentinos)
float CalcularPrecioUnitarioAerolineas(float precioAerolineas, int kilometros); //Calcula el precio por cada kilometro de Aerolineas (COSTO DEL VIAJE / KILOMETROS)

float CalcularDiferenciaPrecio(float precioAerolineas, float precioLatam); //Calcula la diferencia de precio entre ambas aerolineas. Busca la agencia mas cara para poder restar una sobre la otra,

int mostrarResultados(float precioDebitoLatam, float precioCreditoLatam, float precioBitcoinLatam, float precioUnitarioLatam, float precioDebitoAerolineas, float precioCreditoAerolineas, float precioBitcoinAerolineas, float precioUnitarioAerolineas, float diferenciaPrecio);
//Esta funcion muestra todos los datos que se los paso en el main
