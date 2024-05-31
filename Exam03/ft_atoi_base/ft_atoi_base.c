//#include <stdio.h>

int ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int res = 0;
    int signe = 1;
    int num = 0;

    while ((str[i] >= 7 && str[i] <= 13) || (str[i] == ' '))
        i++;
    if ((str[i] == '+') || (str[i] == '-'))
    {
        if (str[i] == '-')
            signe = -1;
        i++;
    }
    while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
            || (str[i] >= 'A' && str[i] <= 'F'))
    {
        if (str[i] >= 'a' && str[i] <= 'f')
            num = str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            num = str[i] - 'A' + 10;
        else
            num = str[i] - '0';
        res = res * str_base + num;
        num = 0;
        i++;
    }
    return (res * signe);
}
/*
int main(void)
{
    printf("%d\n", ft_atoi_base("01000101", 2));
}
*/