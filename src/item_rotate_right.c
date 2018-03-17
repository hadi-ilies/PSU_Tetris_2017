/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** item_rotate_right.c
*/

#include "my.h"

item_t tetro_create(item_t *tetro)
{
	item_t new_tetro;

	new_tetro.coord_x = tetro->coord_x;
	new_tetro.coord_y = tetro->coord_y;
	new_tetro.x = tetro->y;
	new_tetro.y = tetro->x;
	new_tetro.color = tetro->color;
	new_tetro.item = mem_alloc_2d_array(new_tetro.y, new_tetro.x);
	return (new_tetro);
}

item_t rotate(item_t *tetro)
{
	item_t ntetro = tetro_create(tetro);

	for (int i = 0; i < ntetro.y; i++)
		for (int j = 0; j < ntetro.x; j++)
			ntetro.item[i][j] = tetro->item[j][ntetro.y - 1 - i];
	return (ntetro);
}
