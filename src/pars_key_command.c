/*
** EPITECH PROJECT, 2018
** pars_key_command
** File description:
** pars_key_command
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

char *command_l(char *command)
{
	char *str = malloc(sizeof(char) * 2);

	for (int i = 0; command[i] != '\0'; i++) {
		if (command[i] == '=') {
			str[0] = command[i + 1];
		}
	}
	str[1] = '\0';
	return (str);
}

void keydrop(char **argv, int argc)
{
	char *command;

	for (int i = 1; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-drop=", 11) == 0)) {
			command = command_l(argv[i]);
			break;
		} else if (my_strncmp(argv[i], "-d", 2) == 0) {
			command = argv[i + 1];
			break;
		} else
			command = "d";
	} if (command[0] == ' ')
		printf("Key Drop :  (space)\n");
	else
		printf("Key Drop :  %s\n", command);
}

void keyquit(char **argv, int argc)
{
	char *command;

	for (int i = 1; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-quit=", 11) == 0)) {
			command = command_l(argv[i]);
			break;
		} else if (my_strncmp(argv[i], "-q", 2) == 0) {
			command = argv[i + 1];
			break;
		} else
			command = "q";
	} if (command[0] == ' ')
		  printf("Key Quit :  (space)\n");
	else
		printf("Key Quit :  %s\n", command);
}

void keypause(char **argv, int argc)
{
	char *command;

	for (int i = 1; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-pause=", 11) == 0)) {
			command = command_l(argv[i]);
			break;
		} else if ( my_strncmp(argv[i], "-p", 2) == 0) {
			command = argv[i + 1];
			break;
		} else
			command = "p";
	} if (command[0] == ' ')
		  printf("Key Pause :  (space)\n");
	else
		printf("Key Pause :  %s\n", command);
}
