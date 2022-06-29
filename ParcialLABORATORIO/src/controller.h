/*
 * controller.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Matias
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */
#include "movies.h"
#include "LinkedList.h"
#include "library.h"
#include "parser.h"

/**
 * @brief Guarda los datos de la lista en el archivo data.csv (modo txt).
 * 
 * @param path  char* nombre del archivo
 * @param lista LinkedList* lista de peliculas
 * @return int int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int controller_saveAsText(char *path, LinkedList *lista);

/** \brief Guarda los datos de la lista en el archivo data.bin (modo binario).
 *
 * \param path char* nombre del archivo
 * \param lista LinkedList* lista de peliculas
 * \return int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 *
 */
int controller_saveAsBinary(char *path, LinkedList *lista);


/**
 * @brief crea una nueva lista que sale de la original filtrando por genero
 * 
 * @param lista LinkedList* lista de peliculas
 * @param filter LinkedList* lista filtrada
 * @return int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int controller_filtrarGenero(LinkedList* lista, LinkedList* filter);

/**
 * @brief ordena la lista por genero, y rating descendiente 
 * 
 * @param lista LinkedList* lista de peliculas
 * @return int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int controller_sort(LinkedList* lista);

/**
 * @brief mapea (asigna valores) al campo rating de la estructura eMovies
 * 
 * @param lista LinkedList* lista de peliculas
 * @return int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int controller_mapRating(LinkedList* lista);


/**
 * @brief mapea(asigna valores) al campo Genero de la estructura eMovies
 * 
 * @param lista LinkedList* lista de peliculas
 * @return int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int controller_mapGenero(LinkedList* lista);


/**
 * @brief 
 * 
 * @param path char* nombre del archivo 
 * @param lista LinkedList* lista de peliculas
 * @param tipo char* valor que identifica de que tipo va a ser el archivo. 
 * @return int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int controller_saveAsTextTemporal(char *path, LinkedList *lista, char* tipo);


int controller_cargarArchivo(LinkedList* lista);
