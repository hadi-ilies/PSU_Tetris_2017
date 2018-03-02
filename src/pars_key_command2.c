/*
** EPITECH PROJECT, 2018
** pars_key_command2
** File description:
** pars_command_command2
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

bool pars_level(char *command)
{
	for (int i = 0; command[i] != '\0'; i++) {
		if (command[i] < '1' || command [i] > '9') {
			exit(84);
		}
	}
	return (false);
}

void level(char **argv, int argc)
{
	char *command;

	for (int i = 1; i < argc; i++) {
		if ((my_strncmp(argv[i], "--level=", 7) == 0)) {
			command = command_l(argv[i]);
			break;
		} else if (my_strncmp(argv[i], "-L", 2) == 0) {
			command = argv[i + 1];
			break;
		} else
			command = "1";
	}
	pars_level(command);
	if (command[0] == ' ')
		printf("Level :  (space)\n");
	else
		printf("Level :  %s\n", command);
}

void keyleft(char **argv, int argc)
{
	char *command;

	for (int i = 1; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-left=", 11) == 0)) {
			command = command_l(argv[i]);
			break;
		} else if (my_strncmp(argv[i], "-l", 2) == 0) {
			command = argv[i + 1];
			break;
		} else
			command = "^EOD";
	} if (command[0] == ' ')
		printf("Key Left :  (space)\n");
	else
		printf("Key Left :  %s\n", command);
}

void keyright(char **argv, int argc)
{
	char *command;

	for (int i = 1; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-right=", 11) == 0)) {
			command = command_l(argv[i]);
			break;
		} else if (my_strncmp(argv[i], "-r", 2) == 0) {
			command = argv[i + 1];
			break;
		} else
			command = "^EOC";
	} if (command[0] == ' ')
		printf("Key Right :  (space)\n");
	else
		printf("Key Right :  %s\n", command);
}

void keyturn(char **argv, int argc)
{
	char *command;

	for (int i = 1; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-turn=", 11) == 0)) {
			command = command_l(argv[i]);
			break;
		} else if (my_strncmp(argv[i], "-t", 2) == 0) {
			command = argv[i + 1];
			break;
		} else
			command = "t";
	} if (command[0] == ' ')
		printf("Key Turn :  (space)\n");
	else
		printf("Key Turn :  %s\n", command);
}
