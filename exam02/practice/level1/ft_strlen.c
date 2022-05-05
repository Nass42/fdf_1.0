#include <stdio.h>

int	ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}


int main()
{
	printf("%d\n", ft_strlen("Hello"));
}
