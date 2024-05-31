int is_power_of_2(unsigned int n)
{
    unsigned int res;

    res = 0;
    if (n == 0 || n == 1)
        return (0);
    while (res * res < n)
        res++;
    if (res * res == n)
        return (1);
    return (0);
}