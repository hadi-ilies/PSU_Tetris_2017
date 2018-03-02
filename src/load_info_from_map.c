/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
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

void purge_str(item_t *item, int *i, int fd)
{
	char **array = my_str_to_word_array(item[*i].str);

	item[*i].x = my_atoi(array[0]);
	item[*i].y = my_atoi(array[1]);
	item[*i].color = my_atoi(array[2]);
	item[*i].str = get_next_line(fd);
	item[*i].item = mem_alloc_2d_array(item[*i].y, item[*i].x);
	for (int j = 0; item[*i].str != NULL; j++) {
		item[*i].item[j] = item[*i].str;
		item[*i].str = get_next_line(fd);
	}
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
		purge_str(item, &i, fd);
	}
}

item_t *create_item(void)
{
	item_t *item = malloc(sizeof(item_t) * (count_file() + 1));

	for (int i = 0; i < count_file(); i++)
		item[i].filename = malloc(sizeof(char) * 30);
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
	while ((d = readdir(dir)))
		if (d->d_name[0] != '.')
			nb_file++;
	closedir(dir);
	return (nb_file);
}

int take_filename(item_t *item)
{
	DIR *dir = NULL;
	struct dirent *d;
	int i = 0;
	int j = 0;

	dir = opendir("tetriminos");
	if (dir == NULL)
		exit(84);
	while ((d = readdir(dir))) {
		if (d->d_name[0] != '.') {
			for (j = 0; d->d_name[j] > ' '; j++)
				item[i].filename[j] = d->d_name[j];
			item[i].filename[j] = '\0';
			i++;
		}
	}
	closedir(dir);
	return (0);
}
