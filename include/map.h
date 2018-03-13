/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** map.h
*/

#pragma once

#include <stddef.h>

typedef struct
{
	char type;
	char color;
} tab_t;

typedef struct
{
	size_t nb_case_x;
	size_t nb_case_y;
	tab_t **tab;
} map_t;

map_t map_create(size_t nb_case_x, size_t nb_case_y);
map_t map_copy(map_t *map);
map_t map_destroy(map_t *map);
map_t map_aff(map_t *map, size_t x, size_t y);
