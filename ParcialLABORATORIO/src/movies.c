/*
 * movies.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Matias
 */
#include "movies.h"
#include "parser.h"
#include "library.h"
#include "LinkedList.h"
#include "controller.h"

int menu()
{
	int opcion;
	printf("\n\n  *** MENU ***\n");
	printf("1)Cargar archivo.\n");
	printf("2)Mostrar lista de peliculas.\n");
	printf("3)Mapear rating.\n");
	printf("4)Mapear Genero.\n");
	printf("5)Filtrar por genero.\n");
	printf("6)Ordenar peliculas por genero y rating.\n");
	printf("7)Guardar peliculas ordenadas.\n");
	printf("8)Salir.\n");

	validarInt("\nIngrese la opcion que desea elegir\n", "\nError.Ingrese la opcion que desea elegir \n", &opcion, 0, 8);

	return opcion;
}

int printMovie(eMovies *this)
{
	int todoOk = 0;

	if (this != NULL)
	{
		printf("%5d %30s %15s  %.1f\n", this->id, this->nombre, this->genero, this->rating);
		todoOk = 1;
	}
	return todoOk;
}

int printMovies(LinkedList *lista)
{
	int todoOk = 0;
	eMovies *movie;
	if (lista != NULL)
	{
		printf("           *** LISTADO DE PELICULAS *** \n");
		printf("%5s %30s %15s  %5s\n", "Id", "Nombre", "Genero", "Rating");
		printf("----------------------------------------------------------\n");
		for (int i = 0; i < ll_len(lista); i++)
		{
			movie = ll_get(lista, i);
			printMovie(movie);
			todoOk = 1;
		}
	}
	return todoOk;
}

void eMovies_delete(eMovies *this)
{
	if (this != NULL)
	{
		free(this);
	}
}

eMovies *eMovies_new()
{
	eMovies *new;
	new = (eMovies *)malloc(sizeof(eMovies));
	if (new != NULL)
	{
	}
	else
	{
		eMovies_delete(new);
		new = NULL;
	}
	return new;
}

void *asignarRating(void *a)
{
	int min = 10;
	int max = 100;
	float valor;
	eMovies *movie = NULL;
	movie = (eMovies *)a;
	if (a != NULL && movie->rating == 0)
	{
		valor = (float)(rand() % (max - min + 1) + min) / 10;
		movie->rating = valor;
	}
	return a;
}

void *asignarGenero(void *a)
{
	int min = 1;
	int max = 4;
	int valor;
	eMovies *movie = NULL;
	movie = (eMovies *)a;
	if (a != NULL && strcmp(movie->genero, "sin genero") == 0)
	{
		valor = (rand() % (max - min + 1)) + min;

		if (valor == 1)
		{
			strcpy(movie->genero, "Drama");
		}
		if (valor == 2)
		{
			strcpy(movie->genero, "Comedia");
		}
		if (valor == 3)
		{
			strcpy(movie->genero, "Accion");
		}
		if (valor == 4)
		{
			strcpy(movie->genero, "Terror");
		}
	}

	return a;
}

int eMovies_filterComedy(void *a)
{
	int todoOk = 0;
	eMovies *pMovie = NULL;
	if (a != NULL)
	{
		pMovie = (eMovies *)a;
		if (strcmp(pMovie->genero, "Comedia") == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int eMovies_filterDrama(void *a)
{
	int todoOk = 0;
	eMovies *pMovie = NULL;
	if (a != NULL)
	{
		pMovie = (eMovies *)a;
		if (strcmp(pMovie->genero, "Drama") == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int eMovies_filterTerror(void *a)
{
	int todoOk = 0;
	eMovies *pMovie = NULL;
	if (a != NULL)
	{
		pMovie = (eMovies *)a;
		if (strcmp(pMovie->genero, "Terror") == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int eMovies_filterAccion(void *a)
{
	int todoOk = 0;
	eMovies *pMovie = NULL;
	if (a != NULL)
	{
		pMovie = (eMovies *)a;
		if (strcmp(pMovie->genero, "Accion") == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int menuFiltrarGenero()
{
	int opcion;

	printf("\n\n\n\n1)Drama \n");
	printf("2)Comedia\n");
	printf("3)Accion\n");
	printf("4)Terror\n");
	printf("5)SALIR\n");

	validarInt("\n\n\nIngrese la opcion de como desea filtrar\n", "\n\n\nError.Ingrese la opcion de como desea filtrar \n", &opcion, 0, 5);

	return opcion;
}

int eMovies_sortGenero(void *a, void *b)
{
	if (a != NULL && b != NULL)
	{

		if ((strcmp(((eMovies *)a)->genero, ((eMovies *)b)->genero) > 0))
		{
			return 1;
		}
		if (strcmp(((eMovies *)a)->genero, ((eMovies *)b)->genero) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int eMovies_sortRating(void *a, void *b)
{

	if (a != NULL && b != NULL)
	{

		if ((strcmp(((eMovies *)a)->genero, ((eMovies *)b)->genero) == 0))
		{
			if (((eMovies *)a)->rating > ((eMovies *)b)->rating)
			{
				return 1;
			}
		}

		if ((strcmp(((eMovies *)a)->genero, ((eMovies *)b)->genero) == 0))
		{
			if (((eMovies *)a)->rating < ((eMovies *)b)->rating)
			{
				return -1;
			}
		}
	}
	return 0;
}
