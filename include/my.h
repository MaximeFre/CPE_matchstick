/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** my.h
*/

#pragma once

#include "struct.h"

int my_getnbr(char const *str);
int my_putstr(char const *str);
char *malloc_str(int lenght);
int game_loop(info_t *info);
void draw_map(info_t *info);
char *malloc_back(int lenght);
int my_strlen(char const *str);
char *my_int_to_str(int nb);
void put_removed(int bool, int line, int nb);
void ia(info_t *info);
void check_end(int bool, info_t *info);
void rm_max(info_t *info, int *line, int *nb);
void three_line(info_t *info, int *line, int *nb);
void two_line(info_t *info, int *line, int *nb);
void one_line(info_t *info, int *line, int *nb);
void rm_one(info_t *info, int *line, int *nb);
void let_one(info_t *info, int *line, int *nb);
void let_two(info_t *info, int *line, int *nb);
int get_info(info_t *info, int *line, int *nb);
int get_col(info_t *info, int line);
int get_line(info_t *info);
