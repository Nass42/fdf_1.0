/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:12:07 by namohamm          #+#    #+#             */
/*   Updated: 2022/02/02 14:05:11 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = len;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		j = ft_strlen(s);
	str = ft_calloc(j + 1, sizeof(*str));
	if (!str)
		return (NULL);
	if (start > ft_strlen(s))
		return (str);
	while (i < j)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
