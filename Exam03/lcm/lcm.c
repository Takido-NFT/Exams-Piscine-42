unsigned int    lcm(unsigned int a, unsigned int b)
{
    int res = 1;
    int highest = 0;
    int lcm;

    if ((a == 0) || (b == 0))
        return (0);
    if (a >= b)
        highest = a;
    else
        highest = b;
    while (res <= highest)
    {
        if ((a % res == 0) && (b % res == 0))
            lcm = res;
        res++;
    }
    return (lcm);
}