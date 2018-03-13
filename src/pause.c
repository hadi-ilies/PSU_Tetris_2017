/*
** EPITECH PROJECT, 2018
** pause
** File description:
** pause
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"
#include "map.h"

void my_sleep_pause(char key[10], game_t *game)
{
	while (1)
		if (read(0, key, 3) == 1 && key[0] == game->key.key_pause) {
			clear();
			break;
		}
}

void display_pause_grafiti(void)
{
	char **pause_m = map_cr("pause");

	clear();
	for (int i = 0; i < count_row_map("pause"); i++) {
		set_color_without_win(i);
		mvprintw(LINES / 2 - count_row_map("pause") / 2 + i,
			COLS / 2 - (count_col_map("pause") / 2), pause_m[i]);
		refresh();
	}
}

void pause_key(char key[10], game_t *game)
{
	if (read(0, key, 3) == 1 && key[0] == game->key.key_pause) {
		display_pause_grafiti();
		my_sleep_pause(key, game);
		clear();
	}
}
