/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:23:32 by namohamm          #+#    #+#             */
/*   Updated: 2022/03/02 16:02:56 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_putnbr(int n)
{
	int	len;

	len = ft_int_len(n);
	if (n == -2147483648)
	{
		ft_int_putnbr(n / 10);
		ft_int_putchar('8');
		len = 11;
	}
	else if (n < 0)
	{
		ft_int_putchar('-');
		ft_int_putnbr(-n);
	}
	else
	{
		if (n > 9)
			ft_int_putnbr(n / 10);
		ft_int_putchar(48 + n % 10);
	}
	return (len);
}
