/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include "my.h"

bool check_str(char *str)
{
	if (my_strlen(str) == 5 && str[1] != ' ' && str[3] != ' ')
		return (false);
	/*for (int i = 0; str[i] != '\0'; i++) {
		printf("i : %d | %c\n", i, str[i]);
		if (str[i] > '9' && str[i] != ' ' && str[i] != '\0'
		|| str[i] < '0' && str[i] != ' ' && str[i] != '\0');
			return (false);
			}*/
	return (true);
}

void take_size(char *str, int *x, int *y,int *color)
{
	*x = str[0] - '0';
	*y = str[2] - '0';
	*color = str[4] + '0';
}

bool check_size_str(char *str, int x)
{
	printf("size : %d | x : %d\n", my_strlen(str), x);
	if (my_strlen(str) != x)
		return (false);
	else
		return (true);
}
bool test_file(char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *str = get_next_line(fd);
	int x = 0;
	int y = 0;
	int color = 0;
	int i = 0;

	if (check_str(str) == false)
		return (false);
	take_size(str, &x, &y, &color);
	for (i = 0; str != NULL; i++) {
		str = get_next_line(fd);//gerer item_error
	} if (i != y + 1)
		return (false);
	return (true);
}
