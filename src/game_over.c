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
	mvwprintw(game->win.game_over, 14, 1, "Timer:\t%.2d:%.2d", game->time);
	wrefresh(game->win.game_over);
}

void game_over(game_t *game)
{
	char **gameover = map_cr("game_over");
	char key[10] = {'\0'};

	clear();
	for (int i = 0; i < count_row_map("game_over"); i++) {
		set_color_without_win(i);
		mvprintw(LINES / 2 - count_row_map("game_over") / 2 + i,
		COLS / 2 - (count_col_map("game_over") / 2), gameover[i]);
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
