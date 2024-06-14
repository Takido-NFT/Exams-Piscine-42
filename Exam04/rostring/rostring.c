#include <unistd.h>
#include <stdlib.h>

int is_alpha(char c)
{
    if ((c >= 33 && c <= 126))
        return (1);
    return (0);
}

int is_end(char c)
{
    if (c <= 32 || c == '\0')
        return (1);
    return (0);
}

char    **ft_split(char *str)
{
    int     i = 0;
    int     j = 0;
    int     arrays = 0;
    char    **split;

    // Count the number of words
    while (str[i])
    {
        if (is_alpha(str[i]))
        {
            if (is_end(str[i + 1]))
                arrays++;
        }
        i++;
    }
    // Allocate memory for split array
    split = malloc((arrays + 1) * sizeof(char *));
    split[arrays] = NULL;
    i = 0;
    arrays = 0;
    j = 0;
    // Allocate memory for each word
    while (str[i])
    {
        if (is_alpha(str[i]))
        {
            j++;
            if (is_end(str[i + 1]))
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
    arrays = 0;
    // Copy characters into split array
    while (str[i])
    {
        if (is_alpha(str[i]))
        {
            split[arrays][j] = str[i];
            j++;
            if (is_end(str[i + 1]))
            {
                split[arrays][j] = '\0';  // null terminate the string
                arrays++;
                j = 0;
            }
        }
        i++;
    }
    return (split);
}

int main(int ac, char *av[])
{
    int     array = 1;
    int     j = 0;
    int     size = 0;
    char    *tmp;
    char    **split;

    if (ac == 2)
    {
        split = ft_split(av[1]);
        while (split[array])
        {
            while (split[array][j])
            {
                write(1, &split[array][j], 1);
                j++;
            }
            write(1, " ", 1);
            array++;
            j = 0;
        }
        while (split[0][j])
        {
            write(1, &split[0][j], 1);
            j++;
        }
        free(split);
    }
    write(1, "\n", 1);
    return (0);
}