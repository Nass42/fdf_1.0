/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:42:01 by namohamm          #+#    #+#             */
/*   Updated: 2022/02/02 13:51:16 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	if (arg <= 'z' && arg >= 'a')
		return (1);
	else if (arg <= 'Z' && arg >= 'A')
		return (1);
	else if (arg <= '9' && arg >= '0')
		return (1);
	else
		return (0);
}
