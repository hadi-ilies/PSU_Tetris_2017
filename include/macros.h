/*
** EPITECH PROJECT, 2018
** macro
** File description:
** macro
*/

#pragma once
#define D_N display_name(item[j].filename)//mettre i
#define L_L my_strncmp(argv[*i], "-L", 2) == -1 && my_strncmp(argv[*i], "-l", 2) == -1
#define R_T my_strncmp(argv[*i], "-r", 2) == -1 && my_strncmp(argv[*i], "-t", 2) == -1
#define D_Q my_strncmp(argv[*i], "-d", 2) == -1 && my_strncmp(argv[*i], "-q", 2) == -1
#define P_W my_strncmp(argv[*i], "-p", 2) == -1 && my_strncmp(argv[*i], "-w", 2) == -1
#define D_LEV my_strncmp(argv[*i], "-D", 2) == -1 && my_strncmp(argv[*i], "--level=", 8) == -1
#define K_L my_strncmp(argv[*i], "--key-left=", 10) == -1
#define K_R my_strncmp(argv[*i], "--key-right=", 10) == -1
#define K_T my_strncmp(argv[*i], "--key-turn=", 10) == -1
#define K_D my_strncmp(argv[*i], "--key-drop", 10) == -1
#define K_Q my_strncmp(argv[*i], "--key-quit=", 10) == -1
#define K_P my_strncmp(argv[*i], "--key-pause=", 10) == -1
#define M_S my_strncmp(argv[*i], "--map-size=", 10) == -1
#define W_N my_strncmp(argv[*i], "--without-next", 10) == -1
#define DEG my_strncmp(argv[*i], "--debug", 8) == -1
