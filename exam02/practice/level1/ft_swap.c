#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

	printf("*a = %d || *b == %d", *a, *b);
}

int main(void)
{
	int a1 = 15;
	int *a;
	a = &a1;
	int b1 = 87;
	int *b;
	b = &b1;
	ft_swap(a, b);
	return (0);
}
