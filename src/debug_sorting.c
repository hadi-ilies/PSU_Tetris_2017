/*
** EPITECH PROJECT, 2018
** sort
** File description:
** sort
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include <fcntl.h>
#include "macros.h"
#include "prototype.h"

void swap_elem(item_t *array, int index1, int index2)
{
	item_t a = array[index1];

	array[index1] = array[index2];
	array[index2] = a;
}

item_t *sort_debug(item_t *item)
{
	for (int i = 0; i < count_file(); i++)
		for (int j = i + 1; j < count_file(); j++)
			if (my_strcmp(item[i].filename, item[j].filename) >= 0)
				swap_elem(item, i, j);
	return (item);
}
