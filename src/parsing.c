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

bool parse_arg(char **argv, int *i)
{
	if (my_strlen(argv[*i]) >= 2 && L_L && R_T && D_Q && P_W && D_LEV && K_L
	&& K_R && K_T && K_D && K_Q && K_P && M_S && W_N && DEG ) {
		return (true);
	} if (my_strlen(argv[*i]) == 1 && parse_touch(argv, i) == false)
	      return (true);
	else
		return (false);
}

bool parsing(char **argv, int argc)
{
	if (argc == 1)
		return (true);
	for (int i = 1; i < argc; i++) {
		if (parse_arg(argv, &i) == true)
			return (true);
	}
	return (false);
}
