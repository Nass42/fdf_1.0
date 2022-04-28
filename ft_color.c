/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:28:53 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/23 15:43:24 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color(t_fdf **data, char c)
{
	int	col[10];

	col[0] = 0xc09966;
	col[1] = 0x0d8767;
	col[2] = 0x293c28;
	col[3] = 0xaa33cc;
	col[4] = 0x80d7cc;
	col[5] = 0xdc19a0;
	col[6] = 0x800000;
	col[7] = 0x391e3a;
	col[8] = 0xcbbeb5;
	col[9] = 0xffffff;
	if ((*data)->col1 > 9)
		(*data)->col1 = 0;
	else if ((*data)->col1 < 0)
		(*data)->col1 = 9;
	if ((*data)->col2 > 9)
		(*data)->col2 = 0;
	else if ((*data)->col2 < 0)
		(*data)->col2 = 9;
	if (c == 'a')
		(*data)->color = col[(*data)->col1];
	else if (c == 'b')
		(*data)->color = col[(*data)->col2];
}
