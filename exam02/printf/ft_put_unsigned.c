/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:21:13 by namohamm          #+#    #+#             */
/*   Updated: 2022/03/02 16:22:11 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_unsigned_putnbr(unsigned int nb)
{
	int	len;

	len = ft_unsigned_len(nb);
	if (nb >= 0 && nb <= 9)
		ft_int_putchar(nb + 48);
	else
	{
		ft_unsigned_putnbr(nb / 10);
		ft_unsigned_putnbr(nb % 10);
	}
	return (len);
}

int	ft_put_unsigned(unsigned int n)
{
	int	len;

	len = ft_unsigned_putnbr(n);
	return (len);
}
