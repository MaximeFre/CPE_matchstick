/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** loop
*/

#include <stdlib.h>
#include <unistd.h>
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
        return (84);
    }
    return (0);
}

int input(void)
{
    char *buf = malloc_back(20);

    read(0, buf, 19);
    if (check_nb(buf) == 84)
        return (84);

    return (my_getnbr(buf));
}

int get_line(info_t *info)
{
    int nb = 0;

    my_putstr("\nLine: ");
    nb = input();
    if (nb == 84)
        return (84);
    if (nb > info->nb_lines || nb <= 0) {
        my_putstr("Error: this line is out of range");
        return (84);
    }
    if (info->line[nb - 1].nb_match <= 0) {
        my_putstr("Error: this line is empty");
        return (84);
    }
    return (nb);
}

int get_col(info_t *info, int line)
{
    int nb = 0;

    my_putstr("Matches: ");
    nb = input();
    if (nb == 84) {
        my_putstr("\n");
        return (84);
    } if (nb > info->max) {
        my_putstr("Error: you cannot remove more than ");
        my_putstr(my_int_to_str(info->max));
        my_putstr(" matches per turn\n");
        return (84);
    } if (nb <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (84);
    } if (nb > info->line[line - 1].nb_match) {
        my_putstr("Error: not enough matches on this line\n");
        return (84);
    }
    return (nb);
}

void game_loop(info_t *info)
{
    int line = 0;
    int nb = 0;

    draw_map(info);
    while (info->end == 0) {
        my_putstr("\nYour turn:");
        line = get_line(info);
        while (line == 84)
            line = get_line(info);
        nb = get_col(info, line);
        while (nb == 84)
            nb = get_col(info, line);
        info->line[line - 1].nb_match -= nb;
        put_removed(1, line, nb);
        draw_map(info);
        check_end(1, info);
        if (info->end == 0)
            ia(info);
    }
}
