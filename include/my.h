/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include "get_next_line.h"

typedef struct {
	int x;
	int y;
	int color;
	char *filename;
	char *str;
	char **item;
}item_t;

size_t my_putchar(int fd, const char c);
size_t my_putstr(int fd, const char *str);
size_t my_putnbr(int fd, int nb);
size_t my_printf(int fd, const char *str, ...);
ssize_t my_strlen(const char *str);
void *my_malloc(size_t size);
void **my_malloc2(size_t nb_case_x, size_t nb_case_y);

#endif
