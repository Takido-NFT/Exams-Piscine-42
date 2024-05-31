#include <unistd.h>

int main(int ac, char *av[])
{
    int i;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            if (av[1][i] >= 33 && av[1][i] <= 126)
            {
                write(1, &av[1][i], 1);
                if ((av[1][i + 1] >= 7 && av[1][i + 1] <= 13) || (av[1][i + 1] == ' '))
                    write(1, " ", 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}