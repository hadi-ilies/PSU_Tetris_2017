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

	game.key_left = save_keyleft(argv, argc);
	game.key_right = save_keyright(argv, argc);
	game.key_turn = save_keyturn(argv, argc);
	game.key_drop = save_keydrop(argv, argc);
	game.key_quit = save_keyquit(argv, argc);
	game.key_pause = save_keypause(argv, argc);
	game.next = save_without_next(argv, argc);
	game.level = save_level(argv, argc);
	game.size_height = save_mapsize_height(argv, argc);
	game.size_width = save_mapsize_width(argv, argc);
	game.tetrominos = create_item();
	return (game);
}
