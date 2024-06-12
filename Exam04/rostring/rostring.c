#include <unistd.h>
#include <stdlib.h>


/*
int is_alpha(char c)
{
    if (c >= 33 && c <= 126)
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

    while (str[i])
    {
        if (is_alpha(str[i]))
        {
            if (is_end(str[i + 1]))
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
    while (str[i])
    {
        if (is_alpha(str[i]))
        {
            split[arrays][j] = str[i];
            j++;
            if (is_end(str[i + 1]))
            {
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
    int     i = 0;
    int     j = 1;
    int     size = 0;
    char    *tmp;
    char    **split;

    if (ac == 2)
    {
        split = ft_split(av[1]);
        while(split[size])
            size++;
        tmp = split[0];
        split[0] = split[size];
        split[size] = tmp;
        size -= 1;
        while (size > 1)
        {
            tmp = split[size];
            split[size] = split[size - 1];
            split[size - 1] = tmp;
            size--;
        }
        while (split[i])
        {
            while (split[i][j])
            {
                write(1, &split[i][j], 1);
                j++;
            }
            free(split[i]);
            if (split[i + 1] != NULL)
                write(1, " ", 1);
            j = 0;
            i++;
        }
        free(split);
    }
    write(1, "\n", 1);
    return (0);
}
*/
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
    int     i = 0;
    int     j = 0;
    int     size = 0;
    char    *tmp;
    char    **split;

    if (ac == 2)
    {
        split = ft_split(av[1]);

        // Count the number of words
        while (split[size])
            size++;

        // Swap first and last words
        if (size > 0) {
            tmp = split[0];
            split[0] = split[size - 1];
            split[size - 1] = tmp;
        }

        // Print the words in reverse order
        while (size > 0)
        {
            size--;
            j = 0;
            while (split[size][j])
            {
                write(1, &split[size][j], 1);
                j++;
            }
            if (size > 0)
                write(1, " ", 1);
            free(split[size]);
        }
        free(split);
    }
    write(1, "\n", 1);
    return (0);
}