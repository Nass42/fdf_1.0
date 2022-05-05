/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:48:49 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/21 14:40:03 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*int	ft_atoi(const char *str)
{
	int		result = 0;
	int		sign = 1;
	int		i = 0;
	while(str[i] == ' ' || str[i] >= 9 && str[i] <= 13 )
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * sign);
}*/

int ft_strhex_int(char *str)
{
	int n;
	n = 0;
	while (*str != 'x' && *str != 'X')
		str++;
		while (*(++str))
		{
			if(*str >= '0' && *str <= '9')
				n = 16 * n + *str - '0';
			else if (*str >= 'a' && *str <= 'f')
				n = 16 * n + *str - 'a' + 10;
			else if (*str >= 'A' && *str <= 'F')
				n = 16 * n + *str - 'a' + 10;
		}
	return (n);
}

int main()
{
	char *str = "15,0xfffff";
	printf("atoi = %d  || ft_atoi = %s\n", ft_strhex_int(str), str);
	//printf("%ld", LONG_);
	return (0);
}
