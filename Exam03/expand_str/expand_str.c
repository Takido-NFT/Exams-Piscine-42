#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    int j;
    int end;

    if (ac == 2)
    {
        i = 0;
        while (av[1][i])
        {
            if (av[1][i] >= 33 && av[1][i] <= 126)
            {
                write(1, &av[1][i], 1);
                if ((av[1][i + 1] >= 7 && av[1][i + 1] <= 13) || (av[1][i + 1] == ' '))
                {
                    j = i + 1;
                    end = 1;
                    while (av[1][j])
                    {
                        if (av[1][j] >= 33 && av[1][j] <= 126)
                            end = 0;
                        j++;
                    }
                    if (end == 0)
                        write(1, "   ", 3);
                }
            }
            i++;
        }

    }
    write(1, "\n", 1);
    return (0);
}