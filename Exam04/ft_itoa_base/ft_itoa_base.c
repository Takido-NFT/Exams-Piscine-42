#include <stdlib.h>
//#include <stdio.h>

int ft_nbrlen(int value, int base)
{
    int i = 0;
    if (value == 0)
        i = 1;
    while (value > 0)
    {
        value /= base;
        i++;
    }
    return (i);
}

char	*ft_itoa_base(int value, int base)
{
    int negative;
    if (value < 0)
    {
        value = -value;
        if (base == 10)
            negative = 1;
    }
    int nbrlen = ft_nbrlen(value, base);
    char *array;

    if (!(array = malloc((nbrlen + 1 + negative) * sizeof(char))))
        return (NULL);
    array[nbrlen + negative] = '\0';
    if (value == 0)
    {
        array[0] = '0';
        return(array);
    }
    while (nbrlen > 0)
    {
        array[nbrlen - 1 + negative] = (value % base) + '0';
        value /= base;
        nbrlen--;
    }
    if (negative == 1)
        array[0] = '-';
    return (array);
}
/*
int main(void)
{
    int value = 42;
    int base = 4;
    printf("%s\n", ft_itoa_base(value, base));
}
*/