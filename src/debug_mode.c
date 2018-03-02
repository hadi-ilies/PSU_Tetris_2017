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
	printf("Tetriminos:  %d\n", count_file());
	debug_mode_3(argv, item);
}

void debug_mode_3(char **argv, item_t *item)
{
	char *str = NULL;

	for (int i = 0; i < count_file(); i++) {
		printf("Tetriminos:  Name : %s : Size %d*%d",  D_N, item[i].x, item[i].y);
		printf(": Colors %d :\n", item[i].color);
		for (int j = 0; j < item[i].y; j++)
			printf("%s\n", item[i].item[j]);
	}
	printf("Press any key to start Tetris\n");
	while (str == NULL)
		str = get_next_line(0);
}
