
#ifndef PARSER_H_
#define PARSER_H_


/**
 * @fn int parser_JugadorFromText(char*, LinkedList*)

 * @brief carga los jugadores desde el archivo jugadores.txt
 *
 * @param char* path: recive la ruta del archivo que deberia leer para cargar los jugadores
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @return 1
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/**
 * @fn int parser_JugadorFromBinary(char*, LinkedList*)

 * @brief carga los jugadores desde el archivo jugadoresConvocados.bin
 *
 * @param char* path: recive la ruta del archivo que deberia leer para cargar los jugadores
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @return 1
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);


/**
 * @fn int parser_SeleccionFromText(char*, LinkedList*)

 * @brief carga los jugadores desde el archivo jugadores.txt
 *
 * @param char* path: recive la ruta del archivo que deberia leer para cargar las selecciones
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);


#endif /* PARSER_H_ */
