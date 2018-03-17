/*
** EPITECH PROJECT, 2018
** save_command_game
** File description:
** save_command_game
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

char *save_keyturn(char **argv, int argc)
{
	char *key_turn = NULL;
	char *command;

	for (int i = 0; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-turn=", 11) == 0)) {
			command = command_l(argv[i]);
			key_turn = NULL;
			break;
		} else if (my_strncmp(argv[i], "-t", 2) == 0) {
			command = argv[i + 1];
			key_turn = NULL;
			break;
		} else
			key_turn = tigetstr("kcuu1");
	} if (key_turn == NULL)
		key_turn = command;
	return (key_turn);
}

char *save_keydrop(char **argv, int argc)
{
	char *key_drop = NULL;
	char *command;

	for (int i = 0; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-drop=", 11) == 0)) {
			command = command_l(argv[i]);
			key_drop = NULL;
			break;
		} else if (my_strncmp(argv[i], "-d", 2) == 0) {
			command = argv[i + 1];
			key_drop = NULL;
			break;
		} else
			key_drop = tigetstr("kcud1");
	} if (key_drop == NULL)
		key_drop = command;
	return (key_drop);
}

bool save_without_next(char **argv, int argc)
{
	bool next = true;

	for (int i = 0; i < argc; i++) {
		if ((my_strncmp(argv[i], "--without-next=", 7) == 0
		|| my_strncmp(argv[i], "-w", 2) == 0)) {
			next = false;
			break;
		}
	}
	return (next);
}

int save_mapsize_height(char **argv, int argc)
{
	char *command;
	int height = 0;
	char *str;
	int j = 0;

	for (int i = 0; i < argc; i++) {
		if ((my_strncmp(argv[i], "--map-size=", 7) == 0)) {
			command = command_size(argv[i], argv);
			break;
		} else
			command = "20*10";
	}
	str = my_malloc(sizeof(char) * my_strlen(command) - 1);
	for (int i = 0; command[i] != '*'; i++) {
		str[j] = command[i];
		j++;
	}
	str[j] = '\0';
	height = my_atoi(str);
	return (height);
}

int save_mapsize_width(char **argv, int argc)
{
	char *command;
	char *width;
	int j = 0;
	int k = 0;

	for (int i = 0; i < argc; i++) {
		if ((my_strncmp(argv[i], "--map-size=", 7) == 0)) {
			command = command_size(argv[i], argv);
			break;
		} else
			command = "20*10";
	} for (k = 0; command[k] != '*'; k++);
	width = my_malloc(sizeof(char) * (my_strlen(command) + 1 - k++));
	for (; command[k] != '\0'; k++) {
		width[j] = command[k];
		j++;
	}
	width[j] = '\0';
	return (my_atoi(width));
}
