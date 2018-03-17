/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** prototype.h
*/

#pragma once

#include "my.h"
#include "map.h"

void check_line(game_t *game, map_t *game_map);
item_t *sort_debug(item_t *item);
int exit_game(char key[4], game_t *game);
void move_tetro_drop(game_t *game, item_t *cp_tetr, map_t *game_map);
item_t rotate(item_t *tetro);
void command(char key[4], game_t *game, item_t *cp_tetr, map_t *game_map);
void display_windows(game_t *game);
void pause_key(char key[4], game_t *game);
void add_score(game_t *game);
void game_over(game_t *game);
int tetro_colision(game_t *game, item_t *cp_tetr, map_t *game_map);
int best_score(game_t *game);
int tetro_colision_r_l(game_t *game, item_t *cp_tetr, map_t *game_map);
void insert_base_ter(item_t *cp_tetr, map_t *game_map, game_t *game);
void set_color_without_win(int color);
void display_tetro_base(game_t *game, map_t *game_map);
void display_tetro(game_t *game, item_t *cp_tetr);
int move_tetro_auto(game_t *game, item_t *cp_tetr, map_t *game_map);
void move_tetro_right(game_t *game, item_t *cp_tetr, map_t *game_map);
void move_tetro_left(game_t *game, item_t *cp_tetr, map_t *game_map);
int create_next(void);
char *save_keydrop(char **argv, int argc);
char *save_keyturn(char **argv, int argc);
void parsing(char **argv, int argc, char **env);
void check_error_size2(char **argv, int *i);
void check_error_size(char **argv, int argc);
void there_is_error_size(game_t *game);
void check_dir(void);
char *save_keyright(char **argv, int argc);
char *save_keyleft(char **argv, int argc);
void display_score(game_t *game);
void display_title(game_t *game);
void display_next(game_t *game);
void create_border(game_t *game);
void refresh_win(game_t *game);
void initi_win(game_t *game);
void set_color(WINDOW *win, int color);
void check_error_color(void);
int save_mapsize_height(char **argv, int argc);
int save_mapsize_width(char **argv, int argc);
char *save_keyturn(char **argv, int argc);
bool save_without_next(char **argv, int argc);
int save_keyquit(char **argv, int argc);
int save_keypause(char **argv, int argc);
int save_level(char **argv, int argc);
game_t game_create(int argc, char **argv);
char *display_name(char *str);
void debug_mode_2(char **argv, int argc, item_t *item);
void debug_mode_3(item_t *item);
char *command_l(char *command);
void keydrop(char **argv, int argc);
void keypause(char **argv, int argc);
void keyquit(char **argv, int argc);
bool pars_level(char *command);
void level(char **argv, int argc);
void keyleft(char **argv, int argc);
void keyright(char **argv, int argc);
void keyturn(char **argv, int argc);
void debug_mode(char **argv, int argc);
void without_next(char **argv, int argc);
char *command_size(char *size);
void mapsize(char **argv, int argc);
int count_row_map(char *filename);
int count_col_map(char *filename);
char **map_cr(char *filename);
char *ini_filename(void);
void purge_str(item_t *item, int *i, int fd);
void init_item(item_t *item);
item_t *create_item(void);
int count_file(void);
int take_filename(item_t *item);
bool help(char **argv);
int mystrlen_p(char *str);
int mode (int i);
