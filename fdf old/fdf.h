/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 08:58:57 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/28 17:23:31 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFFER_SIZE 1000
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "minilibx_macos/mlx.h"

typedef struct
{
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		my_z;
	int		count;
	int		col1;
	int		col2;
	int		win_width;
	int		win_height;
	int		**z_matrix;
	int		**z_col;
	char	flag;
	void	*mlx_ptr;
	void	*win_ptr;
	double	alpha;
	double	theta;
	double	gamma;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	z1;
	double	z2;
	double	ox;
	double	oy;
}	fdf;

// typedef Points
// {
// 	double	x1;
// 	double	y1;
// 	double	x2;
// 	double	y2;
// }

char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_read_file(char *file, fdf **data);
void	ft_get_height(char *str, fdf **data);
void	ft_get_width(char *str, fdf **data);
void	ft_read_col(char *file, fdf **data);
void	ft_init(fdf **data);
void	ft_bresenham(double x1, double y1, double x2, double y2, fdf **data);
void	ft_draw(fdf **data);
void	ft_rotate_x(fdf **data);
void	ft_rotate_y(fdf **data);
void	ft_rotate_z(fdf **data);
void	ft_rotate(fdf **data);
void	ft_color(fdf **data, char c);
void	ft_keys(int key, fdf **data);

#endif
