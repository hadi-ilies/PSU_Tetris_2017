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
#include "prototype.h"
#include <term.h>

void display_windows(game_t *game, int j)
{
	display_title(game);
	game->next == true ? display_next(game, j) : 0;
	display_score(game);
	refresh_win(game);
}

int game_loop(game_t *game)
{
	char key[5] = {0};
	int x = game->tetrominos[0].x;
	int j = 0;
	int test = 0;

	while (1) {
		if (read(0, key, 1) == 1 && key[0] == 27) {
			printw("%d, %d, %d", key[0], key[1], key[2]);
			test++;
		}
		if (test == 10) {
			mode(0);
			break;
		}
		int y = game->tetrominos[j].y;
		create_border(game);
		set_color(game->win.win, game->tetrominos[j].color);
		for (int i = 0; i < game->tetrominos[j].y; i++)
			mvwprintw(game->win.win, y / 2 + i,
				(game->tetrominos[j].x / 2), game->tetrominos[j].item[i]);
		display_windows(game, j);
		wattroff(game->win.win, COLOR_PAIR(1));//a verifier
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
	game.size_height >= (LINES / 2) ? endwin() : 0;// its height
	game.size_height >= (LINES / 2) ? exit(84) : 0;//
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
	int ret;
	int i;
	char *s;
	char *r;
	bool bol = false;
	char buff[10] = {0};
	  int nb_lu = 0;

	  /*i = setupterm("xterm", 1, &ret);
	printf("result setupterm : i=%d err=%d\n", i, ret);
	//i = tigetnum("cols");
	//printf("cols : %d\n", i);
	s = tigetstr("smkx");
	putp(s);
	s = tigetstr("cup");
	r = tparm(s, 3, 5);
	printf("%s\n", r);
	printf("TOTO\n\n");
	mode(0);
	nb_lu = read(0, buff, 10);
	printf("nb_lu : %d, %d, %d, %d\n", nb_lu, buff[0], buff[1], buff[2]);
	mode(1);*/
	if (env[0] == NULL)
		return (84);
	parsing(argv, argc, env);
	mode(1);
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
