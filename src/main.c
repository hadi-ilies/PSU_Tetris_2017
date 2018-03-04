/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** main.c
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

void init_display_screen(char **title, char **map, item_t *item)
{
	initscr();
	curs_set(0);

	for (int i = 0; i < count_row_map("titre"); i++) {
		mvprintw(LINES / 3.5 - count_row_map("titre") / 1 + i,
			(COLS / 3.5) - (count_col_map("titre") / 1), title[i]);
	} for (int i = 0; i < count_row_map("map"); i++) {
		mvprintw(LINES / 2 - count_row_map("map") / 2 + i,
			(COLS/2) - (count_col_map("map") / 2), map[i]);
	} for (int i = 0; i < item[3].y; i++)
		  mvprintw(LINES / 2 - (item[3].y / 2) / 2 + i,
			(COLS/2) - (item[3].x / 2), item[3].item[i]);
	refresh();
}

int item_tetris(int argc, char **argv)
{
	item_t *item = create_item();
	char key[3] = {0, 0, 0};
	int y = item[3].y;
	int x = item[3].x;
	int Y = y;
	char **map = map_cr("map");
	char **title = map_cr("titre");

	//printf("row : %d|col : %d\n", count_row_map("map"), count_col_map("map"));
	init_display_screen(title, map, item);
	while (1) {
		if (read(0, key, 3) == 1 && key[0] == 27)
			break;
		for (int i = 0; i < count_row_map("map"); i++) {
			mvprintw(LINES / 2 - count_row_map("map") / 2 + i,
				(COLS/2) - (count_col_map("map") / 2), map[i]);
		} for (int i = 0; i < Y; i++)
			  mvprintw(LINES / 2 - y / 2 + i,
				(COLS/2) - (x / 2), item[3].item[i]);
		for (int i = 0; i < count_row_map("titre"); i++) {
		mvprintw(LINES / 3.5 - count_row_map("titre") / 1 + i,
			 (COLS / 3.5) - (count_col_map("titre") / 1), title[i]);
		usleep(10000);
		}
		y--;
		//x++;
		refresh();
		clear();
	}
	endwin();
	return (0);
}

int there_is_d(char **argv, int argc)
{
	for (int i = 1; i < argc; i++)
		if (my_strncmp(argv[i], "-D", 3) == 0
		|| my_strncmp(argv[i], "--debug", 8) == 0)
			return (1);
	return (0);
}

int main(int argc, char **argv)
{
	bool bol = false;

	if (my_strncmp(argv[1], "--help", 5) == 0)
		return (help());
	if (parsing(argv, argc) == true)
		return (84);
	if (there_is_d(argv, argc) == 1) {
		debug_mode(argv, argc);
		bol = true;
	} if (bol == true)
		  item_tetris(argc, argv);
}
