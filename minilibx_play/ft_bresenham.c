/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:14:14 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/17 18:14:20 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bresenham(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
	int x, y, dx, dy, s1, s2, tmp, swap, D, i;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	s1 = get_sign(x1 - x0);
	s2 = get_sign(y1 - y0);
	x = x0;
	y = y0;
	swap = 0;
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
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
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