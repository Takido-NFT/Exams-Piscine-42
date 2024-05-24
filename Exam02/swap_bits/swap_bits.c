//#include <stdio.h>

unsigned char   swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}
/*
int main(void)
{
    unsigned char octet = 18;

    printf("%d\n", swap_bits(octet));
}
*/