/*
** EPITECH PROJECT, 2018
** debug
** File description:
** debug
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

void debug_mode(char **argv)
{
	printf("*** DEBUG MODE ***\n");
	printf("Key Left :  ^EOD\n");
	printf("Key Right :  ^EOC\n");
	printf("Key Turn :  (space)\n");
	printf("Key Drop :  x\n");
	printf("Key Quit :  q\n");
	printf("Key Pause :  p\n");
	printf("Next :  Yes\n");
	printf("Level :  1\n");
	printf("Next :  Yes\n");
	printf("Size :  20*10\n");
}
