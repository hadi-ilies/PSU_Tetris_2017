/*
** EPITECH PROJECT, 2018
** check_dir
** File description:
** check_dir
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

void check_dir(void)
{
	int nb_file = 0;
	DIR *dir = NULL;
	struct dirent *d;

	dir = opendir("tetriminos");
	if (dir == NULL)
		exit(84);
	while ((d = readdir(dir)))
		if (d->d_name[0] != '.')
			nb_file++;
	if (nb_file == 0)
		exit(84);
	closedir(dir);
}
