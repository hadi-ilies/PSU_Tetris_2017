/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** map.h
*/

#pragma once

#include <stddef.h>
#include "my.h"

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
