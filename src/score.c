/*
** EPITECH PROJECT, 2018
** score
** File description:
** score
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

void display_score(game_t *game)
{
	static int clk_start = -1;
	int clk = time(NULL);

	clk_start == -1 ? clk_start = time(NULL) : 0;
	mvwprintw(game->win.score, 2, 1, "High Score:\t%d", 1);
	mvwprintw(game->win.score, 4, 1, "Score:\t%d", 1);
	mvwprintw(game->win.score, 8, 1, "Lines:\t%d", 1);
	mvwprintw(game->win.score, 10, 1, "Level:\t%d", game->key.level - '0');
	mvwprintw(game->win.score, 14, 1, "Timer:\t%.2d:%.2d", (clk - clk_start) / 60, (clk - clk_start)% 60);
}
