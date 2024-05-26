//#include <stdio.h>

int max(int* tab, unsigned int len)
{
    int i;
    int max;

    i = 0;
    max = tab[0];
    if (len == 0)
        return (0);
    while (i < len)
    {
        if (max < tab[i])
            max = tab[i];
        i++;
    }
    return (max);
}
/*
int main(void)
{
    int tab[] = {};
    printf("Maximum is %d\n", max(tab, 5));
}
*/