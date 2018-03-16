/*
** EPITECH PROJECT, 2018
** title
** File description:
** title
*/

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "my.h"
#include "prototype.h"

void display_title(game_t *game)
{
	char **title = map_cr("titre");
	static int j = 1;
	static int clk = -1;

	time(NULL) != clk || !(rand() % 500) ? set_color(game->win.title, j) : 0;
	clk = time(NULL);
	for (int i = 0; i < count_row_map("titre"); i++) {
		mvwprintw(game->win.title, 15 / 2 - count_row_map("titre") / 2 + i,
			50 / 2 - (count_col_map("titre") / 2), title[i]);
	}
	j == 7 ? j = 1: j++;
	//wattroff(game->win.title, COLOR_PAIR(1));
}
