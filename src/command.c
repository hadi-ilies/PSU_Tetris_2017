/*
** EPITECH PROJECT, 2018
** command
** File description:
** command
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"
#include "map.h"

void command(char key[10], game_t *game, item_t *cp_tetr, map_t *game_map)
{
	if (my_strncmp(key, game->key.key_drop, 3) == 0)
		move_tetro_drop(game, cp_tetr, game_map);
	if (my_strncmp(key, game->key.ke_left, 3) == 0)
		move_tetro_left(game, cp_tetr, game_map);
	if (my_strncmp(key, game->key.ke_right, 3) == 0)
		move_tetro_right(game, cp_tetr, game_map);
}
