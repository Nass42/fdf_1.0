/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:56:07 by namohamm          #+#    #+#             */
/*   Updated: 2022/03/02 17:38:31 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len_long(unsigned long n)
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

static int	ft_put_hex_long(unsigned long n)
{
	int	len;

	len = ft_hex_len_long(n);
	if (n >= 16)
	{
		ft_put_hex_long(n / 16);
		ft_put_hex_long(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_int_putchar(n + '0');
		else
			ft_int_putchar(n - 10 + 'a');
	}
	return (len);
}

int	ft_putptr(unsigned long n)
{
	int	len;

	len = ft_int_putstr("0x");
	len += ft_put_hex_long(n);
	return (len);
}
