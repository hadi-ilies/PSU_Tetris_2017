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
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include "my.h"
#include <fcntl.h>
#include "macros.h"
#include "prototype.h"

void debug_mode(char **argv, int argc)
{
	item_t *item = create_item();

	printf("*** DEBUG MODE ***\n");
	debug_mode_2(argv, argc, item);
}

char *display_name(char *str)
{
	char *S1 = my_malloc(sizeof(char) * my_strlen(str)); //strlen faut quil sarrete au point
	int i = 0;

	for (i = 0; str[i] != '.'; i++)
		S1[i] = str[i];
	S1[i] = '\0';
	return (S1);
}

void swap_elem(item_t *array, int index1, int index2)
{
	item_t a = array[index1];

	array[index1] = array[index2];
	array[index2] = a;
}

item_t *sort_debug(item_t *item)
{
	for (int i = 0; i < count_file(); i++)
		for (int j = i + 1; j < count_file(); j++)
			if (my_strcmp(item[i].filename, item[j].filename) >= 0)
				swap_elem(item, i, j);
	return (item);
}
void debug_mode_2(char **argv, int argc, item_t *item)
{
	keyleft(argv, argc);
	keyright(argv, argc);
	keyturn(argv, argc);
	keydrop(argv, argc);
	keyquit(argv, argc);
	keypause(argv, argc);
	without_next(argv, argc);
	level(argv, argc);
	mapsize(argv, argc);
	my_printf(1, "Tetriminos : %d\n", count_file());
	debug_mode_3(argv, sort_debug(item));
}

void debug_mode_3(char **argv, item_t *item)
{
	char buff[3] = {0};

	for (int i = 0; i < count_file(); i++) {
		if (item[i].x == -1)
			my_printf(1, "Tetriminos : Name %s : Error\n", D_N);
		else {
			my_printf(1, "Tetriminos : Name %s : Size %d*%d",  D_N, item[i].x, item[i].y);
			my_printf(1, " : Color %d :\n", item[i].color);
			for (int j = 0; j < item[i].y; j++)
				my_printf(1, "%s\n", item[i].item[j]);
		}
	}
	my_printf(1, "Press any key to start Tetris\n");
	while (buff[0] == 0)
		read(0, buff, 3);
}
