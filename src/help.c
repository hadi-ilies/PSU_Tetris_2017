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

bool help(void)
{
	printf("USAGE: ./tetris [options]\n");
	printf("Options:\nhelp               Display this help\n");
	printf("-l level={num}     Start Tetris at level num (def: 1)\n");
	printf("-kl key-left={K}   Move the tetrimino LEFT using the K ");
	printf("key (def: left arrow)\n");
	printf("-kr key-right={K}  Move the tetrimino RIGHT using the K");
	printf("key (def: right arrow)\n");
	printf("-kt key-turn={K}   TURN the tetrimino clockwise 90d using");
	printf("the K key (def: top arrow)\n");
	printf("-kd key-drop={K}   DROP the tetrimino using the K key (d");
	printf("ef: down arrow)\n-kq key-quit={K}   QUIT the game using th");
	printf("e K key (def: `q' key)\n-kp key-pause={K}  PAUSE/RESTART t");
	printf("he game using the K key (def: space bar)\n");
	printf("-map-size={row,col} Set the numbers of rows and columns of");
	printf(" the map (def: 20,10)\n");
	printf("-w without-next    Hide next tetrimino (def: false)\n");
	printf("-d debug           Debug mode (def: false)\n");
	return (true);
}
