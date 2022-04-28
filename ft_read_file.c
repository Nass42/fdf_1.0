/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:41:49 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/28 17:57:18 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	ft_words(char *s, char c)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (s[i++])
// 		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
// 			count++;
// 	return (count);
// }

void	ft_get_height(char *str, t_fdf **data)
{
	int	fd;
	int	height;

	height = 0;
	fd = open(str, O_RDONLY, 0);
	while (get_next_line(fd))
		height++;
	close(fd);
	(*data)->height = height;
}

void	ft_get_width(char *str, t_fdf **data)
{
	int	width;
	int	fd;

	fd = open(str, O_RDONLY, 0);
	(*data)->width = ft_words(get_next_line(fd), ' ');
	close(fd);
}

int	*fill_matrix(char *line)
{
	char	**str;
	int		*z_line;
	int		i;
	int		len;

	i = 0;
	len = ft_words(line, ' ');
	z_line = (int *)malloc(sizeof(int) * (len + 1));
	if (!z_line)
		return (NULL);
	str = ft_split(line, ' ');
	while (str[i])
	{
		z_line[i] = ft_atoi(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	return (z_line);
}

void	ft_read_file(char *file, t_fdf **data)
{
	int	fd;
	int	i;

	i = 0;
	(*data)->z_matrix = (int **)malloc(sizeof(int *) * ((*data)->height + 1));
	if (!(*data)->z_matrix)
		return ;
	fd = open(file, O_RDONLY, 0);
	while (i < (*data)->height)
	{
		printf("res %d %d\n", i, (*data)->height);
		// (*data)->z_matrix[i] = fill_matrix(get_next_line(fd));
		printf("result : %s\n", get_next_line(fd));
		
		i++;
	}
	(*data)->z_matrix[i] = NULL;
	close(fd);
}
