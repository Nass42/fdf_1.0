#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// int ft_strhex_int(char *str)
// {
// 	int nbr;
// 	int i;
	
// 	nbr = 0;
// 	i = 0;
// 	int len = strlen(str);
// 	while (str[i] != 'x')
// 		i++;
// 	i++;
// 	//printf("i = %d\n", i);
// 	while (i < len)
// 	{
// 		if (str[i] >= '0' && str[i] <= '9')
// 			nbr = 16 * nbr + str[i] - '0';
// 		else if (str[i] >= 'a' && str[i] <= 'f')
// 			nbr = 16 * nbr + str[i] - 'a' + 10;
// 		else if (str[i] >= 'A' && str[i] <= 'F')
// 			nbr = 16 * nbr + str[i] - 'A' + 10;
// 		i++;
// 	}
// 	// printf("nbr = %d\n", nbr);
// 	// fflush(stdout);
// 	return(nbr);
// }


void printRandoms(int lower, int upper, 
                             int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        printf("%d ", num);
    }
}



int ft_random_color(void)
{
	int i = 0;
	int color;
	while (i < 100)
	{
		color = (MATH.random() % 16777215);
		i++;
	}
	return (color);
}


int main(void)
{
	char *str;

	str = "0xFF0000";
	printf("%x\n", ft_random_color());
	return (0);
}