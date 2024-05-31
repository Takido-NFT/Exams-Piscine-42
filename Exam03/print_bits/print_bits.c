#include <unistd.h>

void    print_bits(unsigned char octet)
{
    unsigned char res;
    unsigned char comp;
    int i;

    comp = 1;
    i = 7;
    while (i >= 0)
    {
        res = octet >> i;
        res = res & comp;
        if (res >= 1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        res = 0;
        i--;
    }
}