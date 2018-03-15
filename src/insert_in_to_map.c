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
	for (int i = 0; i < cp_tetr[game->move.nb_tet].y; i++)
		for (int j = 0; game->tetrominos[game->move.nb_tet].item[i][j] != '\0'; j++) {
			game->tetrominos[game->move.nb_tet].item[i][j] == '*' ?	game_map->tab[j + C_X][i + C_Y].type = game->tetrominos[game->move.nb_tet].item[i][j] : 0;
			game_map->tab[j + C_X][i + C_Y].color = game->tetrominos[game->move.nb_tet].color;
		}
}
