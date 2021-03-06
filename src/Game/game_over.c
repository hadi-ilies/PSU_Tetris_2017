/*
** EPITECH PROJECT, 2018
** game_ver
** File description:
** game_over
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"
#include "map.h"
#include "macros.h"

void display_stat(game_t *game)
{
	game->win.game_over =  newwin(20, 10 + (COLS / 4), 0, 0);
	wborder(game->win.game_over, '|', '|', '-', '-', '/', '\\', '\\', '/');
	wrefresh(game->win.game_over);
	mvwprintw(game->win.game_over, 2, 1, "High Score:\t%d",
		best_score(game));
	mvwprintw(game->win.game_over, 4, 1, "Score:\t%d", game->score);
	mvwprintw(game->win.game_over, 10, 1, "Level:\t%d",
		game->key.level);
	mvwprintw(game->win.game_over, 14, 1, "Timer:\t%.2d:%.2d",
		game->time / 60 , game->time % 60);
	wrefresh(game->win.game_over);
}

void game_over(game_t *game)
{
	char **gameover = map_cr(OVER);
	char key[4] = {'\0'};

	clear();
	for (int i = 0; i < count_row_map(OVER); i++) {
		set_color_without_win(i);
		DISPLAY_GAMEOVER;
	}
	refresh();
	display_stat(game);
	while (1)
		if (read(0, key, 3) == 1 && key[0] == game->key.key_quit) {
			mode(0);
			delwin(game->win.win);
			delwin(game->win.score);
			delwin(game->win.title);
			delwin(game->win.game_over);
			endwin();
			break;
		}
}
