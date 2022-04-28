/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:47:04 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/25 13:16:08 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

void	bres_frog(t_fdf **d)
{
	while ((*d)->i < (*d)->dx)
	{
		// mlx_pixel_put((*d)->m_p, (*d)->w_p, (*d)->x, (*d)->y, (*d)->color);
		my_mlx_pixel_put(d, (*d)->x, (*d)->y, (*d)->color);
		while ((*d)->m >= 0)
		{
			(*d)->m = (*d)->m - 2 * (*d)->dx;
			if ((*d)->swap)
				(*d)->x += (*d)->s1;
			else
				(*d)->y += (*d)->s2;
		}
		(*d)->m = (*d)->m + 2 * (*d)->dy;
		if ((*d)->swap)
			(*d)->y += (*d)->s2;
		else
			(*d)->x += (*d)->s1;
		(*d)->i++;
	}
}

void	bres_frag(t_fdf **d)
{
	(*d)->dx = fabs((*d)->x2 - (*d)->x1);
	(*d)->dy = fabs((*d)->y2 - (*d)->y1);
	(*d)->s1 = get_sign((*d)->x2 - (*d)->x1);
	(*d)->s2 = get_sign((*d)->y2 - (*d)->y1);
	(*d)->swap = 0;
	(*d)->x = (*d)->x1;
	(*d)->y = (*d)->y1;
	if ((*d)->dy > (*d)->dx)
	{
		(*d)->tmp = (*d)->dx;
		(*d)->dx = (*d)->dy;
		(*d)->dy = (*d)->tmp;
		(*d)->swap = 1;
	}
	(*d)->m = 2 * (*d)->dy - (*d)->dx;
	(*d)->i = 0;
	bres_frog(d);
}

void	ft_bresenham(double a, double b, t_fdf **d, char flagi)
{
	if (flagi == 'a')
	{
		(*d)->x1 = a * (*d)->zoom;
		(*d)->y1 = b * (*d)->zoom;
		(*d)->x2 = (a + 1) * (*d)->zoom;
		(*d)->y2 = b * (*d)->zoom;
	}
	else if (flagi == 'b')
	{
		(*d)->x1 = a * (*d)->zoom;
		(*d)->y1 = b * (*d)->zoom;
		(*d)->x2 = a * (*d)->zoom;
		(*d)->y2 = (b + 1) * (*d)->zoom;
	}
	(*d)->ox = (*d)->width * (*d)->zoom / 2;
	(*d)->oy = (*d)->height * (*d)->zoom / 2;
	ft_rotate(d);
	bres_frag(d);
}
