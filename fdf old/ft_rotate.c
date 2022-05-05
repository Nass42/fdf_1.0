/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:14:01 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/23 07:26:57 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_rotate(fdf **data)
{
	double x1, y1, x2, y2, a , b, g;
	int  z1, z2, new_z1, new_z2;
	a = (*data)->alpha * M_PI / 180;
	b = (*data)->theta * M_PI / 180;
	g = (*data)->gamma * M_PI / 180;
	z1 = ((*data)->z_matrix)[((int)(*data)->y1) / (*data)->zoom][((int)(*data)->x1) / (*data)->zoom];
	z2 = ((*data)->z_matrix)[((int)(*data)->y2) / (*data)->zoom][((int)(*data)->x2) / (*data)->zoom];
	(*data)->color = ((*data)->z_col)[((int)(*data)->y1) / (*data)->zoom][((int)(*data)->x1) / (*data)->zoom];
	
	if (!(z1 || z2))
		ft_color(data, 'a');
	if ((z1 || z2) && (*data)->color == 0)
		ft_color(data, 'b');
	// else if ((*data)->color == 0)
	// if((*data)->color == 0)
	// 	(*data)->color = (z1 || z2) ? ft_color(data, 'a') : ft_color(data, 'b');
	//(*data)->color = (z1 || z2) ? 0xffffff : 0x800080;
	// printf("%d\n", z1);
	// (*data)->color = z1;
	/*-----------------------------------I N I T--------------------------------------*/
	double a11, a12, a13, a21, a22, a23, a31, a32, a33;

	x1 = (*data)->x1 - (*data)->ox;
	y1 = (*data)->y1 - (*data)->oy;
	x2 = (*data)->x2 - (*data)->ox;
	y2 = (*data)->y2 - (*data)->oy;
	
	a11 = cos(b) * cos(g);
	a12 = cos(b) * sin(g);
	a13 = -sin(b);
	
	a21 = sin(a) * sin(b) * cos(g) - cos(a) * sin(g);
	a22 = sin(a) * sin(b) * sin(g) + cos(a) * cos(g);
	a23 = sin(a) * cos(b);

	a31 = cos(a) * sin(b) * cos(g) + sin(a) * sin(g);
	a32 = cos(a) * sin(b) * sin(g) - sin(a) * cos(g);
	a33 = cos(a) * cos(b);
	
	/*------------------------------------F I R S T  P O I N T---------------------------------------------------------------------------------------------------------*/
	(*data)->x1 = x1 * a11 + y1 * a12 + (z1 * (*data)->my_z) * a13 + (*data)->ox + (*data)->shift_x + ((*data)->win_width / 2) - ((*data)->width * (*data)->zoom / 2);
	(*data)->y1 = x1 * a21 + y1 * a22 + (z1 * (*data)->my_z) * a23 + (*data)->oy + (*data)->shift_y + ((*data)->win_height / 2) - ((*data)->height * (*data)->zoom / 2);
	/*-----------------------------------S E C O N D  P O I N T--------------------------------------------------------------------------------------------------------*/
	(*data)->x2 = x2 * a11 + y2 * a12 + (z2 * (*data)->my_z) * a13 + (*data)->ox + (*data)->shift_x + ((*data)->win_width / 2) - ((*data)->width * (*data)->zoom / 2);
	(*data)->y2 = x2 * a21 + y2 * a22 + (z2 * (*data)->my_z) * a23 + (*data)->oy + (*data)->shift_y + ((*data)->win_height / 2) - ((*data)->height * (*data)->zoom / 2);
	/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/ 
	
}