#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;
	char	a;
	char	b;
	int		i;

	i = 0;
	if (argc == 4)
	{
		a = argv[2][0];
		b = argv[3][0];
		while(argv[1][i] != '\0')
		{
			if (argv[1][i] == a)
				argv[1][i] = b;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
