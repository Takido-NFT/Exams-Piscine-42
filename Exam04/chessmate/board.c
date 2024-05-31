#include "chessmate.h"

void    *board_sjoin(int ac, char *av[])
{
    char    *join;
    int size = ft_strlen(av[1]) * (ac - 1);
    int i = 0;
    int j = 0;

    if (!(join = malloc(size * sizeof(char) + 1)))
        return (NULL);
    while (ac > 1)
    {
        while (av[ac - 1][i])
        {
            join[j] = av[ac - 1][i];
            j++;
            i++;
        }
        join[j] = '\n';
        j++;
        i = 0;
        ac--;
    }
    join[j] = '\0';
    enemies(join);
    free(join);
    return (NULL);
}