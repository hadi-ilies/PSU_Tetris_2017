/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** my_malloc.c
*/

#include "my.h"

void *my_malloc(size_t size)
{
	void *str = malloc(size);

	if (str == NULL)
		exit(84);
	return (str);
}
