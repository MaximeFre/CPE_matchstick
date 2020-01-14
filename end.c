/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** check if the game end
*/

#include <stdlib.h>
#include "include/my.h"

void check_end(int bool, info_t *info)
{
    int check = 0;

    for (int i = 0; i < info->nb_lines; i++) {
        if (info->line[i].nb_match != 0)
            check = 1;
    }
    if (check == 0 && bool == 1) {
        my_putstr("You lost, too bad ...\n");
        info->end = 1;
        info->who_won = 0;
    }
    if (check == 0 && bool == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        info->who_won = 1;
        info->end = 1;
    }
}
