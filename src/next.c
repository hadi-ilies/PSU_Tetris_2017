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

int create_next()
{
	int next = rand() % (count_file() - 2);

	return (next);
}

void display_next(game_t *game)
{
	wclear(game->win.next_i);
	wborder(game->win.next_i, '|', '|', '-', '-', '/', '\\', '\\', '/');//car clear enleve les bord
	game->rand_next == game->move.nb_tet ? game->rand_next = 2 : 0; // a revoir
	mvwprintw(game->win.next_i, 0, 5, "<Next>");
	set_color(game->win.next_i, game->tetrominos[game->rand_next].color);
	for (int i = 0; i < game->tetrominos[game->rand_next].y; i++) {
		mvwprintw(game->win.next_i, 10 / 2 - game->tetrominos[game->rand_next].y / 2 + i,
			20 / 2 - (game->tetrominos[game->rand_next].x / 2), game->tetrominos[game->rand_next].item[i]);
	}
	wattroff(game->win.next_i, COLOR_PAIR(game->tetrominos[game->rand_next].color));
}
