/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:59:34 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/23 15:40:20 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_keys(int key, t_fdf **data)
{
	if (key == 126)
		(*data)->shift_y -= 10;
	if (key == 125)
		(*data)->shift_y += 10;
	if (key == 123)
		(*data)->shift_x -= 10;
	if (key == 124)
		(*data)->shift_x += 10;
	if (key == 13)
		(*data)->zoom -= 10;
	if (key == 1)
		(*data)->zoom += 10;
	if (key == 24)
		(*data)->my_z += 1;
	if (key == 27)
		(*data)->my_z -= 1;
}
