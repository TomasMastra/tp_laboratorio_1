int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);//1
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);//9
int controller_agregarJugador(LinkedList* pArrayListJugador);//2
int controller_editarJugador(LinkedList* pArrayListJugador);//3
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//4
int controller_listarJugadores(LinkedList* pArrayListJugador);//5
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeeleccion);//7
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);//10
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//8
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);//1
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);//3 CREO QUE NO SE PIDE
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);//5
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);//7
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);//10

int controller_mostrarMenuListar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//5
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador);//5

int controller_disminuirConvocadosConfederacion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

