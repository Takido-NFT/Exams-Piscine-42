#include <unistd.h>

void    print_dec(int ac)
{
    int dec = 0;
    if (ac >= 10)
        print_dec(ac / 10);
    ac = ac % 10;
    dec = ac + '0';
    write(1, &dec, 1);
}

int main(int ac, char *av[])
{
    if (ac > 1)
        print_dec(ac - 1);
    else
        write(1, "0", 1);
    write(1, "\n", 1);
}