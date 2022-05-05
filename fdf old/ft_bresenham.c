/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:47:04 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/23 07:29:46 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*--------------------------------------------------------------------*/
int get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}
/***********-----------Bresenham-------------------***********************/
void	ft_bresenham(double x1, double y1, double x2, double y2, fdf **data)
{
	double dx, dy, s1, s2, tmp, swap, D;
	int x, y, i;

	x1 *= (*data)->zoom;
	y1 *= (*data)->zoom;
	x2 *= (*data)->zoom;
	y2 *= (*data)->zoom;
	
	(*data)->x1 = x1;
	(*data)->y1 = y1;
	(*data)->x2 = x2;
	(*data)->y2 = y2;
	
	(*data)->ox = (*data)->width * (*data)->zoom / 2;
	(*data)->oy = (*data)->height * (*data)->zoom / 2;

	ft_rotate(data);
	x1 = (*data)->x1;
	y1 = (*data)->y1;
	x2 = (*data)->x2;
	y2 = (*data)->y2;
	dx = fabs(x2 - x1);
	dy = fabs(y2 - y1);
	s1 = get_sign(x2 - x1);
	s2 = get_sign(y2 - y1);
	swap = 0;

	x = x1;
	y = y1;
	if (dy > dx)
	{
		tmp = dx;
		dx = dy;
		dy = tmp;
		swap = 1;
	}
	D = 2 * dy - dx;
	i = 0;
	while (i < dx)
	{
		mlx_pixel_put((*data)->mlx_ptr, (*data)->win_ptr, x, y, (*data)->color);
		while (D >= 0)
		{
			D = D - 2 * dx;
			if (swap)
				x += s1;
			else
				y += s2;
		}
		D = D + 2 * dy;
		if (swap)
				y += s2;
			else
				x += s1;
		i++;
	}
}
