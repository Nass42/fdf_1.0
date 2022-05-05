/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:14:17 by namohamm          #+#    #+#             */
/*   Updated: 2022/03/02 17:37:56 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned	int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_put_hex(unsigned int n, char flag)
{
	int	len;

	len = ft_hex_len(n);
	if (n >= 16)
	{
		ft_put_hex(n / 16, flag);
		ft_put_hex(n % 16, flag);
	}
	else
	{
		if (n <= 9)
			ft_int_putchar(n + '0');
		else
		{
			if (flag == 'x')
				ft_int_putchar(n - 10 + 'a');
			if (flag == 'X')
				ft_int_putchar(n - 10 + 'A');
		}
	}
	return (len);
}
