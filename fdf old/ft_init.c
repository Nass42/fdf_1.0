/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:49:17 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/23 07:06:17 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(fdf **data)
{
	(*data)->win_width = 1500;
	(*data)->win_height = 900;
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
