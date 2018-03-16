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
	new_tetro.coord_y = tetro->coord_y; //supr
	new_tetro.x = tetro->y;
	new_tetro.y = tetro->x;
	new_tetro.color = tetro->color;
	new_tetro.item = mem_alloc_2d_array(new_tetro.y, new_tetro.x);
	return (new_tetro);
}

item_t rotate(item_t *tetro)
{
	item_t new_tetro = tetro_create(tetro);

	for (int i = 0; i < new_tetro.y; i++)
		for (int j = 0; j < new_tetro.x; j++)
			new_tetro.item[i][j] = tetro->item[j][new_tetro.y - 1 - i];
	//tetro_destroy(tetro);
	return (new_tetro);
}
