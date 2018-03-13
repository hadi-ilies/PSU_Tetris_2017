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

int *sort_debug(item_t *item)
{
	int *sort = my_malloc(sizeof(int) * (count_file() + 1));
	int i = 0;

	for (i = 0; i < count_file(); i++) {
		if (item[i].filename[0] <= '9' && item[i].filename[0] >= '0')
			sort[i] = item[i].filename[0] - '0';
		else
			sort[i] = item[i].filename[0];
	}
	sort_b(sort, i);
	return (sort);
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
	sort_debug(item);
	debug_mode_3(argv, item, sort_debug(item));
}

//je vais le remettre a la norme si ca passes a la mouli
void debug_mode_3(char **argv, item_t *item, int *sort)
{
	char buff[3] = {0};

	for (int i = 0; i < count_file(); i++) {
		for (int j = 0; j < count_file(); j++) {
			if (item[j].filename[0] <= '9' && item[j].filename[0] >= '0') {
				if (sort[i] == item[j].filename[0] - '0') {
					if (item[j].x == -1)
						printf("Tetriminos : Name %s : Error\n", D_N);
					else {
						printf("Tetriminos : Name %s : Size %d*%d",  D_N, item[j].x, item[j].y);
						printf(" : Color %d :\n", item[j].color);
						for (int k = 0; k < item[j].y; k++)
							printf("%s\n", item[j].item[k]);
					}
				}
			}
			else if (sort[i] == item[j].filename[0]) {
				if (item[j].x == -1)
						printf("Tetriminos : Name %s : Error\n", D_N);
					else {
						printf("Tetriminos : Name %s : Size %d*%d",  D_N, item[j].x, item[j].y);
						printf(" : Color %d :\n", item[j].color);
						for (int k = 0; k < item[j].y; k++)
							printf("%s\n", item[j].item[k]);
					}
			}
		}
	}
	printf("Press any key to start Tetris\n");
	while (buff[0] == 0) {
		read(0, buff, 10);
		//printf("%d, %d, %d\n", buff[0], buff[1], buff[2]);
	}
}







/*if (item[i].x == -1)
  printf("Tetriminos:  Name %s : Error\n", D_N);
  else {
  printf("Tetriminos:  Name %s : Size %d*%d",  D_N, item[i].x, item[i].y);
  printf(": Colors %d :\n", item[i].color);
  for (int j = 0; j < item[i].y; j++)
  printf("%s\n", item[i].item[j]);
  }
  }
  printf("Press any key to start Tetris\n");
  while (str == NULL)
  str = get_next_line(0);

  }*/
