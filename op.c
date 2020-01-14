/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** operation for ia
*/

#include <stdlib.h>
#include "include/my.h"

void let_two(info_t *info, int *line, int *nb)
{
    for (int i = 0; i < info->nb_lines; i++) {
        if (info->line[i].nb_match > info->line[*line].nb_match)
            *line = i;
    }
    if (info->line[*line].nb_match == 2)
        let_one(info, line, nb);
    else
        *nb = info->line[*line].nb_match - 2;
}

void let_one(info_t *info, int *line, int *nb)
{
    for (int i = 0; i < info->nb_lines; i++) {
        if (info->line[i].nb_match > info->line[*line].nb_match)
            *line = i;
    }
    *nb = info->line[*line].nb_match - 1;
}

void rm_one(info_t *info, int *line, int *nb)
{
    for (int i = 0; i < info->nb_lines; i++) {
        if (info->line[i].nb_match > info->line[*line].nb_match)
            *line = i;
    }
    *nb = 1;
}
