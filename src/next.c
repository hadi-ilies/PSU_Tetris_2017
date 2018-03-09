/*
** EPITECH PROJECT, 2018
** next
** File description:
** next
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include "my.h"
#include "prototype.h"

int display_next(game_t *game, int j)
{
	srand(time(NULL));
	int next = rand() % (count_file() - 2);

	wclear(game->win.next_i);
	wborder(game->win.next_i, '|', '|', '-', '-', '/', '\\', '\\', '/');//car clear enleve les bord
	next == j ? next = 2 : 0; // a revoir
	mvwprintw(game->win.next_i, 0, 5, "<Next>");
	set_color(game->win.next_i, game->tetrominos[next].color);
	for (int i = 0; i < game->tetrominos[next].y; i++) {
		mvwprintw(game->win.next_i, 10 / 2 - game->tetrominos[next].y / 2 + i,
			20 / 2 - (game->tetrominos[next].x / 2), game->tetrominos[next].item[i]);
	}
	wattroff(game->win.next_i, COLOR_PAIR(game->tetrominos[next].color));
	return (next);
}
