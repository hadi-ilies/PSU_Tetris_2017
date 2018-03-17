/*
** EPITECH PROJECT, 2018
** pars_key_command3.c
** File description:
** pars_key_command3.c
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

void without_next(char **argv, int argc)
{
	bool next = true;

	for (int i = 1; i < argc; i++) {
		if ((my_strncmp(argv[i], "--without-next=", 15) == 0
		|| my_strncmp(argv[i], "-w", 2) == 0)) {
			my_printf(1, "Next : No\n");
			next = false;
			break;
		}
	} if (next == true)
		my_printf(1, "Next : Yes\n");
}

void check_er_size(char *size, char **argv)
{
	int i = 0;

	for (; size[i] != '='; i++);
	i++;
	for (; size[i] != '\0'; i++) {
		if ((size[i] < '0' && size[i] != ',')
		|| (size[i] > '9' && size[i] != ',')) {
			help(argv);
			exit(84);
		}
	}

}

char *command_size(char *size, char **argv)
{
	char *str = my_malloc(sizeof(char) * my_strlen(size));
	int i = 0;
	int j = 0;

	for (; size[i] != '='; i++);
	i++;
	for (; size[i] != ','; i++) {
		check_er_size(size, argv);
		str[j] = size[i];
		j++;
	}
	str[j] = '*';
	j++;
	i++;
	for (; size[i] != '\0'; i++) {
		str[j] = size[i];
		j++;
	}
	str[j] = '\0';
	return (str);
}

void mapsize(char **argv, int argc)
{
	char *command;

	for (int i = 1; i < argc; i++) {
		if ((my_strncmp(argv[i], "--map-size=", 11) == 0)) {
			command = command_size(argv[i], argv);
			break;
		} else
			command = "20*10";
	}
	my_printf(1, "Size : %s\n", command);
}
