/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *concat(char *s1, char *s2)
{
	int c = 0;
	char *str = my_malloc(sizeof(char) * (my_strlen(s1) +
				my_strlen(s2) + 1));

	for (int i = 0; s1[i] != '\0'; i++) {
		str[c] = s1[i];
		c++;
	}
	for (int j = 0; s2[j] != '\0'; j++) {
		str[c] = s2[j];
		c++;
	}
	str[c] = '\0';
	return (str);
}
