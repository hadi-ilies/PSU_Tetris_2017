/*
** EPITECH PROJECT, 2018
** next
** File description:
** next
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "prototype.h"
#include "macros.h"

int create_next(game_t *game)
{
	int next = rand() % (count_file());

	if (game->tetrominos[next].x == -1)
		next = ID;
	return (next);
}

void display_next(game_t *game)
{
	wclear(game->win.next_i);
	BORDER_WIN_NEXT;
	mvwprintw(game->win.next_i, 0, 5, "<Next>");
	set_color(game->win.next_i, game->tetrominos[game->rand_next].color);
	for (int i = 0; i < game->tetrominos[game->rand_next].y; i++)
		DISPLAY_NEXT;
	wattroff(game->win.next_i,
	COLOR_PAIR(game->tetrominos[game->rand_next].color));
}
