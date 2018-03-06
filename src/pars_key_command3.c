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
		if ((my_strncmp(argv[i], "--without-next=", 7) == 0
		|| my_strncmp(argv[i], "-w", 2) == 0)) {
			printf("Next :  no\n");
			next = false;
			break;
		}
	} if (next == true)
		printf("Next :  Yes\n");
}

char *command_size(char *size)
{
	char *str = my_malloc(sizeof(char) * 12);
	int i = 0;
	int j = 0;

	for (; size[i] != '='; i++);
	i++;
	for (; size[i] != ','; i++) {
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
		if ((my_strncmp(argv[i], "--map-size=", 7) == 0)) {
			command = command_size(argv[i]);
			break;
		} else
			command = "20*10";
	}
	printf("Size :  %s\n", command);
}
