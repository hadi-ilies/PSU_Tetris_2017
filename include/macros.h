/*
** EPITECH PROJECT, 2018
** macro
** File description:
** macro
*/

#pragma once

/*macros parsing*/
#define D_N display_name(item[j].filename)
#define L_L my_strncmp(argv[*i], "-L", 3) == -1 && \
		my_strncmp(argv[*i], "-l", 3) == -1
#define R_T my_strncmp(argv[*i], "-r", 3) == -1 && \
		my_strncmp(argv[*i], "-t", 3) == -1
#define D_Q my_strncmp(argv[*i], "-d", 3) == -1 && \
		my_strncmp(argv[*i], "-q", 3) == -1
#define P_W my_strncmp(argv[*i], "-p", 3) == -1 && \
		my_strncmp(argv[*i], "-w", 3) == -1
#define D_LEV my_strncmp(argv[*i], "-D", 3) == -1 && \
		my_strncmp(argv[*i], "--level=", 8) == -1
#define K_L my_strncmp(argv[*i], "--key-left=", 11) == -1
#define K_R my_strncmp(argv[*i], "--key-right=", 12) == -1
#define K_T my_strncmp(argv[*i], "--key-turn=", 11) == -1
#define K_D my_strncmp(argv[*i], "--key-drop=", 11) == -1
#define K_Q my_strncmp(argv[*i], "--key-quit=", 11) == -1
#define K_P my_strncmp(argv[*i], "--key-pause=", 12) == -1
#define M_S my_strncmp(argv[*i], "--map-size=", 11) == -1
#define W_N my_strncmp(argv[*i], "--without-next", 14) == -1
#define DEG my_strncmp(argv[*i], "--debug", 8) == -1
#define HELP my_strncmp(argv[*i], "--help", 7) == -1

/*macros jeu*/
#define BORDER_WIN_WIN wborder(game->win.win, '|', '|', '-', '-', '+', \
			'+', '+', '+')
#define BORDER_WIN_SCORE wborder(game->win.score, '|', '|', '-', '-', \
				'/', '\\', '\\', '/')
#define BORDER_WIN_NEXT wborder(game->win.next_i, '|', '|', '-', '-', '/', \
				'\\', '\\', '/')
#define BORDER_WIN_TITLE wborder(game->win.title, '|', '|', '-', '-', '/', \
				'\\', '\\', '/')

#define C_X cp_tetr[game->move.nb_tet].coord_x
#define C_Y cp_tetr[game->move.nb_tet].coord_y
#define WIN_WIDTH game->key.size_width
#define WIN_HEIGHT game->key.size_height
