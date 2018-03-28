/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** main.c
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"
#include "map.h"
#include "macros.h"

void game_loop_display(game_t *game, item_t *cp_tetr, map_t *game_map,
		char key[4])
{
	pause_key(key, game);
	create_border(game);
	set_color(game->win.win, game->tetrominos[ID].color);
	display_tetro(game, cp_tetr);
	display_windows(game);
	command(key, game, cp_tetr, game_map);
}

void game_loop(game_t *game)
{
	item_t *cp_tetr = create_item();
	map_t game_map = map_create(WIN_WIDTH, WIN_HEIGHT);

	mode(1);
	while (1) {
		char key[4] = {'\0'};

		if (exit_game(key, game) == 1)
			break;
		game_loop_display(game, cp_tetr, &game_map, key);
		if (move_tetro_auto(game, cp_tetr, &game_map) == 1)
			break;
		display_tetro_base(game, &game_map);
		check_line(game, &game_map);
		wattroff(game->win.win, COLOR_PAIR(1));
	}
}

int item_tetris(int argc, char **argv)
{
	game_t game = game_create(argc, argv);

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
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
