#include <stdio.h>
#include <stdlib.h>
/*char    *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}*/

char	*ft_strcpy(char *dest, char *src)
{
	int i;
	i = 0;
	dest = (char *)malloc(sizeof(char));
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

int main(void)
{
	char *s1;
	char *s2 = "My name is Nasser";
	printf("%s\n", ft_strcpy(s1, s2));
}
