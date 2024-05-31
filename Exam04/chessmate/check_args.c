#include "chessmate.h"

int one_king(int ac, char *av[])
{
    int i = 0;
    int king = 0;
    while (ac > 1)
    {
        while (av[ac - 1][i])
        {
            if (av[ac - 1][i] == 'K')
                king++;
            i++;
        }
        i = 0;
        ac--;
    }
    if (king != 1)
        return (1);
    return (0);
}

char    *str_convert(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!((str[i] == '.') || (str[i] == 'P') || (str[i] == 'B')
            || (str[i] == 'R') || (str[i] == 'Q') || (str[i] == 'K')))
            str[i] = '.';
        i++;
    }
    return (str);
}

char    *check_args(int ac, char *av[])
{
    int size = ft_strlen(av[1]);
    int arg_count = ac;
    while (ac > 1)
    {
        if (ft_strlen(av[ac - 1]) == size)
            ac--;
        else
            return (NULL);
    }
    ac = arg_count;
    while (ac > 1)
    {
        av[ac - 1] = str_convert(av[ac - 1]);
        ac--;
    }
    ac = arg_count;
    if (one_king(ac, av) == 1)
        return (NULL);
    board_sjoin(ac, av);
    return (av[1]);
}