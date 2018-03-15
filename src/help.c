/*
** EPITECH PROJECT, 2018
** help
** File description:
** help
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include "my.h"

bool help(char **argv)
{
	my_printf(1, "USAGE:\t%s [options]\n", argv[0]);
	my_printf(1, "Options:\n --help\t\t\tDisplay this help\n");
	my_printf(1, " -L --level={num}\tStart Tetris at level num (def: 1)\n");
	my_printf(1, " -l --key-left={K}\tMove the tetrimino LEFT using the K");
	my_printf(1, " key (def: left arrow)\n");
	my_printf(1, " -r --key-right={K}\tMove the tetrimino RIGHT using");
	my_printf(1, " the K key (def: right arrow)\n");
	my_printf(1, " -t --key-turn={K}\tTURN the tetrimino clockwise 90d");
	my_printf(1, " using the K key (def: top arrow)\n");
	my_printf(1, " -d --key-drop={K}\tDROP the tetrimino using the K key");
	my_printf(1, " (def: down arrow)\n -q key-quit={K}\tQUIT the game");
	my_printf(1, " using the K key (def: `q' key)\n -p key-pause={K}\t");
	my_printf(1, "PAUSE/RESTART the game using the K key (def: space");
	my_printf(1, " bar)\n --map-size={row,col}\tSet the numbers of");
	my_printf(1, " rows and columns of the map (def: 20,10)\n");
	my_printf(1, " -w --without-next\tHide next tetrimino (def: false)\n");
	my_printf(1, " -D --debug\t\tDebug mode (def: false)\n");
	return (false);
}
