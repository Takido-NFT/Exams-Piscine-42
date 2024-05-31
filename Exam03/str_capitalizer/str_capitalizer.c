#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    int j;

    if (ac > 1)
    {
        i = 0;
        j = 1;
        while (ac > 1)
        {
            while (av[j][i])
            {
                if (av[j][i] >= 33 && av[j][i] <= 126)
                {
                    if (!(av[j][i - 1] >= 33 && av[j][i - 1] <= 126))
                    {
                        if (av[j][i] >= 'a' && av[j][i] <= 'z')
                           av[j][i] -= 32;
                    }
                    else if (av[j][i] >= 'A' && av[j][i] <= 'Z')
                        av[j][i] += 32;
                }
                write(1, &av[j][i], 1);
                i++;
            }
            write(1, "\n", 1);
            i = 0;
            j++;
            ac--;
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}