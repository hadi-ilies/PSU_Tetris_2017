/*
** EPITECH PROJECT, 2018
** score
** File description:
** score
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"

void add_score(game_t *game)
{
	static int check_level = 0;

	game->score += 10;
	game->score >= 200 && check_level++ == 10 ? game->key.level += '1' : 0;
	game->score >= 200 && check_level++ == 10 ? check_level = 0 : 0;
}

char *display_high_score()
{
	int fd = open("best_score.txt", O_RDONLY);

	if (fd == -1)
		exit (84);
	return (get_next_line(fd));
}

void insert_best_score(game_t *game)
{
	int fd = open("best_score.txt", O_CREAT | O_WRONLY);
	if (fd == -1)
		exit (84);
	write(fd, inttostr(game->score), my_strlen(inttostr(game->score)));
}

int best_score(game_t *game)
{
	if (game->score > my_atoi(display_high_score())) {
		mvwprintw(game->win.game_over, 1, 1, "NEW SCORE!!\n");
		insert_best_score(game);
		return (game->score);
	} else
		return (my_atoi(display_high_score()));
}

void display_score(game_t *game)
{
	static int clk_start = -1;
	int clk = time(NULL);

	clk_start == -1 ? clk_start = time(NULL) : 0;
	mvwprintw(game->win.score, 0, 10, "SCOREBOARD");
	mvwprintw(game->win.score, 2, 1, "High Score:\t%s",
		display_high_score());
	mvwprintw(game->win.score, 4, 1, "Score:\t%d", game->score);
	mvwprintw(game->win.score, 8, 1, "Lines:\t%d", 1);
	mvwprintw(game->win.score, 10, 1, "Level:\t%d", game->key.level - '0');
	mvwprintw(game->win.score, 14, 1, "Timer:\t%.2d:%.2d",
		game->time = (clk - clk_start) / 60, (clk - clk_start)% 60);
}
