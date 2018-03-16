/*
** EPITECH PROJECT, 2018
** strcmp
** File description:
** strcmp
*/

int my_strcmp(char *s1, char *s2)
{
	for (int k = 0; s1[k] != '\0'; k++)
		if (s1[k] != s2[k])
			return (s1[k] - s2[k]);
	return (0);
}
