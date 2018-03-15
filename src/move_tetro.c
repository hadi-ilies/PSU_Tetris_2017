/*
** EPITECH PROJECT, 2018
** move_tetro
** File description:
** move_tetro
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"
#include "map.h"
#include "macros.h"
/*
void increase_speed(game_t *game, item_t *cp_tetr)
{
	game->key.level == '1' ?  : 0;
	game->key.level == '2' ?  : 0;
	game->key.level == '3' ?  : 0;
	game->key.level == '4' ?  : 0;
	game->key.level == '5' ?  : 0;
	game->key.level == '6' ?  : 0;
	game->key.level == '7' ?  : 0;
	game->key.level == '8' ?  : 0;
	game->key.level == '9' ?  : 0;
}
*/

int move_tetro_auto(game_t *game, item_t *cp_tetr, map_t *game_map) // a la normes!!!
{
	static int clk_start = -1;
/*mettre une clock*/
	if (time(NULL) != clk_start) {
		cp_tetr[game->move.nb_tet].coord_y++;
		clk_start = time(NULL);
	}
	werase(game->win.win);
	if (tetro_colision(game, cp_tetr, game_map) == 1
	&& cp_tetr[game->move.nb_tet].coord_y == 1) {
		game_over(game);
		return (1);
	} if (C_Y >= WIN_HEIGHT - cp_tetr[game->move.nb_tet].y
	|| tetro_colision(game, cp_tetr, game_map) == 1) {
		insert_base_ter(cp_tetr, game_map, game);
		C_Y = 0;
		C_X = 3;
		game->move.nb_tet = game->rand_next;
	}
	return (-1);
}

void move_tetro_drop(game_t *game, item_t *cp_tetr, map_t *game_map)
{
	for (int k = C_Y; k < (int)game_map->nb_case_y; k++) {
		for (int i = 0; i < cp_tetr[game->move.nb_tet].y; i++)
			for (int j = 0; game->tetrominos[game->move.nb_tet].item[i][j] != '\0'; j++) {
				if (game_map->tab[j + C_X][i + k + 1].type == '*'
				&& game->tetrominos[game->move.nb_tet].item[i][j] == '*') {
					C_Y = k;
					return;
				}
			}
	}
	C_Y = WIN_HEIGHT - 3; // revoir
}

void move_tetro_right(game_t *game, item_t *cp_tetr, map_t *game_map)
{
	if (C_X >= WIN_WIDTH - cp_tetr[game->move.nb_tet].x
	|| tetro_colision_r_l(game, cp_tetr, game_map) == 1)
		C_X = WIN_WIDTH - cp_tetr[game->move.nb_tet].x;
	else
		C_X++;
	werase(game->win.win);
}

void move_tetro_left(game_t *game, item_t *cp_tetr, map_t *game_map)
{
	if (C_X <= 0 || tetro_colision_r_l(game, cp_tetr, game_map) == 2)
		C_X = 0;
	else
		C_X--;
	werase(game->win.win);
}
