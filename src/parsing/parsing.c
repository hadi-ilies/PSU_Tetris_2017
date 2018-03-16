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
#include <fcntl.h>
#include "my.h"
#include "prototype.h"
#include "macros.h"
#include <term.h>

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
		help(argv);
		exit (84);
	} if (my_strlen(argv[*i]) == 1 && parse_touch(argv, i) == false) {
		  help(argv);
		  exit (84);
	} else
		return;
}

void check_last_arg(char **argv, int argc)
{
	for (int i = 0; i < argc; i++)
		if (argv[i][0] == '-' && argv[i][1] != 'D' && argv[i][1] != '-'
		&& argv[i][1] != 'w' && argv[i + 1] == NULL) {
			help(argv);
			exit (84);
		}
}

char *gettermi(char **env)
{
	for (int i = 0; env[i] != NULL; i++)
		if (my_strncmp("TERM=", env[i], 5) == 0)
			return (env[i] + 5);
	return (NULL);
}

void parsing(char **argv, int argc, char **env)
{
	check_dir();
	check_last_arg(argv, argc);
	check_error_size(argv, argc);
	int ret = 0;
	int i = 0;
	game_t game = game_create(argc, argv);
	char *termi = gettermi(env);

	if (termi == NULL) {
		my_printf(1, "The terminal doesn't exist :(\n");
		exit(84);
	} else {
		i = setupterm(termi, 1, &ret);
		i == -1 ? my_printf(1, "The terminal doesn't exist :(\n") : 0;
		i == -1 ? exit (84) : 0;
	}
	mode(1);
	there_is_error_size(&game);
	for (int i = 1; i < argc; i++)
		parse_arg(argv, &i);
	return;
}
