#include <stdlib.h>
//#include <stdio.h>

int *ft_rrange(int start, int end)
{
    int *array;
    int size;
    int i = 0;
    if (start < end)
    {
        size = start;
        while (size < end)
            size++;
        if (!(array = malloc(size * sizeof(int))))
            return (0);
        while (size >= start)
        {
            array[i] = size;
            i++;
            size--;
        }
    }
    else if (start > end)
    {
        size = end;
        while (size < start) 
            size++;
        if (!(array = malloc(size * sizeof(int))))
            return (0);
        size = end;
        while (size <= start)
        {
            array[i] = size;
            i++;
            size++;
        }
    }
    else if (start == end)
    {
        if (!(array = malloc(1 * sizeof(int))))
            return (0);
        array[0] = start;
    }
    return (array);
}
/*
int main(void)
{
    int start = 0;
    int end = -3;
    int *array;
    int i = 0;

    array = ft_rrange(start, end);
    while (i < 4)
    {
        printf("%d, ", array[i]);
        i++;
    }
    printf("\n");
    free(array);
}
*/