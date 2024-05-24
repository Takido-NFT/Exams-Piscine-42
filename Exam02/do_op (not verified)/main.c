#include "do_op.h"

#define MAX_INT 2147483647
#define MIN_INT -2147483648

long int dispatch(int first, char operator, int second)
{
    long int res;

    res = 0;
    if (operator == '+')
        res = op_add(first, second);
    else if (operator == '-')
        res = op_sub(first, second);
    else if (operator == '/')
        res = op_div(first, second);
    else if (operator == '*')
        res = op_mul(first, second);
    else if (operator == '%')
        res = op_mod(first, second);
    return (res);
}

int main(int ac, char *av[])
{
    int first;
    char operator;
    int second;
    long int res = 0;
    if (ac == 4)
    {
        first = atoi(av[1]);
        operator = av[2][0];
        second = atoi(av[3]);
        if ((first <= MAX_INT && first >= MIN_INT)
            && (second <= MAX_INT && second >= MIN_INT))
        {  
            res = dispatch(first, operator, second);
            if (res <= MAX_INT && res >= MIN_INT)
                printf("%ld\n", res);
        }
    }
    else
        printf("\n");
    return (0);
}