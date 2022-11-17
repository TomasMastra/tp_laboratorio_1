#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this= NULL;
	this = (LinkedList*) malloc(sizeof(LinkedList));

	if(this!=NULL)
	{
		this->size = 0;
		this->pFirstNode = NULL;
	}

	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;

	if(this!=NULL)
	{
		returnAux = this->size;
	}
	return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int len = ll_len(this);
	Node* pNode = NULL;

	if(this != NULL && nodeIndex > -1 && nodeIndex < len)
	{
		pNode = this->pFirstNode;
		for(int i=0 ;i < nodeIndex; i++)//recorre hasta nodeIndex
		{
			pNode = pNode->pNextNode;

		}
	}
	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	int len;
	Node* pPreviousNode=NULL;
	Node* pNode = NULL;

	len = ll_len(this);
	if(this != NULL && nodeIndex > -1 && nodeIndex <= len)
	{
		pNode = (Node*)malloc(sizeof(Node));
		if(pNode != NULL)
		{
			pNode->pElement = pElement;
			pNode->pNextNode = NULL;

			if(nodeIndex == 0)//primer indice
			{
				pNode->pNextNode = this->pFirstNode;//ASIGNO DIRECCION DE MRMORIA DEL PRIMERO NODO PARA NO PERDER LA LISTA
				this->pFirstNode = pNode;

			}
			else//ultimo apunta a null
			{
				pPreviousNode = getNode(this, nodeIndex-1);// nodo anterior
				pPreviousNode->pNextNode = pNode;//el del medio

			}
		}
		this->size++;
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	int len;

	if(this != NULL)
	{
		len = ll_len(this);
		returnAux = addNode(this, len, pElement);
	}

		return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* returnAux = NULL;
	int len = ll_len(this);
	Node* auxNode = NULL;

	if(this!=NULL && index >-1 && index < len)
	{
		auxNode = getNode(this, index);
		if(auxNode!=NULL)
		{
			returnAux = auxNode->pElement;
		}
	}

	return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	int len;
	int returnAux = -1;
	Node* auxNode=NULL;

	if(this != NULL)
		{
			len=ll_len(this);
			if(index > -1 && index <= len)
			{
				auxNode = getNode(this, index);
				if(auxNode != NULL)
				{
					auxNode->pElement = pElement;
					returnAux = 0;
				}
			}
		}

	return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int len;
	int returnAux = -1;
	Node* pPreviusNode = NULL;
	Node* auxNode = NULL;
	if(this != NULL)
	{
		len=ll_len(this);
		if(index > -1 && index < len)
		{
			auxNode = getNode(this, index);//obtego el elemento

			if(auxNode != NULL)
			{

				if(index == 0)
				{
					this->pFirstNode = auxNode->pNextNode;//primer nodo es el que le sigue

				}
				else
				{
					pPreviusNode = getNode(this, index - 1);
					pPreviusNode->pNextNode = auxNode->pNextNode;//aca conectamos el nodo anterior con el siguiente

				}

				free(auxNode);
				this->size--;
				returnAux = 0;
			}
		}
	}
	return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int len;
    int returnAux = -1;
    if(this != NULL)
    {
    	len=ll_len(this);

    	while(len>0)
		{
        	len=ll_len(this);
    		ll_remove(this, 0);
    	}
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int returnAux = -1;
	if(this != NULL)
	{
	ll_clear(this);
	free(this);
	returnAux = 0;
	}

   return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	int len;
	int i;
	void* auxElement = NULL;
	if(this != NULL)
	{
		len = ll_len(this);
		for(i=0 ; i<len ; i++)
		{
			auxElement = ll_get(this, i);
			if(pElement == auxElement)//aca compara y si se cumple retornamos la posicion
			{
				returnAux = i;
				break;
			}
		}
	}

	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int len;
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux=1;

    	len=ll_len(this);
    	if(len > 0)
    	{
    		returnAux = 0;
    	}

    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int returnAux = -1;
	 int len = ll_len(this);
	 if(this != NULL)
	 {
		 if(index > -1 && index < len + 1)
		  {
		  if(!addNode(this, index, pElement))
			{
			  returnAux = 0;
			}
		  }
	 }
	 return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* returnAux = NULL;
	int len = ll_len(this);
	if(this != NULL)
	{
		if(index > - 1 && index < len)
		{
			returnAux = ll_get(this, index);
			if(ll_remove(this, index))
			{
				returnAux = NULL;
			}
		}
	}
	return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	int i;
	int len = ll_len(this);
	Node* pNodeAux;
	if(this != NULL)
	{
		pNodeAux = NULL;
		returnAux = 0;
		for(i=0 ; i<len ; i++)
		{
			pNodeAux = ll_get(this, i);
			if(pNodeAux == pElement)
			{
				returnAux = 1;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	int i;
	int len = ll_len(this2);
	Node* pAuxNode;

	if(this != NULL && this2 != NULL)
	{
		returnAux = 1;
		pAuxNode = NULL;
		for(i=0 ; i<len ; i++)
		{
			pAuxNode = ll_get(this2, i);
			if(!ll_contains(this, pAuxNode))
			{
				returnAux = 0;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

