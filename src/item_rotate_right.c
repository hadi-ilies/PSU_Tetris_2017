/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** item_rotate_right.c
*/

#include "my.h"

tetro_t rotate_right(tetro_t *tetro)
{
	tetro_t new_tetro = tetro_create(tetro->nb_case_y, tetro->nb_case_x);

	for (size_t i = 0; i < new_tetro.nb_case_x; i++)
		for (size_t j = 0; j < new_tetro.nb_case_y; j++) {
			new_tetro.tab[i][j] = tetro->tab[j][new_tetro.nb_case_x - 1 - i];
		}
	tetro_destroy(tetro);
	return (new_tetro);
}
