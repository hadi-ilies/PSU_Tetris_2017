/*
** EPITECH PROJECT, 2018
** move_tetro
** File description:
** move_tetro
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"
#include "map.h"

int move_tetro_auto(game_t *game, item_t *cp_tetr, map_t *game_map) // a la normes!!!
{
	cp_tetr[game->move.nb_tet].coord_y++;//augmenter lincrementation selon le niveau
	werase(game->win.win);
	if (tetro_colision(game, cp_tetr, game_map) == 1 && cp_tetr[game->move.nb_tet].coord_y == 1) {
		game_over(game);
		mode(0);
		return (1);
	} if (cp_tetr[game->move.nb_tet].coord_y >= game->key.size_height - cp_tetr[game->move.nb_tet].y|| tetro_colision(game, cp_tetr, game_map) == 1) {
		insert_base_ter(cp_tetr, game_map, game);
		cp_tetr[game->move.nb_tet].coord_y = 0;
		cp_tetr[game->move.nb_tet].coord_x = 3;
		game->move.nb_tet = game->rand_next;
	}
	return (-1);
}

void move_tetro_right(game_t *game, item_t *cp_tetr, map_t *game_map)
{
	cp_tetr[game->move.nb_tet].coord_x++;
	werase(game->win.win);
	if (cp_tetr[game->move.nb_tet].coord_x >= game->key.size_width - cp_tetr[game->move.nb_tet].x
	|| tetro_colision(game, cp_tetr, game_map) == 1)
		cp_tetr[game->move.nb_tet].coord_x =  game->key.size_width - cp_tetr[game->move.nb_tet].x;
}

void move_tetro_left(game_t *game, item_t *cp_tetr, map_t *game_map)
{
	cp_tetr[game->move.nb_tet].coord_x--;
	werase(game->win.win);
	if (cp_tetr[game->move.nb_tet].coord_x <= 0 || tetro_colision(game, cp_tetr, game_map) == 1) {
		cp_tetr[game->move.nb_tet].coord_x = 0;
	}
}
