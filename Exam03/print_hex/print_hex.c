#include <unistd.h>

int ft_atoi(char *str)
{
    int res = 0;
    int signe = 1;
    int i = 0;

    while ((str[i] >= 7 && str[i] <= 13) || (str[i] == ' '))
        i++;
    if ((str[i] == '+') || (str[i] == '-'))
    {
        if (str[i] == '-')
            signe = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * signe);
}

void    print_hex(int n)
{
    if (n >= 16)
        print_hex(n / 16);
    n = n % 16;
    if (n > 9)
        n = 'W' + n;
    else
        n = '0' + n;
    write(1, &n, 1);
}

int main(int ac, char *av[])
{
    if (ac == 2)
        print_hex(ft_atoi(av[1]));
    write (1, "\n", 1);
}