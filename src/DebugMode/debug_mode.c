/*
** EPITECH PROJECT, 2018
** debug
** File description:
** debug
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include <fcntl.h>
#include "macros.h"
#include "prototype.h"

void debug_mode(char **argv, int argc)
{
	mode(1);
	item_t *item = create_item();

	my_printf(1, "*** DEBUG MODE ***\n");
	debug_mode_2(argv, argc, item);
}

char *display_name(char *str)
{
	char *S1 = my_malloc(sizeof(char) * my_strlen(str));
	int i = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '.' && my_strncmp(str + i, ".tetrimino", 11) == 0)
			break;
		S1[i] = str[i];
	}
	S1[i] = '\0';
	return (S1);
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
	debug_mode_3(sort_debug(item));
}

void display_tetri_debug(item_t *item, int i)
{
	for (int j = 0; j < item[i].y; j++)
		my_printf(1, "%s\n", item[i].item[j]);
}

void debug_mode_3(item_t *item)
{
	char buff[3] = {'\0'};

	for (int i = 0; i < count_file(); i++) {
		if (item[i].x == -1)
			my_printf(1, "Tetriminos : Name %s : Error\n", D_N);
		else {
			DISPLAY_NAME_AND_SIZE;
			my_printf(1, " : Color %d :\n", item[i].color);
			display_tetri_debug(item, i);
		}
	}
	my_printf(1, "Press any key to start Tetris\n");
	while (buff[0] == '\0')
		read(0, buff, 3);
	mode(0);
}
