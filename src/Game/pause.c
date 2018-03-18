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
#include "macros.h"

void my_sleep_pause(char key[4], game_t *game)
{
	while (1)
		if (read(0, key, 3) == 1 && key[0] == game->key.key_pause) {
			clear();
			refresh();
			break;
		}
}

void display_pause_grafiti(void)
{
	char **pause_m = map_cr(PAUSE);

	clear();
	for (int i = 0; i < count_row_map(PAUSE); i++) {
		set_color_without_win(i);
		DISPLAY_PAUSE;
	}
	refresh();
}

void pause_key(char key[4], game_t *game)
{
	if (key[0] == game->key.key_pause) {
		display_pause_grafiti();
		my_sleep_pause(key, game);
		clear();
	}
}
