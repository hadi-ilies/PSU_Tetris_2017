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
	my_printf(1, " -r --key-right={K}\tMove the tetrimino RIGHT using the K");
	my_printf(1, " key (def: right arrow)\n");
	my_printf(1, " -t --key-turn={K}\tTURN the tetrimino clockwise 90d using");
	my_printf(1, " the K key (def: top arrow)\n");
	my_printf(1, " -d --key-drop={K}\tDROP the tetrimino using the K key");
	my_printf(1, " (def: down arrow)\n -q key-quit={K}\tQUIT the game using th");
	my_printf(1, "e K key (def: `q' key)\n -p key-pause={K}\tPAUSE/RESTART t");
	my_printf(1, "he game using the K key (def: space bar)\n");
	my_printf(1, " --map-size={row,col}\tSet the numbers of rows and columns of");
	my_printf(1, " the map (def: 20,10)\n");
	my_printf(1, " -w --without-next\tHide next tetrimino (def: false)\n");
	my_printf(1, " -D --debug\t\tDebug mode (def: false)\n");
	return (false);
}
