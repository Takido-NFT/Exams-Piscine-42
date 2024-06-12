#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char    **ft_split(char *str)
{
    int     i = 0;
    int     size = 0;
    int     arrays = 0;
    int     strs = 0;
    char    **split;

    // First pass to count the number of words
    while (str[i])
    {
        if (str[i] >= 33 && str[i] <= 126)
        {
            if (str[i + 1] == '\0' || str[i + 1] < 33 || str[i + 1] > 126)
                arrays++;
            size++;
        }
        else if (size > 0)
        {
            arrays++;
            size = 0;
        }
        i++;
    }

    // Allocate memory for split array, including space for the NULL terminator
    split = malloc((arrays + 1) * sizeof(char *));
    if (!split)
        return NULL;

    // Second pass to allocate memory for each word
    i = 0;
    size = 0;
    while (str[i])
    {
        if (str[i] >= 33 && str[i] <= 126)
        {
            size++;
            if (str[i + 1] == '\0' || str[i + 1] < 33 || str[i + 1] > 126)
            {
                split[strs] = malloc((size + 1) * sizeof(char));
                if (!split[strs])
                    return NULL;  // Handle memory allocation failure
                size = 0;
                strs++;
            }
        }
        i++;
    }
    split[arrays] = NULL;  // Null-terminate the split array

    // Third pass to copy the words into the allocated memory
    i = 0;
    strs = 0;
    int j = 0;
    while (str[i])
    {
        if (str[i] >= 33 && str[i] <= 126)
        {
            split[strs][j++] = str[i];
            if (str[i + 1] == '\0' || str[i + 1] < 33 || str[i + 1] > 126)
            {
                split[strs][j] = '\0';
                j = 0;
                strs++;
            }
        }
        i++;
    }
    return (split);
}

int main(void)
{
    int i = 0;
    char str[] = "Hello World !";
    char    **split = ft_split(str);
    
    if (split == NULL)
    {
        printf("Memory allocation failed\n");
        return (1);
    }
    
    while (split[i] != NULL)
    {
        printf("%s\n", split[i]);
        free(split[i]);  // Free the allocated memory for each word
        i++;
    }
    free(split);  // Free the allocated memory for the split array

    return (0);
}
