/*
 * movies.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Matias
 */

#ifndef MOVIES_H_
#define MOVIES_H_

typedef struct{
	int id;
	char nombre[50];
	char genero[50];
	float rating;

}eMovies;

#endif /* MOVIES_H_ */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "library.h"

/**
 * @brief muestra el menu principal con sus opciones
 * 
 * @return int devuelve la opcion elegida
 */
int menu();


/**
 * @brief 
 * 
 * @return eMovies* 
 */
eMovies* eMovies_new();

/**
 * @brief Imprime la lista de peliculas
 * 
 * @param lista LinkedList* lista de peliculas
 * @return int int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int printMovies(LinkedList* lista);

/**
 * @brief Imprime un pasajero en particular
 * 
 * @param this LinkedList* lista de peliculas
 * @return int int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int printMovie(eMovies* this);

/**
 * @brief muestra el menu que se encarga de mostrar las opciones de como se quiere filtrar
 * 
 * @return int  devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int menuFiltrarGenero();


/**
 * @brief Asigna un valor al campo rating entre 1.0 y 10.0
 * 
 * @param a void* elemento de la lista de peliculas.
 * @return void* retorna el elemento de la lista con el rating ya asignado en su campo
 */
void* asignarRating(void* a);

/**
 * @brief Asigna un valor al campo Genero 
 * 
 * @param a void* elemento de la lista
 * @return void* retor el elemento de la lista con el Genero ya asignado en su campo
 */
void* asignarGenero(void* a);

/**
 * @brief Filtra la lista dejando solo las peliculas de accion
 * 
 * @param a void* elemento de la lista
 * @return int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int eMovies_filterAccion(void* a);

/**
 * @brief 
 * 
 * @param a void* elemento de la lista
 * @return int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int eMovies_filterTerror(void* a);

/**
 * @brief 
 * 
 * @param a void* elemento de la lista
 * @return int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int eMovies_filterDrama(void* a);

/**
 * @brief 
 * 
 * @param a void* elemento de la lista
 * @return int devuelve 1 si pudo realizar su funcion devuelve 0 si no.
 */
int eMovies_filterComedy(void* a);

/**
 * @brief 
 * 
 * @param a void* elemento 1 de la lista
 * @param b void* elemento 2 de la lista
 * @return int 
 */
int eMovies_sortGenero(void* a, void* b);

/**
 * @brief 
 * 
 * @param a void* elemento 1  de la lista 
 * @param b void* elemento 2 de la lista 
 * @return int 
 */
int eMovies_sortRating(void* a, void* b);
