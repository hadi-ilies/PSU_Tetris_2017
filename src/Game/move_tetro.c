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

void speed_tetro(game_t *game, item_t *cp_tetr)
{
	static clock_t clk_start = -1;
	const int temp = 50000;

	if (clock() > clk_start + temp * (9 - game->key.level)) {
		cp_tetr[ID].coord_y++;
		clk_start = clock();
	}
}

int move_tetro_auto(game_t *game, item_t *cp_tetr, map_t *game_map)
{
	speed_tetro(game, cp_tetr);
	werase(game->win.win);
	if (tetro_colision(game, cp_tetr, game_map) == 1
	&& cp_tetr[ID].coord_y == 1) {
		game_over(game);
		return (1);
	} if (C_Y >= WIN_HEIGHT - cp_tetr[ID].y
	|| tetro_colision(game, cp_tetr, game_map) == 1) {
		insert_base_ter(cp_tetr, game_map, game);
		cp_tetr[ID] = game->tetrominos[ID];
		C_Y = 0;
		C_X = WIN_WIDTH / 2;
		ID = game->rand_next;
	}
	return (-1);
}

void move_tetro_drop(game_t *game, item_t *cp_tetr, map_t *game_map)
{
	for (int k = C_Y; k < (int)game_map->nb_case_y; k++) {
		for (int i = 0; i < cp_tetr[ID].y; i++)
			for (int j = 0; cp_tetr[ID].item[i][j] != '\0'; j++) {
				if (COND_DROP) {
					C_Y = k;
					return;
				}
			}
	}
}

void move_tetro_right(game_t *game, item_t *cp_tetr, map_t *game_map)
{
	if (C_X >= WIN_WIDTH - cp_tetr[ID].x
	|| tetro_colision_r_l(game, cp_tetr, game_map) == 1)
		C_X = WIN_WIDTH - cp_tetr[ID].x;
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
