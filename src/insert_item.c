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
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>
#include "my.h"

void purge_str(char **array, int *x, int *y, int *color)
{
	*x = my_atoi(array[0]);
	*y = my_atoi(array[1]);
	*color = my_atoi(array[2]);
}

void insert_item2(char **item, int x, int y, int fd)
{
	char *str = get_next_line(fd);

	for (int i = 0; str != NULL; i++) {
		item[i] = str;
		//printf("%s\n" , item[i]);
		str = get_next_line(fd);
	}
}

char **insert_item(char *filename, int *x, int *y, int *color)
{
	int fd = open(filename, O_RDONLY);
	char *str = get_next_line(fd);
	char **array = my_str_to_word_array(str);

	purge_str(array, x, y , color);
	char **item =  my_malloc2((*x) + 1, (*y) + 1);

	insert_item2(item, *x, *y, fd);
	return (item);

}
