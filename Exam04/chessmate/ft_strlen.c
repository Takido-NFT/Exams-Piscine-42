#include "chessmate.h"

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_strlenln(char *str)
{
    int i = 0;
    while (str[i - 1] != '\n')
        i++;
    return (i);
}