/*
** EPITECH PROJECT, 2018
** colors
** File description:
** colors
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

void set_color_without_win(int color)
{
	start_color();
	init_pair(1, COLOR_RED, 0);
	init_pair(2, COLOR_GREEN, 0);
	init_pair(3, COLOR_YELLOW, 0);
	init_pair(4, COLOR_BLUE, 0);
	init_pair(5, COLOR_MAGENTA, 0);
	init_pair(6, COLOR_CYAN, 0);
	init_pair(7, COLOR_WHITE, 0);
	attron(COLOR_PAIR(color));
}

void set_color(WINDOW *win, int color)
{
	start_color();
	init_pair(1, COLOR_RED, 0);
	init_pair(2, COLOR_GREEN, 0);
	init_pair(3, COLOR_YELLOW, 0);
	init_pair(4, COLOR_BLUE, 0);
	init_pair(5, COLOR_MAGENTA, 0);
	init_pair(6, COLOR_CYAN, 0);
	init_pair(7, COLOR_WHITE, 0);
	wattron(win, COLOR_PAIR(color));
}

void check_error_color(void)
{
	if (!has_colors()) {
		my_printf(1, "Terminal does not support color\n");
		exit(84);
	}
}
