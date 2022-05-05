#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ft_len(int nbr)
{
	int len;

	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int nbr)
{
	int len;
	char *str;

	len = ft_len(nbr);
	if (nbr <= 0)
		len += 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr == -2147483648)
	{
		str = "-2147483648";
		return (str);
	}
	len -= 1;
	while (nbr)
	{
		str[len] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
	}
	return (str);
}

int main()
{
	int nbr = 558965;
	printf("%s\n", ft_itoa(nbr));
	return (0);
}
