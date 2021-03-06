/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** getinfo
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

int get_info(info_t *info, int *line, int *nb)
{
    *line = -1;
    while (*line == -1 || *nb == -1) {
        *line = get_line(info);
        while (*line == -1)
            *line = get_line(info);
        if (*line == -2)
            return (-2);
        *nb = get_col(info, *line);
        if (*nb == -2) {
            my_putstr("\n");
            return (-2);
        }
    }
    return (0);
}
