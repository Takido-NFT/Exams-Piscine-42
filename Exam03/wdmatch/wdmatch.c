#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int main(int ac, char *av[])
{
    int i;
    int j;
    if (ac == 3)
    {
        i = 0;
        j = 0;
        while (av[2][i])
        {
            if ((av[2][i] == av[1][j]) && (j < ft_strlen(av[1])))
                j++;
            i++;
        }
        if (j == ft_strlen(av[1]))
        {
            i = 0;
            while (av[1][i])
            {
                write(1, &av[1][i], 1);
                i++;
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}