/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:07:33 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/04 15:14:42 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/namohamm/Desktop/minilibx_play/minilibx_macos/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>



/*--------------------------------------------------------------------*/
typedef struct
{
	double x;
	double y;
}	Point;

typedef struct
{
	Point A;
	Point B;
	Point C;
	Point D;
	Point O;
	double angle;
	void *mlx_ptr;
	void *win_ptr;
}	Square;

// typedef struct
// {
// 	int all;
// 	float x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
// } Cube ;C[6];
/*--------------------------------------------------------------------*/
void init()
{
	
}
/*--------------------------------------------------------------------*/
int get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}
/*--------------------------------------------------------------------*/
void	ft_bresenham(void *mlx_ptr, void *win_ptr, Point A, Point B)
{
	double x, y, dx, dy, s1, s2, tmp, swap, D, i;
	dx = fabs(B.x - A.x);
	dy = fabs(B.y - A.y);
	s1 = get_sign(B.x - A.x);
	s2 = get_sign(B.y - A.y);
	x = A.x;
	y = A.y;
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

float aprox(float n)
{
	if(n >= n + 0.5)
		n += 0.5;
	return (n);
}
/*--------------------------------------------------------------------*/
void ft_draw_square(void *mlx_ptr, void *win_ptr, Square K)
{
	ft_bresenham(mlx_ptr, win_ptr, K.A, K.B);
	ft_bresenham(mlx_ptr, win_ptr, K.A, K.C);
	ft_bresenham(mlx_ptr, win_ptr, K.B, K.D);
	ft_bresenham(mlx_ptr, win_ptr, K.D, K.C);
}
/*--------------------------------------------------------------------*/

void	ft_rotate(void *mlx_ptr, void *win_ptr, Point *A, Point O, double *angle)
{
	Point T;
	T.x = A->x;
	T.y = A->y;
	printf("%f \n", *angle);
	fflush(stdout);
	double my_cos = cos(*angle * 3.14 / 180);
	double my_sin = sin(*angle * 3.14 / 180);
	if (fabs(*angle) > 0)
	{
		A->x = ((A->x - O.x) * my_cos) + ((A->y - 200) * my_sin) + 200;
		A->y = -((T.x - O.y) * my_sin) + ((T.y - 200) * my_cos) + 200;
	}
	// else if (fabs(*angle) < 0)
	// {
	// 	A->x = ((A->x - O.x) * my_cos) - ((A->y - 200) * my_sin) + 200;
	// 	A->y = ((T.x - 200) * my_sin) + ((T.y - 200) * my_cos) + 200;
	// 	mlx_pixel_put(mlx_ptr, win_ptr, A->x, A->y, 0xff00000);
	// }
}

/*********************************/ 
/***********DEAL KEY*************/ 
/*********************************/ 
int deal_key(int key, Square *param)
{
	printf("%d\n", key);
	if (key == 123)
	{
		param->angle = 10;
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		ft_rotate(param->mlx_ptr, param->win_ptr, &param->A, param->O, &param->angle);
		ft_rotate(param->mlx_ptr, param->win_ptr, &param->B, param->O, &param->angle);
		ft_rotate(param->mlx_ptr, param->win_ptr, &param->C, param->O, &param->angle);
		ft_rotate(param->mlx_ptr, param->win_ptr, &param->D, param->O, &param->angle);
		ft_draw_square(param->mlx_ptr, param->win_ptr, *param);	
	}
	if (key == 124)
	{
		param->angle = -10;
		// mlx_clear_window(param->mlx_ptr, param->win_ptr);
		ft_rotate(param->mlx_ptr, param->win_ptr, &param->A, param->O, &param->angle);
		ft_rotate(param->mlx_ptr, param->win_ptr, &param->B, param->O, &param->angle);
		ft_rotate(param->mlx_ptr, param->win_ptr, &param->C, param->O, &param->angle);
		ft_rotate(param->mlx_ptr, param->win_ptr, &param->D, param->O, &param->angle);
		ft_draw_square(param->mlx_ptr, param->win_ptr, *param);
	}	
	printf("angle = %f\n", param->angle);
	//ft_rotate();
	//mlx_clear_window(param->mlx_ptr, param->win_ptr);
	return (0);
}

// void ft_rotate(int old_x, int old_y, int *new_x, int *new_y, int angle)
// {
// 	*new_x = old_x * cos(angle) - old_y * sin(angle);
// 	*new_y = old_x * sin(angle) + old_y * cos(angle);
// 	printf("%d", *new_x);
// }



int main(void)
{
	Square K;
	
	K.mlx_ptr = mlx_init();
	K.win_ptr = mlx_new_window(K.mlx_ptr, 400, 400, "lol");
/*--------------------------------------------------------------------*/
	// int ax, ay, bx, by, cx, cy, dx, dy;
	// ax = 100;
	// ay = 100;
	// bx = 100;
	// by = 100 + 200;
	// cx = 100 + 200;
	// cy = 100;
	// dx = 100 + 200;
	// dy = 100 + 200;
	
	// Point A, B, C, D, O;
	// A.x = 100;
	// A.y = 100;
	// B.x = 100;
	// B.y = 100 + 200;
	// C.x = 100 + 200;
	// C.y = 100;
	// D.x = 100 + 200;
	// D.y = 100 + 200;
	// O.x = 200;
	// O.y = 200;
	
	
	K.A.x = 100;
	K.A.y = 100;
	K.B.x = 100;
	K.B.y = 100 + 200;
	K.C.x = 100 + 200;
	K.C.y = 100;
	K.D.x = 100 + 200;
	K.D.y = 100 + 200;
	K.O.x = 200;
	K.O.y = 200;
	K.angle = 10;
	
	

/*--------------------------------------------------------------------*/
	//	 x   y				    x   y
	// A(ax, ay)--------------C(cx, cy)
	// |	   				  |
	// |		o(o,o)		  |
	// |					  |
	// B(bx, by)--------------D(dx, dy)
/*--------------------------------------------------------------------*/
	// int new_ax, new_ay, new_cx, new_cy, new_dx, new_dy, new_bx, new_by, tmp, angle;
	
	// float my_cos = cos(angle * 3.14 / 180);
	// float my_sin = sin(angle * 3.14 / 180);
/*------------------C(d, b)----------------------*/ 
	// new_cx = ((cx - 200) * my_cos) + ((cy - 200) * my_sin) + 200;
	// new_cy = -((cx - 200) * my_sin) + ((cy - 200) * my_cos) + 200;
	// mlx_pixel_put(mlx_ptr, win_ptr, new_cx, new_cy, 0xff00000);
	// printf("(%d, %d)", new_cx, new_cy);
/*------------------A(a, b)----------------------*/
	// new_ax = ((ax - 200) * my_cos) + ((ay - 200) * my_sin) + 200;
	// new_ay = -((ax - 200) * my_sin) + ((ay - 200) * my_cos) + 200;
	// mlx_pixel_put(mlx_ptr, win_ptr, new_ax, new_ay, 0xff00000);
	// printf("(%d, %d)", new_ax, new_ay);
/*------------------B(a, c)----------------------*/
	// new_bx = ((bx - 200) * my_cos) + ((by - 200) * my_sin) + 200;
	// new_by = -((bx - 200) * my_sin) + ((by - 200) * my_cos) + 200;
	// mlx_pixel_put(mlx_ptr, win_ptr, new_bx, new_by, 0xff00000);
	// printf("(%d, %d)", new_bx, new_by);
/*------------------D(d, c)----------------------*/
	// new_dx = ((dx - 200) * my_cos) + ((dy - 200) * my_sin) + 200;
	// new_dy = -((dx - 200) * my_sin) + ((dy - 200) * my_cos) + 200;
	// mlx_pixel_put(mlx_ptr, win_ptr, new_dx, new_dy, 0xff00000);
	// printf("(%d, %d)", new_dx, new_dy);
	// fflush(stdout);
	
/*--------------------------------------------------------------------*/

	
	mlx_pixel_put(K.mlx_ptr, K.win_ptr, 200, 200, 0xff00000); // center
	/*------------square----------------------*/
	ft_draw_square(K.mlx_ptr, K.win_ptr, K);
	// ft_rotate(mlx_ptr, win_ptr, &A, O, &angle);
	fflush(stdout);




	
	
	

/*--------------------------------------------------------------------*/
	mlx_key_hook(K.win_ptr, deal_key, &K);
	mlx_loop(K.mlx_ptr);
}
