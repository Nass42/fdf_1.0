/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:49:17 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/25 13:42:26 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_fdf **data)
{
	(*data)->w_w = 1500;
	(*data)->w_h = 900;
	(*data)->shift_x = 10;
	(*data)->shift_y = 10;
	(*data)->my_z = 3;
	(*data)->alpha = 0;
	(*data)->theta = 0;
	(*data)->gamma = 0;
	(*data)->col1 = 0;
	(*data)->col2 = 0;
	(*data)->count = 0;
}
