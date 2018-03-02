/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** prototype.h
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

char *display_name(char *str);
void debug_mode_2(char **argv, int argc, item_t *item);
void debug_mode_3(char **argv, item_t *item);
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
bool help(void);
#endif
