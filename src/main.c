/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** main.c
*/

#include "prototype.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include "my.h"

item_t create_item(char **argv)
{
	item_t item;

	item.x = 0;
	item.y = 0;
	item.color = 0;
	item.filename = argv[1];
	item.str = NULL;
	item.item = insert_item(item.filename, &item.x, &item.y, &item.color);
	return (item);
}

int item_tetris(int argc, char **argv)
{
	item_t item = create_item(argv);
	char key[3] = {0, 0, 0};
	int y = item.y;
	int x = item.x;
	int Y = y;

	initscr();
	curs_set(0);
	for (int i = 0; i < Y; i++)
		mvprintw(LINES / 2 - y / 2 + i,
			(COLS/2) - (x / 2), item.item[i]);
	refresh();
	while (1) {
		if (read(0, key, 3) == 1 && key[0] == 27)
			break;
		for (int i = 0; i < Y; i++)
			mvprintw(LINES / 2 - y / 2 + i,
				 (COLS/2) - (x / 2), item.item[i]);
		usleep(10000);
		y--;
		//x++;
		refresh();
		clear();
	}
	endwin();
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (84);
	/*if (my_strncmp(argv[1], "-d", 3) == 0)
		debug_mode(argv);
		return (0);*/
	if (test_file(argv) == false)
		return (84);
	return (item_tetris(argc, argv));
}
