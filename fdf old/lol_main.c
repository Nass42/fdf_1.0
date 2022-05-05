/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:02:53 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/23 07:02:41 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, fdf **param)
{
	ft_keys(key, &(*param));
	if (key == 34)
		(*param)->alpha += 5;
	if (key == 40)
			(*param)->alpha -= 5;
	if (key == 37)
		(*param)->theta += 5;
	if (key == 38)
		(*param)->theta -= 5;
	if (key == 32)
		(*param)->gamma += 5;
	if (key == 31)
		(*param)->gamma -= 5;
	if (key == 8)
		(*param)->col1 += 1;
	if (key == 9)
		(*param)->col2 += 1;
	mlx_clear_window((*param)->mlx_ptr, (*param)->win_ptr);
	ft_draw(&(*param));
	return (0);
}

int	main(int ac, char **av)
{
	int	fd;
	int	i;
	fdf	*data;

	data = (fdf *)malloc(sizeof(fdf));
	ft_get_height(av[1], &data);
	ft_get_width(av[1], &data);
	ft_read_file(av[1], &data);
	ft_read_col(av[1], &data);
	ft_init(&data);
	if (data->width > 100)
		data->zoom = 2;
	else
		data->zoom = 40;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1500, 900, "FDF");
	ft_draw(&data);
	mlx_key_hook(data->win_ptr, deal_key, &data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
