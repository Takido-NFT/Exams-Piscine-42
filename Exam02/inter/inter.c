#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i;
	int	j;
	int	temp;
	int	check;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i] != '\0')
		{
			j = 0;
			check = 0;
			while (av[2][j] != '\0')
			{
				if (av[1][i] == av[2][j])
				{
					temp = 0;
					while (temp < i)
					{
						if (av[1][temp] == av[2][j])
						{
							check = 1;
							break;
						}
						temp++;
					}
					if (check == 0)
					{
						write(1, &av[2][j], 1);
						break;
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}