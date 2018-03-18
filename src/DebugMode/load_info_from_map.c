/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>
#include "my.h"
#include "prototype.h"
#include "macros.h"

void purge_str(item_t *item, int *i, int fd)
{
	char **array = my_str_to_word_array(item[*i].str);

	item[*i].x = my_atoi(array[0]);
	item[*i].y = my_atoi(array[1]);
	if (item[*i].x <= 0 || item[*i].y <= 0) {
		item[*i].x = -1;
		return;
	}
	item[*i].color = my_atoi(array[2]);
	item[*i].str = get_next_line(fd);
	item[*i].item = mem_alloc_2d_array(item[*i].y, item[*i].x);
	for (int j = 0; item[*i].str != NULL; j++) {
		item[*i].item[j] = item[*i].str;
		item[*i].str = get_next_line(fd);
	}
}

bool check_file(item_t *item, int *i)
{
	if (item[*i].str == NULL)
		return (false);
	char **array = my_str_to_word_array(item[*i].str);

	if (array[1] == NULL || array[2] == NULL)
		return (false);
	for (int k = 0; array[k] != NULL; k++)
		for (int j = 0; array[k][j] != '\0'; j++)
			if (array[k][j] < '0' || array[k][j] > '9')
				return (false);
	return (true);
}

void init_item(item_t *item)
{
	int fd = 0;
	char *str;

	for (int i = 0; i < count_file(); i++) {
		str = concat("tetriminos/", item[i].filename);
		fd = open(str, O_RDONLY);
		fd == -1 ? exit(84) : 0;
		item[i].str = get_next_line(fd);
		item[i].coord_x = 3;
		item[i].coord_y = 3;
		check_file(item, &i) == false ? item[i].x = -1 :
			(purge_str(item, &i, fd));
	}
}

item_t *create_item(void)
{
	item_t *item = my_malloc(sizeof(item_t) * (count_file() + 1));

	for (int i = 0; i < count_file(); i++)
		item[i].filename = my_malloc(sizeof(char) * 30);
	take_filename(item);
	init_item(item);
	return (item);
}

int count_file(void)
{
	int nb_file = 0;
	DIR *dir = NULL;
	struct dirent *d;

	dir = opendir("tetriminos");
	if (dir == NULL)
		exit(84);
	while ((d = readdir(dir))) {
		(d == NULL) ? exit(84) : 0;
		if (d->d_name[0] != '.' && T_FILE)
			nb_file++;
	}
	closedir(dir);
	return (nb_file);
}
