/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** malloc_error
*/

#include <stdlib.h>

char *malloc_str(int lenght)
{
    char *str = malloc(sizeof(char) * (lenght + 1));

    if (str == NULL) {
        return (NULL);
    }
    for (int i = 0; i <= lenght; i++) {
        str[i] = ' ';
    }
    return (str);
}

char *malloc_back(int lenght)
{
    char *str = malloc(sizeof(char) * (lenght + 1));

    if (str == NULL) {
        return (NULL);
    }
    for (int i = 0; i <= lenght; i++) {
        str[i] = '\0';
    }
    return (str);
}
