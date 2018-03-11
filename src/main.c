/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** main.c
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
#include <time.h>
#include "prototype.h"
#include <term.h>

void display_windows(game_t *game)
{
	game->move.nb_tet == game->rand_next ? game->rand_next = create_next() : 0;
	display_title(game);
	game->key.next == true ? display_next(game) : 0;
	display_score(game);
	refresh_win(game);
}

void command(char key[10], game_t *game, item_t *cp_tetr)
{
	if (my_strncmp(key, game->key.ke_left, 3) == 0) {//mettre key.key_left a la place
		move_tetro_left(game, cp_tetr);
	}
	if (my_strncmp(key, game->key.ke_right, 3) == 0) {//mettre key.key_right a la place
		move_tetro_right(game, cp_tetr);
	}

}

int move_tetro_auto(game_t *game, int i, item_t *cp_tetr) // a la normes!!!
{
	cp_tetr[game->move.nb_tet].coord_y++;//augmenter lincrementation selon le niveau
	werase(game->win.win);
	if (cp_tetr[game->move.nb_tet].coord_y >= game->key.size_height - cp_tetr[game->move.nb_tet].y - 1) {
		game->tetrominos[game->move.nb_tet].coord_y = cp_tetr[game->move.nb_tet].coord_y;
		game->tetrominos[game->move.nb_tet].coord_x = cp_tetr[game->move.nb_tet].coord_x;
		cp_tetr[game->move.nb_tet].coord_y = 0;
		cp_tetr[game->move.nb_tet].coord_x = 0;
		//game->move.nb_tet = game->rand_next;
		//cp_tetr = create_item();
		return (game->move.nb_tet);
	}
	return (-1);
}

void move_tetro_right(game_t *game, item_t *cp_tetr)
{
	cp_tetr[game->move.nb_tet].coord_x++;
	werase(game->win.win);
	if (cp_tetr[game->move.nb_tet].coord_x >= game->key.size_width - cp_tetr[game->move.nb_tet].x) {
	cp_tetr[game->move.nb_tet].coord_x =  game->key.size_width - cp_tetr[game->move.nb_tet].x - 1;
	}
}

void move_tetro_left(game_t *game, item_t *cp_tetr)
{
	cp_tetr[game->move.nb_tet].coord_x--;
	werase(game->win.win);
	if (cp_tetr[game->move.nb_tet].coord_x <= 1) {
		cp_tetr[game->move.nb_tet].coord_x = 1;
	}
}

void display_tetro_base(game_t *game, int id_tetri)
{
	for (int i = 0; i < game->tetrominos[id_tetri].y; i++)
		mvwprintw(game->win.win, game->tetrominos[id_tetri].coord_y + i, game->tetrominos[id_tetri].coord_x, game->tetrominos[id_tetri].item[i]);
}

int game_loop(game_t *game)
{
	int i = 0;
	item_t *cp_tetr = create_item();
	int id_tetri = 0;

	mode(1);
	while (1) {
		char key[10] = {0};

		if (read(0, key, 3) == 1 && key[0] == game->key.key_quit) {
			mode(0);
			break;
		}
		create_border(game);
		set_color(game->win.win, game->tetrominos[game->move.nb_tet].color);
		for (i = 0; i < game->tetrominos[game->move.nb_tet].y; i++)
			mvwprintw(game->win.win, cp_tetr[game->move.nb_tet].coord_y + i, cp_tetr[game->move.nb_tet].coord_x, game->tetrominos[game->move.nb_tet].item[i]);
		display_windows(game);
		command(key, game, cp_tetr);
		id_tetri = move_tetro_auto(game, i, cp_tetr) != -1 ? game->move.nb_tet = game->rand_next : 0;// a debuguer
		display_tetro_base(game, id_tetri);
		wattroff(game->win.win, COLOR_PAIR(1));
		refresh();
	}
}

int item_tetris(int argc, char **argv)
{
	game_t game = game_create(argc, argv);

	initscr();
	//raw();//i dont know
	keypad(stdscr, TRUE);//i dont know
	noecho();//i dont know
	curs_set(0);
	game.key.size_height >= (LINES / 2) ? endwin() : 0;
	game.key.size_height >= (LINES / 2) ? exit(84) : 0;
	check_error_color();
	initi_win(&game);
	game_loop(&game);
	endwin();
	return (0);
}

int there_is_d(char **argv, int argc)
{
	for (int i = 1; i < argc; i++)
		if (my_strncmp(argv[i], "-D", 3) == 0
		|| my_strncmp(argv[i], "--debug", 8) == 0)
			return (1);
	return (0);
}

int main(int argc, char **argv, char **env)
{
	bool bol = false;
	srand(time(NULL));

	if (env[0] == NULL)
		return (84);
	parsing(argv, argc, env);
	//mode(1);
	if (argc == 1)
		return (item_tetris(argc, argv));
	if (my_strncmp(argv[1], "--help", 5) == 0)
		return (help(argv));
	if (there_is_d(argv, argc) == 0)
		return (item_tetris(argc, argv));
	if (there_is_d(argv, argc) == 1) {
		debug_mode(argv, argc);
		bol = true;
	} if (bol == true)
		return (item_tetris(argc, argv));
	else
		return (0);
}
