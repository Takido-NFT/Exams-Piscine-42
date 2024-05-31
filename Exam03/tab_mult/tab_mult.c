#include <unistd.h>
#define INT_MAX 2147483647

int ft_atoi(char *str)
{
    int signe = 1;
    int res = 0;
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

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void print_tab(int tab)
{
    int i = 1;
    while (i <= 9)
    {
        ft_putnbr(i);
        write(1, " * ", 3);
        ft_putnbr(tab);
        write(1, " = ", 3);
        ft_putnbr(i * tab);
        write(1, "\n", 1);
        i++;
    }
}

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        if ((ft_atoi(av[1]) * 9) < INT_MAX)
            print_tab(ft_atoi(av[1]));
    }
    else
        write(1, "\n", 1);
    return (0);
}