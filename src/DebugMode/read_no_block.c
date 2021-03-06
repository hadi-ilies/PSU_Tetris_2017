/*
** EPITECH PROJECT, 2018
** block
** File description:
** block
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <fcntl.h>
#include "my.h"
#include "prototype.h"
#include <termios.h>
#include <sys/ioctl.h>

int mode(int i)
{
	static struct termios oldt;
	struct termios newt;

	if (i == 1) {
		ioctl(0, TCGETS, &oldt);
		ioctl(0, TCGETS, &newt);
		newt.c_lflag &= ~ICANON;
		newt.c_lflag &= ~ECHO;
		newt.c_cc[VMIN] = 0;
		ioctl(0, TCSETS, &newt);
	} if (i == 0)
		ioctl(0, TCSETS, &oldt);
	return (0);
}
