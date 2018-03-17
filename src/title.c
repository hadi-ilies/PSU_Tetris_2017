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
#include "macros.h"

void display_title(game_t *game)
{
	char **title = map_cr("titre");
	static int j = 1;
	static int cl = -1;

	time(NULL) != cl || !(rand() % 500) ? set_color(game->win.title, j) : 0;
	cl = time(NULL);
	for (int i = 0; i < count_row_map("titre"); i++)
		DISPLAY_TITLE;
	j == 7 ? j = 1 : j++;
}
