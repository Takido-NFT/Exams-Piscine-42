#include "chessmate.h"

int main(int ac, char *av[])
{
    if ((ac > 2) && (ac < 9))
    {
        if (check_args(ac, av) == NULL)
            write(1, "Board Error", 11);
    }
    else
        write(1, "\n", 1); 
    return (0);
}