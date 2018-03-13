/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include "my.h"

char *inttostr(int nb)
{
	char *str = my_malloc(sizeof(char) * 20);
	int size = 1;

	if (nb == 0)
		return ("0");
	for (int nb2 = nb; nb2 >= 10; nb2 /= 10)
		size++;
	for (int i = 0; i <= size; i++)
		str[i] = '\0';
	for (int j = 1; nb > 0 ; j++) {
		str[size - j] =  nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
