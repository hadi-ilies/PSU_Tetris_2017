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

void insert_base_ter(item_t *cp_tetr, map_t *game_map, game_t *game)
{
	for (int i = 0; i < cp_tetr[game->move.nb_tet].y; i++)
		for (int j = 0; game->tetrominos[game->move.nb_tet].item[i][j] != '\0'; j++) {
			game_map->tab[j + cp_tetr[game->move.nb_tet].coord_x][i + cp_tetr[game->move.nb_tet].coord_y].type = game->tetrominos[game->move.nb_tet].item[i][j];
			game_map->tab[j + cp_tetr[game->move.nb_tet].coord_x][i + cp_tetr[game->move.nb_tet].coord_y].color = game->tetrominos[game->move.nb_tet].color;
		}
}

int tetro_colision(game_t *game, item_t *cp_tetr, map_t *game_map)
{
	for (int i = 0; i < cp_tetr[game->move.nb_tet].y; i++)
		for (int j = 0; game->tetrominos[game->move.nb_tet].item[i][j] != '\0'; j++)
			if (game_map->tab[j + cp_tetr[game->move.nb_tet].coord_x][i + cp_tetr[game->move.nb_tet].coord_y + 1].type == '*')
				return (1);
	return (0);
}

int check_line(game_t *game, map_t *game_map)
{
	int line_filled = 0;

	for (int i = 0; i < game_map->nb_case_x; i++) {
		for (int j = 0; j < game_map->nb_case_y; j++) {
			game_map->tab[i][j].type == '*' ? line_filled++ : (line_filled = 0);
			//game_map->tab[i][j].type == '*' ? printw("|%d|", line_filled) : 0;
		}
		printw("|%d|", line_filled);
		if (line_filled == 8) {
			for (int k = i; k < game_map->nb_case_x; k++) {
				for (int l = 0; l < game_map->nb_case_y; l++) {
					printw("|%c|", game_map->tab[k][l].type);
					mvwprintw(game->win.win, l, k, " ");
					game_map->tab[k][l].type = ' ';
				}
			}
		}
	}
}

int game_loop(game_t *game)
{
	item_t *cp_tetr = create_item();
	map_t game_map = map_create(game->key.size_width, game->key.size_height);//stock size map in var

	mode(1);
	while (1) {
		char key[10] = {'\0'};

		pause_key(key, game);
		if (read(0, key, 3) == 1 && key[0] == game->key.key_quit) {
			mode(0);
			break;
		}
		create_border(game);
		set_color(game->win.win, game->tetrominos[game->move.nb_tet].color);
		display_tetro(game, cp_tetr);
		display_windows(game);
		command(key, game, cp_tetr);
		move_tetro_auto(game, cp_tetr, &game_map) != -1 ? game->move.nb_tet = game->rand_next : 0;
		display_tetro_base(game, &game_map);
		//check_line(game, &game_map);
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
