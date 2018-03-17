/*
** EPITECH PROJECT, 2018
** macro
** File description:
** macro
*/

#pragma once

#define D_N display_name(item[i].filename)
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
#define T_FILE my_strncmp(d->d_name + mystrlen_p(d->d_name), \
			".tetrimino", 9) == 0
#define DISPLAY_NAME_AND_SIZE my_printf(1, "Tetriminos : Name %s : Size %d*%d"\
					, D_N, item[i].x, item[i].y)
#define BORDER_WIN_WIN wborder(game->win.win, '|', '|', '-', '-', '+', \
			'+', '+', '+')
#define BORDER_WIN_SCORE wborder(game->win.score, '|', '|', '-', '-', \
				'/', '\\', '\\', '/')
#define BORDER_WIN_NEXT wborder(game->win.next_i, '|', '|', '-', '-', '/', \
				'\\', '\\', '/')
#define BORDER_WIN_TITLE wborder(game->win.title, '|', '|', '-', '-', '/', \
				'\\', '\\', '/')
#define DISPLAY_TITLE mvwprintw(game->win.title, 15 / 2 - count_row\
_map("titre") / 2 + i, 50 / 2 - (count_col_map("titre") / 2), title[i])

#define DISPLAY_NEXT mvwprintw(game->win.next_i, 10 / 2 - game->tetrominos\
		[game->rand_next].y / 2 + i, 20 / 2 - (game->tetrominos\
		[game->rand_next].x / 2), game->tetrominos[game->rand_next]\
			.item[i])
#define DISPLAY_TETRI mvwprintw(game->win.win, cp_tetr[ID].coord_y + i\
	+ 1, cp_tetr[ID].coord_x + j + 1, "%c", cp_tetr[ID].item[i][j])
#define DISPLAY_TETRI_BASE mvwprintw(game->win.win, j + 1, i + 1, "%c", \
			game_map->tab[i][j]) : 0
#define DISPLAY_PAUSE mvprintw(LINES / 2 - count_row_map("pause") / 2 + i, \
			COLS / 2 - (count_col_map("pause") / 2), pause_m[i])
#define DISPLAY_GAMEOVER mvprintw(LINES / 2 - count_row_map("game_over") / 2 +\
		i, COLS / 2 - (count_col_map("game_over") / 2), gameover[i])
#define ID game->move.nb_tet
#define C_X cp_tetr[game->move.nb_tet].coord_x
#define C_Y cp_tetr[game->move.nb_tet].coord_y
#define COLOR cp_tetr[ID].color
#define WIN_WIDTH game->key.size_width
#define WIN_HEIGHT game->key.size_height
#define INSERT_IN_MAP cp_tetr[ID].item[i][j] == '*' ? game_map->tab[j \
			+ C_X][i + C_Y].type = cp_tetr[ID].item[i][j] : 0
#define COND_DROP cp_tetr[ID].y + k >= (int)game_map->nb_case_y || \
		(game_map->tab[j + C_X][i + k + 1].type == '*'\
		&& cp_tetr[ID].item[i][j] == '*')
