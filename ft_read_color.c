/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:42:46 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/28 17:52:33 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strhex_int(char *str)
{
	int	nbr;
	int	i;
	int	len;

	nbr = 0;
	i = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != 'x')
		i++;
	if (str[i] != 'x')
		return (nbr);
	i++;
	while (i < len)
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = 16 * nbr + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			nbr = 16 * nbr + str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			nbr = 16 * nbr + str[i] - 'A' + 10;
		i++;
	}
	if (!nbr)
		nbr = 0xffffff;
	return (nbr);
}

int	*fill_col(char *line)
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
		z_line[i] = ft_strhex_int(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	return (z_line);
}

void	ft_read_col(char *file, t_fdf **data)
{
	int	fd;
	int	i;

	i = 0;
	(*data)->z_col = (int **)malloc(sizeof(int *) * ((*data)->height + 1));
	if (!(*data)->z_col)
		return ;
	fd = open(file, O_RDONLY, 0);
	while (i < (*data)->height)
	{
		(*data)->z_col[i] = fill_col(get_next_line(fd));
		i++;
	}
	(*data)->z_col[i] = NULL;
	close(fd);
}
