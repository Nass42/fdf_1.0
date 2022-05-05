#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	int count = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] <= 'Z' && av[1][i] >= 'A')
				count = av[1][i] - 64;
			else if (av[1][i] <= 'z' && av[1][i] >= 'a')
				count = av[1][i] - 96;
			while(count)
			{
				write(1, &av[1][i], 1);
				count--;
			}
			count = 1;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
