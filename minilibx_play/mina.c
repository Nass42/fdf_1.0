/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mina.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:07:33 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/16 14:57:06 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/namohamm/Desktop/minilibx_play/lib/minilibx_macos/mlx.h"
#include <math.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/
int get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}
/*--------------------------------------------------------------------*/
void	ft_bresenham(void *mlx_ptr, void *win_ptr, int *a, int *b)
{
	int x, y, dx, dy, s1, s2, tmp, swap, D, i;
	dx = abs(a[0] - b[0]);
	dy = abs(a[1] - b[1]);
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


/*--------------------------------------------------------------------*/
// void ft_square(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
// {
	
// }
/*--------------------------------------------------------------------*/

int main(void)
{
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, 640, 320, "lol");
/*--------------------------------------------------------------------*/
	int a, b, c, d;
	int big_a[2];
	int big_b[2];
	int big_c[2];
	int big_d[2];
	
	big_a[0] = 640 / 2 - (200 / 2);
	big_a[1] = 320 / 2 - (150 / 2);
	big_b[0] = big_a[0] + 200;
	big_b[1] = 320 / 2 - (150 / 2);
	big_c[0] = big_b[0];
	big_c[1] = big_b[1] + 150;
	big_d[0] = big_a[0];
	big_d[1] = big_a[1] + 150;
	a = 640 / 2 - (200 / 2);
	b = 320 / 2 - (150 / 2);
	c = b + 150;
	d = a + 200;

/*--------------------------------------------------------------------*/
	int p = d;                        
/*--------------------------------------------------------------------*/
	
	mlx_pixel_put(mlx_ptr, win_ptr, 320, 160, 0xff00000);
	
	ft_bresenham(mlx_ptr, win_ptr, a, b, d, b);
	ft_bresenham(mlx_ptr, win_ptr, a, b, a, c);
	ft_bresenham(mlx_ptr, win_ptr, a, c, d, c);
	ft_bresenham(mlx_ptr, win_ptr, d, b, d, c);




	
	
	

/*--------------------------------------------------------------------*/

	mlx_loop(mlx_ptr);
}
