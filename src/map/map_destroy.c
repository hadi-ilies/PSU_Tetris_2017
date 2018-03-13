/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** map_destroy.c
*/

#include <stdlib.h>
#include "map.h"

void map_destroy(map_t *map)
{
	for (size_t i = 0; i < map->nb_case_x; i++)
		free(map->tab[i]);
	free(map->tab);
}
