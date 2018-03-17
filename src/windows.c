/*
** EPITECH PROJECT, 2018
** win
** File description:
** win
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include "my.h"
#include "prototype.h"
#include "macros.h"

void display_windows(game_t *game)
{
	ID == game->rand_next
		? game->rand_next = create_next(game) : 0;
	display_title(game);
	game->key.next == true ? display_next(game) : 0;
	display_score(game);
	refresh_win(game);
}

void create_border(game_t *game)
{
	BORDER_WIN_WIN;
	BORDER_WIN_SCORE;
	game->key.next == true ? BORDER_WIN_NEXT : 0;
	BORDER_WIN_TITLE;
}

void refresh_win(game_t *game)
{
	wrefresh(game->win.title);
	wrefresh(game->win.score);
	game->key.next == true ? wrefresh(game->win.next_i) : 0;
	wrefresh(game->win.win);
}

void initi_win(game_t *game)
{
	game->win.win = newwin(WIN_HEIGHT + 2, WIN_WIDTH + 2,
			(LINES / 2) - WIN_HEIGHT, (COLS / 2));
	game->win.score = newwin(20, 10 + (COLS / 4), LINES / 2, 0);
	game->key.next == true ?
		game->win.next_i = newwin(10, 20, 0, COLS - WIN_HEIGHT) : 0;
	game->win.title = newwin(15, 50, 0, 0);
}
