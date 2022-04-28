/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:02:53 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/28 17:41:48 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf **param)
{
	ft_keys(key, &(*param));
	if (key == 34)
		(*param)->alpha += 0.5;
	if (key == 40)
			(*param)->alpha -= 0.5;
	if (key == 37)
		(*param)->theta += 0.5;
	if (key == 38)
		(*param)->theta -= 0.5;
	if (key == 32)
		(*param)->gamma += 0.5;
	if (key == 31)
		(*param)->gamma -= 0.5;
	if (key == 8)
		(*param)->col1 += 1;
	if (key == 9)
		(*param)->col2 += 1;
	//mlx_clear_window((*param)->m_p, (*param)->w_p);
	mlx_destroy_image((*param)->m_p, (*param)->img->i_p);
	(*param)->img->i_p = mlx_new_image((*param)->m_p, (*param)->w_w, (*param)->w_h);
	(*param)->img->ad = mlx_get_data_addr((*param)->img->i_p, &((*param)->img->bpp), &((*param)->img->ll),
								&((*param)->img->endian));
	ft_draw(&(*param));
	mlx_put_image_to_window((*param)->m_p, (*param)->w_p, (*param)->img->i_p, 0, 0);
	return (0);
}

void	my_mlx_pixel_put(t_fdf **d, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < (*d)->w_w  && y < (*d)->w_h))
	{
		dst = (*d)->img->ad + (y * (*d)->img->ll + x * ((*d)->img->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

int	main(int ac, char **av)
{
	int		fd;
	t_fdf	*d;
	
	
	d = (t_fdf *)malloc(sizeof(t_fdf));
	// d->img = (t_i *)malloc(sizeof(t_i));
	
	
	
	ft_get_height(av[1], &d);
	ft_get_width(av[1], &d);
	ft_read_file(av[1], &d);
	ft_read_col(av[1], &d);
	
	int i, j;
	i = 0;
	j = 0;
	while (i < d->height)
	{
		while (j <= d->width)
		{
			printf("%3d", d->z_matrix[i][j]);
			j++;
			//printf("j=%d", j);
		}
		printf("\n");
		i++;
		j = 0;
		//printf("i=%d\n", i);
	}

	printf("%d\n", d->height);
	printf("%d\n", d->width);

	ft_init(&d);
	if (d->width > 100)
		d->zoom += 1;
	else
		d->zoom = 40;
	d->m_p = mlx_init();
	d->w_p = mlx_new_window(d->m_p, 1500, 900, "FDF");
	d->img->i_p = mlx_new_image(d->m_p, d->w_w, d->w_h);
	d->img->ad = mlx_get_data_addr(d->img->i_p, &(d->img->bpp), &(d->img->ll),
								&(d->img->endian));
	// ft_draw(&d);
	// mlx_key_hook(d->w_p, deal_key, &d);
	// mlx_put_image_to_window(d->m_p, d->w_p, d->img->i_p, 0, 0);
	// mlx_loop(d->m_p);
	return (0);
}
