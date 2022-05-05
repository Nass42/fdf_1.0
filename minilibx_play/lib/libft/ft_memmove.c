/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:34:18 by namohamm          #+#    #+#             */
/*   Updated: 2022/02/01 12:31:09 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*crs;
	char	*dest;

	crs = (char *)src;
	dest = (char *)dst;
	if (crs < dest)
	{
		while (len--)
		{
			dest[len] = crs[len];
		}
	}
	else
		ft_memcpy(dest, crs, len);
	return (dst);
}
