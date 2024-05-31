#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char *av[])
{
    unsigned int first;
    unsigned int second;
    unsigned int div;
    unsigned int res = 0;
    if (ac == 3)
    {
        first = atoi(av[1]);
        second = atoi(av[2]);
        if (first >= second)
            div = first;
        else
            div = second;
        while (div > 1)
        {
            if ((first % div == 0) && (second % div == 0))
            {
                res = div;
                div = 1;
            }
            div--;
        }
        if (div == 1)
            res = 1;
        printf("%d", res);
    }
    printf("\n");
    return (0);
}