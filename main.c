/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** matchstick
*/

#include <stdlib.h>
#include "include/my.h"

char **fill_line(info_t *info, int i, char **map)
{
    int middle = 0;

    if (i == 0 || i == info->nb_lines + 1) {
        for (int a = 0; a < info->nb_col - 1; a++) {
            map[i][a] = '*';
        }
        map[i][info->nb_col - 1] = '\n';
        map[i][info->nb_col] = '\0';
    } else {
        middle = ((info->nb_col) / 2) - ((info->line[i - 1].start + 1) / 2);
        for (int a = middle; a < (middle + info->line[i - 1].nb_match); a++)
            map[i][a] = '|';
        map[i][0] = '*';
        map[i][info->nb_col - 2] = '*';
        map[i][info->nb_col - 1] = '\n';
        map[i][info->nb_col] = '\0';
    }
    return (map);
}

void draw_map(info_t *info)
{
    char **map = malloc(sizeof(char *) * (info->nb_lines + 3));

    map[info->nb_lines + 2] = NULL;
    for (int i = 0; i < (info->nb_lines + 2); i++) {
        map[i] = malloc_str(info->nb_col + 1);
        map = fill_line(info, i, map);
    }
    for (int i = 0; map[i] != NULL; i++)
        my_putstr(map[i]);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

void init_map(info_t *info, int ac, char **av)
{
    info->nb_lines = my_getnbr(av[1]);
    info->nb_col = 2 * (info->nb_lines - 1) + 4;
    info->line = malloc(sizeof(line_t) * info->nb_lines);
    info->end = 0;

    for (int i = 0; i < info->nb_lines; i++) {
        info->line[i].nb_match = (2 * i) + 1;
        info->line[i].start = (2 * i) + 1;
    }
}

int error(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100)
        return (84);
}

int main(int ac, char **av)
{
    info_t *info = malloc(sizeof(info_t));

    if (error(ac, av) == 84)
        return (84);
    info->max = my_getnbr(av[2]);
    init_map(info, ac, av);
    game_loop(info);
    if (info->who_won == 1)
        return (1);
    else
        return (2);
    return (0);
}
