
/**
 * @fn int controller_listarJugadoresConvocados(char*, LinkedList*)

 * @brief
 *
 * @param char* path: ruta del archivo
 * @param LinkedList* pArrayListSeleccion: lista de jugadores
 * @return 1
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);//1


/**
 * @fn int controller_cargarJugadoresDesdeBinario(char*, LinkedList*)

 * @brief
 *
 * @param char* path: la ruta del archivo
 * @param LinkedList* pArrayListJugador: lista de jugadores
 * @return 1
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);//9


/**
 * @fn int controller_agregarJugador(LinkedList*)

 * @brief egrega un jugador pidiendole los datos, el id se calcula automaticamente, es autoincremental y se guarda en ultimaId.csv mediante una funcion
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @return 1
 */
int controller_agregarJugador(LinkedList* pArrayListJugador);//2


/**
 * @fn int controller_editarJugador(LinkedList*)

 * @brief pide el ingreso de un id para modificar y llama a la funcion que muestra el menu que permite elegir el campo que se desea modificar
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @return 1
 */
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//3

/**
 * @fn int controller_removerJugador(LinkedList*)

 * @brief Pide el ingreso del id del jugador para eliminarlo, tambien a la seleccion se le saca el jugador convocado
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @return 1
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//4

/**
 * @fn int controller_listarJugadores(LinkedList*)

 * @brief muestra los jugadores
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @param LinkedList* pArrayListSeleccion
 * @return 1
 */
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//5


/**
 * @fn int controller_ordenarJugadores(LinkedList*, LinkedList*)

 * @brief permite elegir el criterio de irdenamiento al usuario mediante un menu
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeeleccion);//7


/**
 * @fn int controller_guardarJugadoresModoTexto(LinkedList*)

 * @brief guarda los jugadores en el archivo jugadores.csv (Todos)
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @return 1
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);//10

/**
 * @fn int controller_guardarJugadoresModoBinario(LinkedList*, LinkedList*)

 * @brief guarda los jugadores de una confederacion en especifico, se le pregunta al jugador. Los guarda en jugadoresConvocados.bin
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//8


/**
 * @fn int controller_cargarSeleccionesDesdeTexto(char*, LinkedList*)

 * @brief carga las selecciones desde el archivo selecciones.csv
 *
 * @param char* path: ruta del archivo para cargar selecciones
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);//1


/**
 * @fn int controller_listarJugadoresConvocados(LinkedList*)

 * @brief permite editar una seleccion, preguntando que desea eliminar (No se usa)
 *
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);

/**
 * @fn int controller_listarSelecciones(LinkedList*)

 * @brief muestra las selecciones
 *
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);//5



int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);//NO SE USA

/**
 * @fn int controller_guardarSeleccionesModotexto(LinkedList*, LinkedList*)

 * @brief guarda las selecciones en el archivo selecciones.txt
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);//10


/**
 * @fn int controller_mostrarMenuListar(LinkedList*, LinkedList*)

 * @brief muestra el menu para listar dependiendo lo que el usuario quiera ver
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int controller_mostrarMenuListar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//5

/**
 * @fn int controller_listarJugadoresConvocados(LinkedList*, LinkedList*)

 * @brief muestra los jugadores que pertenecen a una seleccion
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//5

/**
 * @fn int controller_mostrarMenuConvocar(LinkedList*, LinkedList*)

 * @brief muestra el menu para convocar y pide que ingrese una opcion dependiendo si quiere agregar jugador a la seleccion o eliminar de la seleccion
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int controller_mostrarMenuConvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//6


/**
 * @fn int controller_convocarJugadores(LinkedList*, LinkedList*)

 * @brief pide el ingreso de un jugador y se lo convoca a una seleccion, se le suma 1 a la seleccion
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//6

/**
 * @fn int controller_quitarJugadorDeSeleccion(LinkedList*, LinkedList*)

 * @brief pide el ingreso de un jugador y si esta convocado se lo saca de esa seleccion
 *
 * @param LinkedList* pArrayListJugador: recive la lista de jugadores
 * @param LinkedList* pArrayListSeleccion: recive la lista de selecciones
 * @return 1
 */
int controller_quitarJugadorDeSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

