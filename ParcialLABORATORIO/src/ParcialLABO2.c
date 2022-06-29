/*
 ============================================================================
 Name        : ParcialLABO2.c
 Author      : Matias Corta
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "movies.h"
#include "controller.h"

int main(void) {
		setbuf(stdout, NULL);
		int opcion;
		srand(time(NULL));
		LinkedList* lista = ll_newLinkedList();
		LinkedList* filter = NULL;
		int flagSort = 0;
		int flagGenero = 0;
		int flagRating= 0;

			if(lista != NULL){
		do{
			switch(menu()){

			case 1:
				controller_cargarArchivo(lista);
				break;
			case 2:
				if(ll_len(lista) > 0)
				{
					printMovies(lista);
				}else{
					printf("\n\nNo hay peliculas en la lista\n\n");
				}
						break;
			case 3:
				if(ll_len(lista) > 0)
				{
					controller_mapRating(lista);
					flagRating = 1;
					printMovies(lista);
				}else{
					printf("\n\nNo hay peliculas en la lista\n\n");
				}
						break;
			case 4:
				if(ll_len(lista) > 0)
				{
					controller_mapGenero(lista);
					flagGenero = 1;
					printMovies(lista);
				}else{
					printf("\n\nNo hay peliculas en la lista\n\n");
				}
						break;
			case 5:
				if(ll_len(lista) > 0 && flagGenero)
				{
					controller_filtrarGenero(lista, filter);
				}else{
					printf("\n\nNo hay peliculas en la lista o no poseen genero\n\n");
				}

						break;
			case 6:
				if(ll_len(lista) > 0 && flagGenero && flagRating)
				{
					controller_sort(lista);
					printMovies(lista);
					flagSort = 1;
				}else{
					printf("\n\nNo hay peliculas en la lista o alguno de los valores no fue asignado\n\n");
				}
						break;
			case 7:
				if(ll_len(lista) > 0 && flagSort)
				{
					controller_saveAsText("sort.csv", lista);
				}else{
					printf("\n\nNo hay peliculas en la lista o no se ordeno aun.\n\n");
				}
						break;
			case 8:
				opcion = 8;
						break;

			}

			}while(opcion != 8);
		}else{
			printf("Error al pedir memoria.");
		}
	return EXIT_SUCCESS;
}
