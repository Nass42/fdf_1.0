/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:36:43 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/23 07:53:20 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(fdf **data)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while(y < (*data)->height)
	{
		x = 0;
		while (x <= (*data)->width)
		{
			if(x < (*data)->width)
			{
				(*data)->x1 = x;
				(*data)->y1 = y;
				(*data)->x2 = x + 1;
				(*data)->x2 = y;
				ft_bresenham(x, y, x + 1, y, data);
			}
			if (y < (*data)->height - 1)
				ft_bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
