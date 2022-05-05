#include <unistd.h>


int is_capital(char c)
{
	if (c <= 90 && c >= 65)
		return (1);
	return (0);
}

void make_lower(char c)
{
}


int main(int ac, char **av)
{
	int i = 0;
	int	temp = 0;

	if (ac == 2)
	{
		while (av[1][i])
		{
			if(is_capital(av[1][i]))
			{
				temp = av[1][i] + 32;
				write(1, "_", 1);
				write(1, &temp, 1);
				//i++;
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
