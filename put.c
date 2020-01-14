/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** put str
*/

#include <stdlib.h>
#include "include/my.h"

void put_removed(int bool, int line, int nb)
{
    if (bool == 1) {
        my_putstr("Player removed ");
        my_putstr(my_int_to_str(nb));
        my_putstr(" match(es) from line ");
        my_putstr(my_int_to_str(line));
        my_putstr("\n");
    } else {
        my_putstr("AI removed ");
        my_putstr(my_int_to_str(nb));
        my_putstr(" match(es) from line ");
        my_putstr(my_int_to_str(line));
        my_putstr("\n");
    }
}
