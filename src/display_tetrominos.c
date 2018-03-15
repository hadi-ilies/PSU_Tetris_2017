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
	for (int i = 0; i < (int)game_map->nb_case_x; i++) {
		for (int j = 0; j < (int)game_map->nb_case_y; j++) {
			game_map->tab[i][j].type == '*' ?
			set_color(game->win.win, game_map->tab[i][j].color) : 0;
			game_map->tab[i][j].type == '*' ?
			mvwprintw(game->win.win, j + 1, i + 1, "%c", game_map->tab[i][j]) : 0;
			game_map->tab[i][j].type == '*' ?
			wattroff(game->win.win, COLOR_PAIR(1)) : 0;
		}
	}
}

void display_tetro(game_t *game, item_t *cp_tetr)
{
	for (int i = 0; i < game->tetrominos[game->move.nb_tet].y; i++)
		for (int j = 0; j < game->tetrominos[game->move.nb_tet].x; j++)
			game->tetrominos[game->move.nb_tet].item[i][j] == '*' ? mvwprintw(game->win.win, cp_tetr[game->move.nb_tet].coord_y + i + 1, cp_tetr[game->move.nb_tet].coord_x + j + 1, "%c", game->tetrominos[game->move.nb_tet].item[i][j]) : 0;
}
