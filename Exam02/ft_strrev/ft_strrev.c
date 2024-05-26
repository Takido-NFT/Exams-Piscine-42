#include <stdio.h>

char    *ft_strrev(char *str)
{
    int     i;
    int     len;
    char    temp;

    i = 0;
    len = 0;
    while (str[len])
        len++;
    len -= 1;
    while (i < len)
    {
        temp = str[len];
        str[len] = str[i];
        str[i] = temp;
        len--;
        i++;
    }
    return (str);
}
/*
int main(void)
{
    char str[] = "abcde";
    printf("%s\n", ft_strrev(str));
}
*/