/*
** EPITECH PROJECT, 2018
** parsing2
** File description:
** parsing2
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
/*
void there_is_error_size(game_t *game, char **argv)
{
	if (game->key.size_height < 20 || game->key.size_height > 50
	|| game->key.size_width < 10 || game->key.size_width > 50) {
		help(argv);
		exit (84);
	}
}
*/
void check_error_size2(char **argv, int *i)
{
	int j = 0;
	int check_vir = 0;

	for (; argv[*i][j] != '='; j++);
	j++;
	for (; argv[*i][j] != '\0'; j++) {
		(argv[*i][j] == ',') ? check_vir = 1 : 0;
		if ((argv[*i][j] < '0' && argv[*i][j] != ',')
		|| (argv[*i][j] > '9')) {
			help(argv);
			exit (84);
		}
	}
	(check_vir == 0) ? help(argv) : 0;
	(check_vir == 0) ? exit(84) : 0;
}

void check_error_size(char **argv, int argc)
{
	for (int i = 1; i != argc; i++) {
		if (my_strncmp(argv[i], "--map-size=", 11) == 0)
			check_error_size2(argv, &i);
	}
}
