/*
** EPITECH PROJECT, 2018
** take_filename
** File description:
** take_filename
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "prototype.h"
#include "macros.h"

int mystrlen_p(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '.'; i++);
	return (i);
}

int is_regular_file(const char *path)
{
    struct stat path_stat;

    stat(path, &path_stat);
    return (S_ISREG(path_stat.st_mode));
}

int take_filename(item_t *item)
{
	DIR *dir = NULL;
	struct dirent *d;
	int i = 0;
	int j = 0;

	dir = opendir("tetriminos");
	if (dir == NULL)
		exit(84);
	while ((d = readdir(dir))) {
		d == NULL ? exit (84) : 0;
		if (is_regular_file(concat("tetriminos/", d->d_name))
		&& T_FILE){
			for (j = 0; d->d_name[j] > ' '; j++)
				item[i].filename[j] = d->d_name[j];
			item[i].filename[j] = '\0';
			i++;
		}
	}
	closedir(dir);
	return (0);
}
