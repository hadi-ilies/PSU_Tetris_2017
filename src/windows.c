/*
** EPITECH PROJECT, 2018
** win
** File description:
** win
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

void create_border(game_t *game)
{
	wborder(game->win.win, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(game->win.score, '|', '|', '-', '-', '/', '\\', '\\', '/');
	game->next == true ? wborder(game->win.next_i, '|', '|', '-', '-', '/', '\\', '\\', '/') : 0;
	wborder(game->win.title, '|', '|', '-', '-', '/', '\\', '\\', '/');
}

void refresh_win(game_t *game)
{
	wrefresh(game->win.title);
	wrefresh(game->win.score);
	game->next == true ? wrefresh(game->win.next_i) : 0;
	wrefresh(game->win.win);
}

void initi_win(game_t *game)
{
	game->win.win = newwin(game->size_height, game->size_width, (LINES / 2) - game->size_height, (COLS / 2));
	game->win.score = newwin(20, 10 + (COLS / 4), LINES/2, 0);
	game->next == true ? game->win.next_i = newwin(10, 20, 0, COLS - game->size_height) : 0;
	game->win.title = newwin(15, 50, 0, 0);//
	refresh();
}
