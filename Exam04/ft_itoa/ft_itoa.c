#include <stdlib.h>
#include <stdio.h>

int ft_nbrlen(int nbr)
{
    int i = 0;
    if (nbr == 0)
        i = 1;
    while (nbr > 0)
    {
        nbr /= 10;
        i++;
    }
    return (i);
}

char    *ft_itoa(int nbr)
{
    int negative = 0;
    if (nbr < 0)
    {
        nbr = -nbr;
        negative = 1;
    }
    int nbrlen = ft_nbrlen(nbr);
    char *array;

    if (!(array = malloc((nbrlen + 1 + negative) * sizeof(char))))
        return (NULL);
    array[nbrlen + negative] = '\0';
    if (nbr == 0)
    {
        array[0] = '0';
        return (array);
    }
    while (nbrlen > 0)
    {
        array[nbrlen - 1 + negative] = (nbr % 10) + '0';
        nbr /= 10;
        nbrlen--;
    }
    if (negative == 1)
        array[0] = '-';
    return (array);
}

int main(void)
{
    int nbr = 0;
    printf("%s\n", ft_itoa(42));
}