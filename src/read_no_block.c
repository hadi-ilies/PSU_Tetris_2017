/*
** EPITECH PROJECT, 2018
** block
** File description:
** block
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
#include <termios.h>
#include <sys/ioctl.h>

//mode non canonique
int mode(int i)
{
	static struct termios	oldT;
	static struct termios	newT;

	if (i == 1) {
		ioctl(0, TCGETS, &oldT);
		ioctl(0, TCGETS, &newT);
		newT.c_lflag &= ~ECHO;
		newT.c_lflag &= ~ICANON;
		ioctl(0, TCSETS, &newT);
	} else if (i == 2) {
		ioctl(0, TCGETS, &newT);
		newT.c_lflag &= ~ECHO;
		newT.c_lflag &= ~ICANON;
		newT.c_cc[VMIN] = 0;
		newT.c_cc[VTIME] = 0;
		ioctl(0, TCSETS, &newT);
	} else if (i == 0)
		ioctl(0, TCSETS, &oldT);
/*
	if (i == 0) {
		ioctl(0, TCGETS, &oldt);
		ioctl(0, TCGETS, &newt) == -1 ? exit(84) : 0;
		newt.c_lflag &= ~ECHO;
		newt.c_lflag &= ~ICANON;
		ioctl(0, TCSETS, &newt);
		//tcgetattr(0, &newt);
		newt.c_cc[VMIN] = 1;
		newt.c_cc[VTIME] = 0;
		return (0);
	} if (i == 1)
		  ioctl(0, TCSETS, &oldt) == -1 ? exit (84) : 0;
	return (0);*/
}
