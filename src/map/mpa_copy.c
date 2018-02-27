/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** map_copy.c
*/

#include "map.h"

map_t map_copy(map_t *map)
{
	map_t map_cpy = {.nb_case_x = map->nb_case_x};

	map_cpy.nb_case_y = map->nb_case_y
	map_cpy.tab = my_malloc(sizeof(tab_t *) * map_cpy.nb_case_x);
	for (size_t i = 0; i < map_cpy.nb_case_x; i++) {
		map_cpy.tab[i] = my_malloc(sizeof(tab_t) * map_cpy.nb_case_y);
		for (size_t j = 0; j < map_cpy.nb_case_y; j++) {
			map_cpy.tab[i][j].type = map->tab[i][j].type;
			map_cpy.tab[i][j].color = map->tab[i][j].color;
		}
	}
	return (map_cpy);
}
