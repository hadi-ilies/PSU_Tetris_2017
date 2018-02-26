/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** my_printf.h
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdlib.h>

size_t my_putchar(int fd, char c);
size_t my_putstr(int fd, char *str);
size_t my_putnbr(int fd, int nb);
size_t my_printf(int fd, char *str, ...);

#endif
