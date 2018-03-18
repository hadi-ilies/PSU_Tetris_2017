/*
** EPITECH PROJECT, 2018
** create
** File description:
** create
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

game_t game_create(int argc, char **argv)
{
	game_t game;

	game.rand_next = 0;
	game.key.ke_left = save_keyleft(argv, argc);
	game.key.ke_right = save_keyright(argv, argc);
	game.key.key_turn = save_keyturn(argv, argc);
	game.key.key_drop = save_keydrop(argv, argc);
	game.key.key_quit = save_keyquit(argv, argc);
	game.key.key_pause = save_keypause(argv, argc);
	game.key.next = save_without_next(argv, argc);
	game.key.level = save_level(argv, argc);
	game.key.size_height = save_mapsize_height(argv, argc);
	game.key.size_width = save_mapsize_width(argv, argc);
	game.tetrominos = create_item();
	game.move.x = game.tetrominos[0].x;
	game.move.y = game.tetrominos[0].y;
	game.move.nb_tet = 0;
	game.score = 0;
	return (game);
}
