/*
** EPITECH PROJECT, 2018
** parsing
** File description:
** parsing
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

bool parse_touch(char **argv, int *i)
{
	if (argv[*i][0] >= ' ' || argv[*i][0] <= 'z')
		return (true);
	else
		return (false);
}

void parse_arg(char **argv, int *i)
{
	if (my_strlen(argv[*i]) >= 2 && L_L && R_T && D_Q && P_W && D_LEV && K_L
	&& K_R && K_T && K_D && K_Q && K_P && M_S && W_N && DEG && HELP) {
		exit (84);
	} if (my_strlen(argv[*i]) == 1 && parse_touch(argv, i) == false)
		exit (84);
	else
		return;
}

void check_last_arg(char **argv, int argc)
{
	for (int i = 0; i < argc; i++)
		if (argv[i][0] == '-' && argv[i][1] != 'D' && argv[i][1] != '-'
		&& argv[i][1] != 'w' && argv[i + 1] == NULL)
			exit (84);
}

void parsing(char **argv, int argc)
{
	check_dir();
	check_last_arg(argv, argc);
	check_error_size(argv, argc);
	game_t game = game_create(argc, argv);

	there_is_error_size(&game);
	for (int i = 1; i < argc; i++)
		parse_arg(argv, &i);
	return;
}
