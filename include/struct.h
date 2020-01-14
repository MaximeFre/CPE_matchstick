/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** struct
*/

#pragma once

typedef struct line_s
{
    int nb_match;
    int start;
} line_t;

typedef struct ia_s
{
    int nb_line_rm;
    int nb_full;
    int nb_still;
    int only_one;
} ia_t;

typedef struct info_s
{
    int nb_lines;
    int nb_col;
    int max;
    line_t *line;
    int end;
    int who_won;
    ia_t ia;
} info_t;
