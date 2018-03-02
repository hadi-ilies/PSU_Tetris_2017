/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
	char **array;

	array = malloc(sizeof(char *) * nb_rows);
	for (int i = 0; i < nb_rows; i++)
		array[i] = malloc(sizeof(char) * nb_cols);
	return (array);
}
