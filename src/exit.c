/*
** EPITECH PROJECT, 2018
** quit
** File description:
** quit
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"
#include "map.h"

int exit_game(char key[4], game_t *game)
{
	if (read(0, key, 3) == 1 && key[0] == game->key.key_quit) {
		mode(0);
		delwin(game->win.win);
		delwin(game->win.score);
		delwin(game->win.title);
		endwin();
		return (1);
	} else
		return (0);
}
