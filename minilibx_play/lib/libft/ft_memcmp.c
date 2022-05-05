/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:59:43 by namohamm          #+#    #+#             */
/*   Updated: 2022/02/02 14:03:09 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (i < n)
	{
		if (((unsigned const char *)s1)[i] != ((unsigned const char *)s2)[i])
			return (((unsigned const char *)s1)[i] -
					((unsigned const char *)s2)[i]);
		i++;
	}
	return (0);
}
