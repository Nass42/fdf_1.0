/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:36:43 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/28 13:58:13 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_fdf **data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (*data)->height)
	{
		x = 0;
		while (x <= (*data)->width)
		{
			if (x < (*data)->width - 1)
				ft_bresenham(x, y, data, 'a');
			if (y < (*data)->height - 1)
				ft_bresenham(x, y, data, 'b');
			x++;
		}
		y++;
	}
}
