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

void display_tetro_base(game_t *game, map_t *game_map)
{
	for (int i = 0; i < game_map->nb_case_x; i++) {
		for (int j = 0; j < game_map->nb_case_y; j++) {
			set_color(game->win.win, game_map->tab[i][j].color);
			mvwprintw(game->win.win, j, i, "%c", game_map->tab[i][j]);
			wattroff(game->win.win, COLOR_PAIR(1));
		}
	}
}

void display_tetro(game_t *game, item_t *cp_tetr)
{
	for (int i = 0; i < game->tetrominos[game->move.nb_tet].y; i++)
		mvwprintw(game->win.win, cp_tetr[game->move.nb_tet].coord_y + i, cp_tetr[game->move.nb_tet].coord_x, game->tetrominos[game->move.nb_tet].item[i]);
}
