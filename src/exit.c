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

int exit_game(char key[10], game_t *game)
{
	if (read(0, key, 3) == 1 && key[0] == game->key.key_quit) {
		mode(0);
		return (1);
	} else
		return (0);
}
