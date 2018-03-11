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
	int x;
	int y;
	int nb_tet;
}move_t;

typedef struct {
	WINDOW *win;
	WINDOW *score;
	WINDOW *next_i;
	WINDOW *title;
}win_t;

typedef struct {
	int coord_x;//
	int coord_y;//
	int x;//size_x
	int y;//size_y
	int color;
	char *filename;
	char *str;
	char **item;
}item_t;

typedef struct {
	char *ke_left;
	char *ke_right;
	char *key_turn;
	char *key_drop;
	int key_quit;
	int key_pause;
	bool next;
	int level;
	int size_height;
	int size_width;
} keyb_t;

typedef struct {
	keyb_t key;
	win_t win;
	int rand_next;
	move_t move;
	item_t *tetrominos;
} game_t;

void move_tetro_right(game_t *game, item_t *cp_tetr);
void move_tetro_left(game_t *game, item_t *cp_tetr);
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
