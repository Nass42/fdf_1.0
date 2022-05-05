/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:42:09 by namohamm          #+#    #+#             */
/*   Updated: 2022/03/02 16:53:45 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_int_len(int nb);
int	ft_int_putnbr(int n);
int	ft_int_putchar(char c);
int	ft_int_putstr(char *s);
int	ft_put_hex(unsigned int n, char flag);
int	ft_put_unsigned(unsigned int n);
int	ft_printf(const char *format, ...);
int	ft_search_flag(va_list arg, char flag);
int	ft_putptr(unsigned long n);

#endif
