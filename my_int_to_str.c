/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** my_int_to_str
*/

#include <stdio.h>
#include <stdlib.h>

char *cpmystr(char *str, int nb, int nb2, int a)
{
    int cp;

    str[a - 1] = '\0';
    for (int j = a - 2; j >= 0; j--) {
        if (nb >= 10) {
            cp = nb % 10;
            nb = nb - cp;
            nb = nb / 10;
            str[j] = cp + '0';
        } else
            str[j] = nb + '0';
    }
    return (str);
}

char *my_int_to_str(int nb)
{
    int nb2 = nb;
    char *str;
    int a = 0;

    a = 1;
    while (nb2 >= 0) {
        nb2 = nb2 / 10;
        a++;
        if (nb2 == 0)
            nb2 = -1;
    }
    str = malloc(sizeof(char) * a);
    return (cpmystr(str, nb, nb2, a));
}
