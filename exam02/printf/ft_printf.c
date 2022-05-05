/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:05:57 by namohamm          #+#    #+#             */
/*   Updated: 2022/03/02 16:55:48 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_flag(va_list arg, char flag)
{
	int	len;

	len = 0;
	if (flag == 'c')
		len += ft_int_putchar(va_arg(arg, int));
	else if (flag == 's')
		len += ft_int_putstr(va_arg(arg, char *));
	else if (flag == 'p')
		len += ft_putptr(va_arg(arg, unsigned long));
	else if (flag == 'd' || flag == 'i')
		len += ft_int_putnbr(va_arg(arg, int));
	else if (flag == 'x')
		len += ft_put_hex(va_arg(arg, int), 'x');
	else if (flag == 'X')
		len += ft_put_hex(va_arg(arg, int), 'X');
	else if (flag == 'u')
		len += ft_put_unsigned(va_arg(arg, unsigned int));
	else if (flag == '%')
		len += ft_int_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{	
	int		len;
	int		count;
	va_list	arg;

	len = 0;
	count = 0;
	va_start(arg, format);
	while (format[count])
	{
		if (format[count] == '%')
		{
			len += ft_search_flag(arg, format[count + 1]);
			count++;
		}
		else
			len += write(1, &format[count], 1);
		count++;
	}
	va_end(arg);
	return (len);
}
