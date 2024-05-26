#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    int len;
    int check;

    i = 0;
    len = 0;
    check = 0;
    if (ac == 2)
    {
        while (av[1][len])
            len++;
        while (len >= 0)
        {
            if (av[1][len] >= 33 && av[1][len] <= 126)
            {
                if (av[1][len - 1] == ' ' || (av[1][len - 1] >= 7 && av[1][len - 1] <= 13))
                    break;
            }
            len--;
        }
        if (len > 0)
            len -= 1;
        while (av[1][len])
        {
            if (av[1][len] >= 33 && av[1][len] <= 126)
                write(1, &av[1][len], 1);
            len ++;
        }
    }
    write(1, "\n", 1);
}