/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** ia for matchstick
*/

#include <stdlib.h>
#include "include/my.h"

void decision(info_t *info, int *line, int *nb)
{
    if (info->ia.nb_still == 1)
        one_line(info, line, nb);
    if (info->ia.nb_still == 2)
        two_line(info, line, nb);
    if (info->ia.nb_still == 3)
        three_line(info, line, nb);
    if (info->ia.nb_still > 3)
        rm_max(info, line, nb);
}

void check_line(info_t *info)
{
    info->ia.nb_full = 0;
    info->ia.nb_line_rm = 0;
    info->ia.nb_still = 0;
    info->ia.only_one = 0;

    for (int i = 0; i < info->nb_lines; i++) {
        if (info->line[i].nb_match > info->max) {
            info->ia.nb_full += 1;
            info->ia.nb_still += 1;
        } else if (info->line[i].nb_match != 0) {
            info->ia.nb_line_rm += 1;
            info->ia.nb_still += 1;
        }
        if (info->line[i].nb_match == 1)
            info->ia.only_one += 1;
    }
}

void ia(info_t *info)
{
    int line = 0;
    int nb = 0;

    my_putstr("\nAI's turn...\n");
    check_line(info);
    decision(info, &line, &nb);
    info->line[line].nb_match -= nb;
    put_removed(0, line + 1, nb);
    draw_map(info);
    check_end(0, info);
}
