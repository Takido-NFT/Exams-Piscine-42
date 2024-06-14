/*
#include <stdio.h>

void print_sort(int *tab, unsigned int size)
{
    int i = 0;

    while (size > i)
    {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");
}
*/
void sort_int_tab(int *tab, unsigned int size)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    if (size <= 1)
        return ;
    while (i < size)
    {
        while (j < size)
        {
            if (tab[j] > tab[j + 1])
            {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
            j++;
        }
        j = 0;
        i++;
    }
    //print_sort(tab, size);
}
/*
int main(void)
{
    int tab[] = {4, 2, 1, 3};
    unsigned int size = 4;

    sort_int_tab(tab, size);
}
*/