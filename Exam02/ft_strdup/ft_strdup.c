#include <stdlib.h>
//#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;

	while (src[len])
		++len;
	if (!(dup = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dup[len] = '\0';
	while (len >= 0)
	{
		dup[len] = src[len];
		len--;
	}
	return (s);
}

/*
int main(void)
{
    char    src[] = "test";
    printf("%s\n", ft_strdup(src));
}
*/