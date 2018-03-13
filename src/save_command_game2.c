/*
** EPITECH PROJECT, 2018
** save_command_game2.c
** File description:
** save_command_game.c
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

int save_keyquit(char **argv, int argc)
{
	int key_quit = 'q';
	char *command;

	for (int i = 0; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-quit=", 11) == 0)) {
			command = command_l(argv[i]);
			break;
		} else if (my_strncmp(argv[i], "-q", 2) == 0) {
			command = argv[i + 1];
			break;
		} else
			command = "q";
	}
	key_quit = command[0];
	return (key_quit);
}

int save_keypause(char **argv, int argc)
{
	int key_pause = ' ';
	char *command;

	for (int i = 0; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-pause=", 11) == 0)) {
			command = command_l(argv[i]);
			break;
		} else if (my_strncmp(argv[i], "-p", 2) == 0) {
			command = argv[i + 1];
			break;
		} else
			command = " ";
	}
	key_pause = command[0];
	return (key_pause);
}

int save_level(char **argv, int argc)
{
	int level = 1;
	char *command;

	for (int i = 0; i < argc; i++) {
		if ((my_strncmp(argv[i], "--level=", 11) == 0)) {
			command = command_l(argv[i]);
			break;
		} else if (my_strncmp(argv[i], "-L", 2) == 0) {
			command = argv[i + 1];
			break;
		} else
			command = "1";
	}
	level = command[0];
	return (level);
}

char *save_keyleft(char **argv, int argc)
{
	char *key_left = NULL;
	char *command;

	for (int i = 0; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-left=", 11) == 0)) {
			command = command_l(argv[i]);
			key_left = NULL;
			break;
		} else if (my_strncmp(argv[i], "-l", 2) == 0) {
			command = argv[i + 1];
			key_left = NULL;
			break;
		} else
			key_left = tigetstr("kcub1");
	} if (key_left == NULL)
		key_left = command;
	return (key_left);
}

char *save_keyright(char **argv, int argc)
{
	char *key_right = NULL;
	char *command;

	for (int i = 0; i < argc; i++) {
		if ((my_strncmp(argv[i], "--key-right=", 11) == 0)) {
			command = command_l(argv[i]);
			key_right = NULL;
			break;
		} else if (my_strncmp(argv[i], "-r", 2) == 0) {
			command = argv[i + 1];
			key_right = NULL;
			break;
		} else
			key_right = tigetstr("kcuf1");
	} if (key_right == NULL)
		key_right = command;
	return (key_right);
}
