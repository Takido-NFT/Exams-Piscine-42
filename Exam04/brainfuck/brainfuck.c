#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void    print_brainfuck(char *str)
{
    int i = 0;
    int loop;
    char bytes[2048] = {0};
    char *ptr = bytes;
    
    while(str[i])
    {
        if (str[i] == '>')
            ptr++;
        else if (str[i] == '<')
            ptr--;
        else if (str[i] == '+')
            (*ptr)++;
        else if (str[i] == '-')
            (*ptr)--;
        else if (str[i] == '.')
            ft_putchar(*ptr);
        else if (str[i] == '[')
        {
            if (*ptr == 0)
            {
                loop = 1;
                while (loop > 0)
                {
                    i++;
                    if (str[i] == '[')
                        loop++;
                    if (str[i] == ']')
                        loop--;
                }
            }
        }
        else if (str[i] == ']')
        {
            if (*ptr != 0)
            {
                loop = 1;
                while (loop != 0)
                {
                    i--;
                    if (str[i] == ']')
                        loop++;
                    if (str[i] == '[')
                        loop--;
                }
            }
        }
        i++;
    }

}

int main(int ac, char *av[])
{
    if (ac == 2)
        print_brainfuck(av[1]);
    else
        write(1, "\n", 1);
    return (0);
}