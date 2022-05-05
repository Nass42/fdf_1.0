#include <stdio.h>

int ft_pow(int n)
{
	int	i = 1;
	int res = 2;
	while (i < n)
	{
		res *= 2;
		if (res == n)
			return (1);
		i++;
	}
	return (0);
}
int main()
{
	printf("%d\n", ft_pow(128));
}
