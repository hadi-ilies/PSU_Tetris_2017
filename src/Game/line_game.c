/*
** EPITECH PROJECT, 2018
** line
** File description:
** line
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"
#include "map.h"
#include "macros.h"

void line_down(map_t *game_map, int line)
{
	for (int j = line; j > 0; j--)
		for (int i = 0; i < (int)game_map->nb_case_x; i++)
			game_map->tab[i][j] = game_map->tab[i][j - 1];
}

void check_line(game_t *game, map_t *game_map)
{
	for (int j = 0; j < (int)game_map->nb_case_y; j++) {
		int line_filled = 0;

		for (int i = 0; i < (int)game_map->nb_case_x; i++)
			game_map->tab[i][j].type != ' ' ? line_filled++ : 0;
		if (line_filled == (int)game_map->nb_case_x) {
			for (int i = 0; i < (int)game_map->nb_case_x; i++)
				game_map->tab[i][j].type = ' ';
			line_down(game_map, j);
			add_score(game);
		}
	}
}
