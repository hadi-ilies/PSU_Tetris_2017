/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>

void merge_sort (int *array1, int *array2, int *array3, int size1, int size2);
int sort_b(int *array1, int size)
{
	int *array2 = 0;
	int i = 0;
	int cut = size / 2;
	int *array3 = 0;

	array2 = malloc(sizeof(int *) * cut);
	array3 = malloc(sizeof(int *) * (size - cut));
	if(size < 2)
		return (84);
	else {
		for (i = 0; i < cut; i++) {
			array2[i] = array1[i];
		}
		for (i = cut; i < size; i++)
			array3[i - cut] = array1[i];

		sort_b(array2, cut);
		sort_b(array3, size - cut);
		merge_sort(array1, array2, array3, cut, size - cut);

	}
}

void merge_sort (int *result, int *array1, int *array2, int size1, int size2)
{
	int i1 = 0;
	int ir = 0;
	int i2 = 0;

	for (; i1 < size1 && i2 < size2; ir++) {
		if (array2[i2] > array1[i1])
			result[ir] = array1[i1++];
		else {
			result[ir] = array2[i2++];
		}
	}
	for (; i1 < size1; ir++) {
		result[ir] = array1[i1++];
	}
	for (; i2 < size2; ir++) {
		result[ir] = array2[i2++];
	}
}
