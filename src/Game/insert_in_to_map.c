/*
** EPITECH PROJECT, 2018
** insert
** File description:
** insert
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"
#include "map.h"
#include "macros.h"

void insert_base_ter(item_t *cp_tetr, map_t *game_map, game_t *game)
{
	for (int i = 0; i < cp_tetr[ID].y; i++)
		for (int j = 0; cp_tetr[ID].item[i][j] != '\0'; j++) {
			INSERT_IN_MAP;
			game_map->tab[j + C_X][i + C_Y].color = COLOR;
		}
}
