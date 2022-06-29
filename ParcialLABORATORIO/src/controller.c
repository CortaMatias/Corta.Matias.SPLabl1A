/*
 * controller.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Matias
 */
#include "controller.h"

int controller_cargarArchivo(LinkedList *lista)
{
	int todoOk;
	char archivo[30];

	if (lista != NULL)
	{

		printf("Ingrese el nombre del archivo que desea cargar:  Ej: movies.csv \n");
		fflush(stdin);
		fgets(archivo, 30, stdin);
		limpiarBarraN(archivo);

		if (archivo > 0)
		{
			FILE *data = fopen(archivo, "r");

			if (data == NULL)
			{
				todoOk = 0;
				printf("error al abrir el archivo\n");
			}
			else
			{
				// Si esta vacio copia lo del archivo a la lista
				if (ll_len(lista) == 0)
				{
					todoOk = parser_PassengerFromText(data, lista);

					printf("Cargado\n");
				}
				else
				{ // si tiene datos, hacemos el backUp
					if (!controller_saveAsText("backUp.csv", lista))
					{
						printf("Los datos fueron cargados, pero no se pudo hacer el backUp");
						ll_clear(lista);
						todoOk = parser_PassengerFromText(data, lista);
					}
					else
					{
						printf("Se han sobre-escrito los datos, se hizo un backUp en \"backUp.csv\"");
						ll_clear(lista);
						todoOk = parser_PassengerFromText(data, lista);
					}
				}
			}
			fclose(data);
		}
	}
	return todoOk;
}

int controller_saveAsText(char *path, LinkedList *lista)
{
	int todoOk = 0;
	eMovies *movie;
	if (path != NULL && lista != NULL)
	{
		FILE *data = fopen(path, "a");
		if (data == NULL)
		{
			todoOk = 0;
			printf("error al abrir el archivo\n");
		}
		else if (ll_len(lista) > 0)
		{
			for (int i = 0; i < ll_len(lista); i++)
			{
				movie = (eMovies *)ll_get(lista, i);
				fprintf(data, "%d,%s,%s,%f\n", movie->id, movie->nombre, movie->genero, movie->rating);
			}
			todoOk = 1;
			fclose(data);
		}
	}
	return todoOk;
}

int controller_saveAsBinary(char *path, LinkedList *lista)
{
	int todoOk = 0;
	eMovies *movie;

	if (path != NULL && lista != NULL)
	{
		FILE *data = fopen(path, "ab");
		int cant;
		if (data == NULL)
		{
			todoOk = 0;
			printf("\nerror al abrir el archivo\n");
		}

		if (ll_len(lista) > 0)
		{
			for (int i = 0; i < ll_len(lista); i++)
			{
				movie = (eMovies *)ll_get(lista, i);
				cant = fwrite(movie, sizeof(eMovies), 1, data);
				if (cant != 1)
				{
					break;
				}
			}
			todoOk = 1;
			fclose(data);
		}
	}
	return todoOk;
}

int controller_mapRating(LinkedList *lista)
{
	int todoOk = 0;

	if (lista != NULL)
	{
		lista = ll_map(lista, asignarRating);
		todoOk = 1;
	}
	return todoOk;
}

int controller_mapGenero(LinkedList *lista)
{
	int todoOk = 0;

	if (lista != NULL)
	{
		lista = ll_map(lista, asignarGenero);
		todoOk = 1;
	}
	return todoOk;
}

int controller_filtrarGenero(LinkedList *lista, LinkedList *filter)
{
	int todoOk = 0;
	int opcion;

	if (lista != NULL)
	{

		do
		{
			switch (menuFiltrarGenero())
			{

			case 1:
				filter = ll_filter(lista, eMovies_filterDrama);
				controller_saveAsTextTemporal("filterDrama.csv", filter, "w");
				break;
			case 2:
				filter = ll_filter(lista, eMovies_filterComedy);
				controller_saveAsTextTemporal("filterComedy.csv", filter, "w");
				break;
			case 3:
				filter = ll_filter(lista, eMovies_filterAccion);
				controller_saveAsTextTemporal("filterAccion.csv", filter, "w");
				break;
			case 4:
				filter = ll_filter(lista, eMovies_filterTerror);
				controller_saveAsTextTemporal("filterTerror.csv", filter, "w");
				break;
			case 5:
				opcion = 12;
				break;
			}
			printMovies(filter);
			todoOk = 1;
		} while (opcion != 12);
	}
	return todoOk;
}

int controller_sort(LinkedList *lista)
{
	int todoOk = 0;

	if (lista != NULL)
	{
		ll_sort(lista, eMovies_sortGenero, 1);
		ll_sort(lista, eMovies_sortRating, 0);
		todoOk = 1;
	}

	return todoOk;
}

// W Si existe reemplaza, si no existe crea
// A Si existe agrega, si no existe crea
// R Lee, si no existe devuelve error

int controller_saveAsTextTemporal(char *path, LinkedList *lista, char *tipo)
{
	int todoOk = 0;
	eMovies *movie;
	if (path != NULL && lista != NULL)
	{
		FILE *data = fopen(path, tipo);
		if (data == NULL)
		{
			todoOk = 0;
			printf("error al abrir el archivo\n");
		}
		else if (ll_len(lista) > 0)
		{
			for (int i = 0; i < ll_len(lista); i++)
			{
				movie = (eMovies *)ll_get(lista, i);
				fprintf(data, "%d,%s,%s,%f\n", movie->id, movie->nombre, movie->genero, movie->rating);
			}
			todoOk = 1;
			fclose(data);
		}
	}
	return todoOk;
}
