/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:14:01 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/24 14:26:07 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rot_part(t_fdf **d)
{
	(*d)->tmp2[0] += (*d)->ox + (*d)->shift_x + ((*d)->w_w / 2);
	(*d)->tmp2[1] += (*d)->oy + (*d)->shift_y + ((*d)->w_h / 2);
	(*d)->tmp2[2] += (*d)->ox + (*d)->shift_x + ((*d)->w_w / 2);
	(*d)->tmp2[3] += (*d)->oy + (*d)->shift_y + ((*d)->w_h / 2);
	(*d)->tmp2[0] -= ((*d)->width * (*d)->zoom / 2);
	(*d)->tmp2[1] -= ((*d)->height * (*d)->zoom / 2);
	(*d)->tmp2[2] -= ((*d)->width * (*d)->zoom / 2);
	(*d)->tmp2[3] -= ((*d)->height * (*d)->zoom / 2);
}

void	ft_matrot(t_fdf **d)
{
	double	a;
	double	b;
	double	c;

	a = (*d)->alpha * M_PI / 180;
	b = (*d)->theta * M_PI / 180;
	c = (*d)->gamma * M_PI / 180;
	(*d)->x111 = (*d)->x1 - (*d)->ox;
	(*d)->y111 = (*d)->y1 - (*d)->oy;
	(*d)->x222 = (*d)->x2 - (*d)->ox;
	(*d)->y222 = (*d)->y2 - (*d)->oy;
	(*d)->a11 = cos(b) * cos(c);
	(*d)->a12 = cos(b) * sin(c);
	(*d)->a13 = -sin(b);
	(*d)->a21 = sin(a) * sin(b) * cos(c) - cos(a) * sin(c);
	(*d)->a22 = sin(a) * sin(b) * sin(c) + cos(a) * cos(c);
	(*d)->a23 = sin(a) * cos(b);
	(*d)->a31 = cos(a) * sin(b) * cos(c) + sin(a) * sin(c);
	(*d)->a32 = cos(a) * sin(b) * sin(c) - sin(a) * cos(c);
	(*d)->a33 = cos(a) * cos(b);
}

void	ft_rotate(t_fdf **d)
{
	int		z[6];

	z[2] = (int)(*d)->y1;
	z[3] = (int)(*d)->x1;
	z[4] = (int)(*d)->y2;
	z[5] = (int)(*d)->x2;
	z[0] = ((*d)->z_matrix)[z[2] / (*d)->zoom][z[3] / (*d)->zoom];
	z[1] = ((*d)->z_matrix)[z[4] / (*d)->zoom][z[5] / (*d)->zoom];
	(*d)->color = ((*d)->z_col)[z[2] / (*d)->zoom][z[3] / (*d)->zoom];
	if (!(z[0] || z[1]))
		ft_color(d, 'a');
	if ((z[0] || z[1]) && (*d)->color == 0)
		ft_color(d, 'b');
	ft_matrot(d);
	(*d)->tmp2[0] = (z[0] * (*d)->my_z) * (*d)->a13;
	(*d)->tmp2[1] = (z[0] * (*d)->my_z) * (*d)->a23;
	(*d)->tmp2[2] = (z[1] * (*d)->my_z) * (*d)->a13;
	(*d)->tmp2[3] = (z[1] * (*d)->my_z) * (*d)->a23;
	ft_rot_part(d);
	(*d)->x1 = (*d)->x111 * (*d)->a11 + (*d)->y111 * (*d)->a12 + (*d)->tmp2[0];
	(*d)->y1 = (*d)->x111 * (*d)->a21 + (*d)->y111 * (*d)->a22 + (*d)->tmp2[1];
	(*d)->x2 = (*d)->x222 * (*d)->a11 + (*d)->y222 * (*d)->a12 + (*d)->tmp2[2];
	(*d)->y2 = (*d)->x222 * (*d)->a21 + (*d)->y222 * (*d)->a22 + (*d)->tmp2[3];
}
