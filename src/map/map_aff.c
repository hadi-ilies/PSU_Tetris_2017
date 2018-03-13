/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** map_aff.c
*/

#include "map.h"

void map_aff(map_t *map, size_t x, size_t y)
{
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++) {
			move(x + i, y + j);
			printw("%c", map->tab[i][j]);
		}
}
