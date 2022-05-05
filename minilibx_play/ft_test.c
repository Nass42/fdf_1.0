/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 06:47:14 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/16 11:06:54 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/namohamm/Desktop/minilibx_play/lib/minilibx_macos/mlx.h"
#include <math.h>

/*--------------------------------------------------------------------*/ 
int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}
/*--------------------------------------------------------------------*/
int get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}
/*--------------------------------------------------------------------*/
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
/*--------------------------------------------------------------------*/ 
/*--------------------------------------------------------------------*/ 

int draw_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
{
	double x, y, dx, dy;
	int pixels;
	
	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	//color = rgb_to_int(2, 3, 4);
	pixels = sqrt((dx * dx) + (dy * dy));
	dx /= pixels;
	dy /= pixels;
	while (pixels)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		x += dx;
		y += dy;
		pixels--;
	}
	
	return (1);
}

int main()
{
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, 640, 360, "fdf");
	//draw_line(mlx_ptr, win_ptr, 0, 0, 640, 360, 0xffffff);
	void *img_ptr = mlx_new_image(mlx_ptr, 640, 360);
	
	int pixel_bits;
	int line_bytes;
	int endian;
	int color = 0xffffff;
	char *buffer = mlx_get_data_addr(img_ptr, &pixel_bits, &line_bytes, &endian);
	
	if (pixel_bits != 32)
		color = mlx_get_color_value(mlx_ptr, color);
	
	// for(int y = 0; y < 360; ++y)
	// for(int x = 0; x < 640; ++x)
	int y = 0;
	int x = 0;
	// while(y < 360)
	// {
	// 	while(x < 640)
	// 	{
	// 		int pixel = (y * line_bytes) + (x * 4);
	//     	if (endian == 1)        // Most significant (Alpha) byte first
	//     	{
	//     	    buffer[pixel + 0] = (color >> 24);
	//     	    buffer[pixel + 1] = (color >> 16) & 0xFF;
	//     	    buffer[pixel + 2] = (color >> 8) & 0xFF;
	//     	    buffer[pixel + 3] = (color) & 0xFF;
	//     	}
	//     	else if (endian == 0)   // Least significant (Blue) byte first
	//     	{
	//     	    buffer[pixel + 0] = (color) & 0xFF;
	//     	    buffer[pixel + 1] = (color >> 8) & 0xFF;
	//     	    buffer[pixel + 2] = (color >> 16) & 0xFF;
	//     	    buffer[pixel + 3] = (color >> 24);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
	for(int y = 0; y < 360; ++y)
	for(int x = 0; x < 640; ++x)
	{
	    buffer[(y * line_bytes) + x] = color;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	

	return (0);
}