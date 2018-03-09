/*
** EPITECH PROJECT, 2018
** map
** File description:
** map
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

char **map_cr(char *filename)
{
	char **map = mem_alloc_2d_array(count_row_map(filename), count_col_map(filename));
	int fd = open(filename, O_RDONLY);
	char *str = get_next_line(fd);

	for (int i = 0; str != NULL; i++) {
		map[i] = str;
		str = get_next_line(fd);
	}
	close(fd);
	return (map);
}

int count_row_map(char *filename)
{
	int fd = open(filename, O_RDONLY);
	char *str = get_next_line(fd);
	int i = 0;

	for (; str != NULL; i++)
		str = get_next_line(fd);
	close(fd);
	return (i);
}

int count_col_map(char *filename)
{
	int fd = open(filename, O_RDONLY);
	char *str = get_next_line(fd);
	int i = 0;
	int j = 0;

	for (; str != NULL; ) {
		for (i = 0; str[i] != '\0'; i++)
			i > j ? j = i : 0;
		str = get_next_line(fd);
	}
	close(fd);
	return (++j);
}
