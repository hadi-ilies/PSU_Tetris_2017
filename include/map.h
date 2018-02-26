/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** map.h
*/

#ifndef MAP_H_
#define MAP_H_

#include <stdlib.h>

typedef struct {
	char type;
	char color;
} tab_t;

typedef struct {
	size_t nb_case_x;
	size_t nb_case_y;
	tab_t **tab;
} map_t;

map_t map_create(size_t nb_case_x, size_t nb_case_y);
map_t map_copy(map_t *map);
map_t map_destroy(map_t *map);
map_t map_aff(map_t *map);

#endif
