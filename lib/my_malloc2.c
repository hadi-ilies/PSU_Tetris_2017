/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** my_malloc2.c
*/

#include "my.h"

void **my_malloc2(size_t nb_case_x, size_t nb_case_y)
{
	void **tab = malloc(nb_case_x);

	if (tab == NULL)
		exit(84);
	for (size_t i = 0; i < nb_case_x; i++) {
		tab[i] = malloc(nb_case_y);
		if (tab[i] == NULL)
			exit(84);
	}
	return (tab);
}
