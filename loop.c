/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** loop
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"

int check_nb(char *str)
{
    int i = 0;
    int len = my_strlen(str);
    int count = 0;

    for (; str[i]; i++) {
        if (str[i] <= '9' && str[i] >= '0' || str[i] == '\n') {
            count++;
        }
    }
    if (i == 0 || count != len) {
        my_putstr("Error: invalid input (positive number expected)");
        return (-1);
    }
    return (0);
}

int input(void)
{
    char *buf = NULL;
    size_t nb = 0;

    getline(&buf, &nb, stdin);
    if (buf[0] == '\0')
        return (-2);
    if (check_nb(buf) == -1)
        return (-1);
    return (my_getnbr(buf));
}

int get_line(info_t *info)
{
    int nb = 0;

    my_putstr("\nLine: ");
    nb = input();
    if (nb == -2) {
        my_putstr("\n");
        return (-2);
    }
    if (nb == -1)
        return (-1);
    if (nb > info->nb_lines || nb <= 0) {
        my_putstr("Error: this line is out of range");
        return (-1);
    }
    if (info->line[nb - 1].nb_match <= 0) {
        my_putstr("Error: this line is empty");
        return (-1);
    }
    return (nb);
}

int get_col(info_t *info, int line)
{
    int nb = 0;

    my_putstr("Matches: ");
    nb = input();
    if (nb == -1 || nb == -2) {
        my_putstr("\n");
        return (nb);
    } if (nb > info->max) {
        my_putstr("Error: you cannot remove more than ");
        my_putstr(my_int_to_str(info->max));
        my_putstr(" matches per turn\n");
        return (-1);
    } if (nb <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (-1);
    } if (nb > info->line[line - 1].nb_match) {
        my_putstr("Error: not enough matches on this line\n");
        return (-1);
    }
    return (nb);
}

int game_loop(info_t *info)
{
    int line = 0;
    int nb = 0;

    draw_map(info);
    while (info->end == 0) {
        my_putstr("\nYour turn:");
        if (get_info(info, &line, &nb) == -2)
            return (-2);
        info->line[line - 1].nb_match -= nb;
        put_removed(1, line, nb);
        draw_map(info);
        check_end(1, info);
        if (info->end == 0)
            ia(info);
    }
    return (0);
}
