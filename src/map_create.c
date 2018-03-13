/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** map_create.c
*/

#include "map.h"
#include "my.h"

map_t map_create(size_t nb_case_x, size_t nb_case_y)
{
	map_t map = {.nb_case_x = nb_case_x, .nb_case_y = nb_case_y};

	map.tab = my_malloc(sizeof(tab_t *) * map.nb_case_x);
	for (size_t i = 0; i < map.nb_case_x; i++) {
		map.tab[i] = my_malloc(sizeof(tab_t) * map.nb_case_y);
		for (size_t j = 0; j < map.nb_case_y; j++) {
			map.tab[i][j].type = 0;
			map.tab[i][j].color = 0;
		}
	}
	return (map);
}
