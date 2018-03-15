/*
** EPITECH PROJECT, 2018
** colisions
** File description:
** colisions
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"
#include "map.h"
#include "macros.h"

int tetro_colision_r_l(game_t *game, item_t *cp_tetr, map_t *game_map)
{
	for (int i = 0; i < cp_tetr[game->move.nb_tet].y; i++)
		for (int j = 0; game->tetrominos[game->move.nb_tet].item[i][j] != '\0'; j++) {
			if (C_X > 0 && game_map->tab[j + C_X - 1][i + C_Y].type == '*'
			&& game->tetrominos[game->move.nb_tet].item[i][j] == '*')
				return (1);
			if (C_X < WIN_WIDTH
			&& game_map->tab[j + C_X][i + C_Y - 1].type == '*'
			&& game->tetrominos[game->move.nb_tet].item[i][j] == '*')
				return (2);
		}
	return (0);
}

int tetro_colision(game_t *game, item_t *cp_tetr, map_t *game_map)
{
	for (int i = 0; i < cp_tetr[game->move.nb_tet].y; i++)
		for (int j = 0; game->tetrominos[game->move.nb_tet].item[i][j] != '\0'; j++) {
			if (game_map->tab[j + C_X][i + C_Y + 1].type == '*'
			&& game->tetrominos[game->move.nb_tet].item[i][j] == '*')
				return (1);
		}
	return (0);
}
