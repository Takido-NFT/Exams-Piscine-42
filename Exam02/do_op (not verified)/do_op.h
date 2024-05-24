#ifndef DO_OP_H
#define DO_OP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long int op_add(int first, int second)
{
    return ((long int)first + (long int)second);
}

long int op_sub(int first, int second)
{
    return ((long int)first - (long int)second);
}

long int op_div(int first, int second)
{
    return ((long int)first / (long int)second);
}

long int op_mul(int first, int second)
{
    return ((long int)first * (long int)second);
}

long int op_mod(int first, int second)
{
    return ((long int)first % (long int)second);
}

#endif