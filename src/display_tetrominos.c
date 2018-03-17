/*
** EPITECH PROJECT, 2018
** display_tetrominos
** File description:
** display_tetrominos
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"
#include "map.h"
#include "macros.h"

void display_tetro_base(game_t *game, map_t *game_map)
{
	for (int i = 0; i < (int)game_map->nb_case_x; i++) {
		for (int j = 0; j < (int)game_map->nb_case_y; j++) {
			game_map->tab[i][j].type == '*' ?
			set_color(game->win.win, game_map->tab[i][j].color) : 0;
			game_map->tab[i][j].type == '*' ? DISPLAY_TETRI_BASE;
			game_map->tab[i][j].type == '*' ?
			wattroff(game->win.win, COLOR_PAIR(1)) : 0;
		}
	}
}

void display_tetro(game_t *game, item_t *cp_tetr)
{
	for (int i = 0; i < cp_tetr[ID].y; i++)
		for (int j = 0; j < cp_tetr[ID].x; j++)
			cp_tetr[ID].item[i][j] == '*' ? DISPLAY_TETRI : 0;
}
