//#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char   res;
    int i;

    res = 0;
    i = 8;
    while (i > 0)
    {
        res = res * 2 + (octet % 2);
        octet = octet / 2;
        i--;
    }
    return (res);
}
/*
int main(void)
{
    printf("%d", reverse_bits(25));
}
*/