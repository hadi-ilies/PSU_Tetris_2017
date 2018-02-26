/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int count_space(char *str)
{
	int nb_word = 0;
	int count = 2;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && count == 0
			|| str[i] == '\t' && count == 0)
			count = 1;
		if (str[i] > ' ' ) {
			count == 1 ? nb_word++ : 0;
			count = 0;
		}
	}
	return (nb_word + 1);
}

char **malloc_array(char *str)
{
	char **array = my_malloc(sizeof(char *) * (count_space(str) + 1));

	for (int i = 0; i < count_space(str); i++)
		array[i] = my_malloc(sizeof(char) *(my_strlen(str) + 1));
	return (array);
}

char **my_str_to_word_array(char *str)
{
	char **array = malloc_array(str);
	int nb_word = 0;
	int count = 2;
	int j = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && count == 0
		|| str[i] == '\t' && count == 0)
			count = 1;
		if (str[i] > ' ' ) {
			count == 1 ? nb_word++ : 0;
			count == 1 ? j = 0 : 0;
			array[nb_word][j] = str[i];
			array[nb_word][j + 1] = '\0';
			j++;
			count = 0;
		}
	}
	array[nb_word + 1] = NULL;
	return (array);
}
