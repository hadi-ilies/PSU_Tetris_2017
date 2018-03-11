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
	struct termios	oldt;
	struct termios newt;
	char c[10];

	if (i == 1) {
	ioctl(0, TCGETS, &newt);
	newt.c_lflag &= ~ICANON;
	newt.c_lflag &= ~ECHO;
	newt.c_cc[VMIN] = 0;
	newt.c_cc[VTIME] = 2;
	ioctl(0, TCSETS, &newt);
	}
	//while (1) {
	//      read(0, c, 1);
	//      printf("xd\n");
	//}
	if (i == 0)
		ioctl(0, TCSETS, &oldt);
	return (0);
}
