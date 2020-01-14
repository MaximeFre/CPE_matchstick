/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** fct line
*/

#include <stdlib.h>
#include "include/my.h"

void one_line(info_t *info, int *line, int *nb)
{
    if (info->ia.only_one == 1) {
        rm_one(info, line, nb);
        return;
    }
    if (info->ia.nb_full == 1) {
        rm_max(info, line, nb);
        return;
    } else {
        let_one(info, line, nb);
        return;
    }
}

void two_line(info_t *info, int *line, int *nb)
{
    if (info->ia.only_one == 2) {
        rm_one(info, line, nb);
        return;
    } if (info->ia.only_one == 1 && info->ia.nb_line_rm == 2) {
        rm_max(info, line, nb);
        return;
    } if (info->ia.nb_line_rm == 2) {
        let_two(info, line, nb);
        return;
    } if (info->ia.nb_full > 0) {
        rm_max(info, line, nb);
        return;
    }
}

void three_line(info_t *info, int *line, int *nb)
{
    if (info->ia.only_one == 3) {
        rm_one(info, line, nb);
        return;
    } if (info->ia.nb_full > 0) {
        rm_max(info, line, nb);
        return;
    } if (info->ia.only_one == 2 && info->ia.nb_line_rm > 1) {
        let_one(info, line, nb);
        return;
    } if (info->ia.only_one == 1 && info->ia.nb_line_rm > 2) {
        let_two(info, line, nb);
        return;
    } if (info->ia.nb_line_rm == 3) {
        let_two(info, line, nb);
        return;
    }
}

void rm_max(info_t *info, int *line, int *nb)
{
    for (int i = 0; i < info->nb_lines; i++) {
        if (info->line[i].nb_match > info->line[*line].nb_match)
            *line = i;
    }
    if (info->line[*line].nb_match >= info->max)
        *nb = info->max;
    else
        *nb = info->line[*line].nb_match;
}
