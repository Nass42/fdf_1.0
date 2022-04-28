/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 08:58:57 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/28 18:00:49 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFFER_SIZE 111
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "minilibx_macos/mlx.h"

typedef struct	s_i 
{
	void	*i_p;
	char	*ad;
	int		bpp;
	int		ll;
	int		endian;
}	t_i;

typedef struct s_fdf
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
	int		w_w;
	int		w_h;
	int		tmp2[4];
	int		**z_matrix;
	int		**z_col;
	char	flag;
	char	flagi;
	void	*m_p;
	void	*w_p;
	double	alpha;
	double	theta;
	double	gamma;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	x111;
	double	x222;
	double	y111;
	double	y222;
	double	z1;
	double	z2;
	double	ox;
	double	oy;
	double	a1;
	double	b1;
	double	a2;
	double	b2;
	double	a3;
	double	b3;
	double	a4;
	double	b4;
	double	dx;
	double	dy;
	double	s1;
	double	s2;
	double	tmp;
	double	swap;
	double	m;
	double	x21;
	double	y21;
	double	x22;
	double	y22;
	double	a11;
	double	a12;
	double	a13;
	double	a21;
	double	a22;
	double	a23;
	double	a31;
	double	a32;
	double	a33;
	int		x;
	int		y;
	int		i;
	t_i		*img;
}	t_fdf;



char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const	char *str);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_read_file(char *file, t_fdf **data);
void	ft_get_height(char *str, t_fdf **data);
void	ft_get_width(char *str, t_fdf **data);
void	ft_read_col(char *file, t_fdf **data);
void	ft_init(t_fdf **data);
void	ft_bresenham(double x, double y, t_fdf **data, char flagi);
void	ft_draw(t_fdf **data);
void	ft_rotate_x(t_fdf **data);
void	ft_rotate_y(t_fdf **data);
void	ft_rotate_z(t_fdf **data);
void	ft_rotate(t_fdf **data);
int		ft_words(char const *s, char c);
void	ft_color(t_fdf **data, char c);
void	ft_keys(int key, t_fdf **data);
// int		ft_count_word(char *s, char c);
void	my_mlx_pixel_put(t_fdf **d, int x, int y, int color);

#endif
