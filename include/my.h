/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>
#include "get_next_line.h"
#include "macros.h"

typedef struct {
	WINDOW *win;
	WINDOW *score;
	WINDOW *next_i;
	WINDOW *title;
}win_t;

typedef struct {
	int x;
	int y;
	int color;
	char *filename;
	char *str;
	char **item;
}item_t;

typedef struct {
	int key_left;
	int key_right;
	int key_turn;
	int key_drop;
	int key_quit;
	int key_pause;
	bool next;
	int level;
	int size_height;
	int size_width;
	win_t win;
	item_t *tetrominos;
} game_t;

char *concat(char *s1, char *s2);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
int my_atoi(char *str);
ssize_t my_strlen(const char *str);
int my_strncmp(const char *s1, const char *s2, int n);
char **my_str_to_word_array(char *str);
size_t my_putchar(int fd, const char c);
size_t my_putstr(int fd, const char *str);
size_t my_putnbr(int fd, int nb);
size_t my_printf(int fd, const char *str, ...);
ssize_t my_strlen(const char *str);
void *my_malloc(size_t size);
void **my_malloc2(size_t nb_case_x, size_t nb_case_y);

#endif
