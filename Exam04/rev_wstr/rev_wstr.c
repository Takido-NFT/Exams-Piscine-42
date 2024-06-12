#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int is_end(char c)
{
    if (c <= 32 || c == '\0')
        return (1);
    return (0);
}

char    **ft_split(char *str)
{
    char    **split;
    int     i = 0;
    int     j = 0;
    int     arrays = 0;

    while (str[i])
    {
        if (str[i] >= 33 && str[i] <= 126)
        {
            if (is_end(str[i + 1]) == 1)
                arrays++;
        }
        i++;
    }

    split = malloc((arrays + 1) * sizeof(char *));

    split[arrays] = NULL;

    i = 0;
    arrays = 0;
    while (str[i])
    {
        if (str[i] >= 33 && str[i] <= 126)
        {
            j++;
            if (is_end(str[i + 1]) == 1)
            {
                split[arrays] = malloc((j + 1) * sizeof(char));
                arrays++;
                j = 0;
            }
        }
        i++;
    }

    i = 0;
    j = 0;
    int strs = 0;
    while (str[i])
    {
        if (str[i] >= 33 && str[i] <= 126)
        {
            split[strs][j] = str[i];
            j++;
            if (is_end(str[i + 1]) == 1)
            {
                split[strs][j] = '\0';
                strs++;
                j = 0;
            }
        }
        i++;
    }
    return (split);
}

int main(int ac, char *av[])
{
    int     i = 0;
    int     j = 0;
    int     num_words = 0;
    char    **split;

    if (ac == 2)
    {
        split = ft_split(av[1]);
        while (split[num_words])
            num_words++;
        i = num_words - 1;
        while (i >= 0)
        {
            while (split[i][j])
            {
                write(1, &split[i][j], 1);
                j++;
            }
            if (i >= 1)
                write(1, " ", 1);
            free(split[i]);
            j = 0;
            i--;
        }
        free(split);
    }
    write(1, "\n", 1);
    return (0);
}
