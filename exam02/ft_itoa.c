/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:45:10 by namohamm          #+#    #+#             */
/*   Updated: 2022/03/22 18:59:15 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int    ft_len(int n)
{
    int    i;

    i = 0;
    while (n)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char    *ft_itoa(int n)
{
    char    *str;
    int        i;
    long    nbr;

    i = n > 0 ? 0 : 1;
    nbr = n > 0 ? n : -n;
	i += ft_len(n);
    str = (char *)malloc(sizeof(char *) * (i + 1));
    if (!str)
        return (NULL);
    str[i] = '\0';
    while (nbr)
    {
        str[--i] = nbr % 10 + '0'; 
        nbr /= 10;
    }
    if (i == 1 && str[i] != '\0')
        str[--i] = '-';
	if (i == 1 && str[i] == '\0')
		str[--i] = '0';
    return (str);
}

int main()
{
    int n = -589;
    printf("=> %s\n", ft_itoa(n));
    return (0);
}
