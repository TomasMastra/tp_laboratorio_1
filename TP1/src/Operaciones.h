/*
 * Operaciones.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Tomas Mastra
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_



#endif /* OPERACIONES_H_ */


float CalcularDebitoLatam(float precioLatam);
float CalcularCreditoLatam(float precioLatam);
float CalcularBitCoinLatam(float precioLatam);
float CalcularPrecioUnitarioLatam(float precioLatam, int kilometros);

float CalcularDebitoAerolineas(float precioAerolineas);
float CalcularCreditoAerolineas(float precioAerolineas);
float CalcularBitCoinAerolineas(float precioAerolineas);
float CalcularPrecioUnitarioAerolineas(float precioAerolineas, int kilometros);

float CalcularDiferenciaPrecio(float precioAerolineas, float precioLatam);

int mostrarResultados(float precioDebitoLatam, float precioCreditoLatam, float precioBitcoinLatam, float precioUnitarioLatam, float precioDebitoAerolineas, float precioCreditoAerolineas, float precioBitcoinAerolineas, float precioUnitarioAerolineas, float diferenciaPrecio);
