/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:41:49 by namohamm          #+#    #+#             */
/*   Updated: 2022/04/22 17:01:18 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i++])
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
	return (count);
}

void	ft_get_height(char *str, fdf **data)
{
	int	fd;
	int	height;

	height = 0;
	fd = open(str, O_RDONLY, 0);
	while (get_next_line(fd))
		height++;
	close(fd);
	(*data)->height = height;
	//return (height);
}

void	ft_get_width(char *str, fdf **data)
{
	int	width;
	int	fd;

	fd = open(str, O_RDONLY, 0);
	(*data)->width = ft_count_word(get_next_line(fd), ' ');
	close(fd);
	//return (width);
}

int	*fill_matrix(char *line)
{
	char	**str;
	int		*z_line;
	int		i;
	int		len;

	i = 0;
	len = ft_count_word(line, ' ');
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

/*----------------------------------------------------*/ 
/*----------------------------------------------------*/
// int	*fill_col_matrix(char *line)
// {
// 	char	**str;
// 	char	*z_col_line;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = ft_count_word(line, ' ');
// 	z_col_line = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!z_col_line)
// 		return (NULL);
// 	str = ft_split(line, ' ');
// 	while (str[i])
// 	{
// 		z_line[i] = ft_atoi(str[i]);
		

// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// 	return (z_line);
// }
/*----------------------------------------------------*/ 
/*----------------------------------------------------*/ 

void	ft_read_file(char *file, fdf **data)
{
	int fd;
	int i;
	i = 0;
	
	(*data)->z_matrix = (int **)malloc(sizeof(int *) * ((*data)->height + 1));
	if (!(*data)->z_matrix)
		return ;
	fd = open(file, O_RDONLY, 0);
	while (i < (*data)->height)
	{
		(*data)->z_matrix[i] = fill_matrix(get_next_line(fd));
		i++;
	}
	(*data)->z_matrix[i] = NULL;
	close(fd);
	//printf("%d\n", data->z_matrix[3][6]);
}

/*-----------------------------------------------------------------------*/ 
/*-----------------------------------------------------------------------*/
// int ft_strhex_int(char *str)
// {
// 	int nbr;
	
// 	nbr = 0;
// 	while (*str != 'x' && *str != 'X')
// 		str++;
// 	while (*(++str))
// 	{
// 		if (*str >= '0' && *str <= '9')
// 			nbr = 16 * nbr + *str - '0';
// 		else if (*str >= 'a' && *str <= 'f')
// 			nbr = 16 * nbr + *str - 'a' + 10;
// 		else if (*str >= 'A' && *str <= 'A')
// 			nbr = 16 * nbr + *str - 'a' + 10;
// 	}
// 	printf("nbr = %d\n", nbr);
// 	fflush(stdout);
// 	return(nbr);
// }
int ft_strhex_int(char *str)
{
	int nbr;
	int i;
	
	nbr = 0;
	i = 0;
	int len = ft_strlen(str);
	while (str[i] && str[i] != 'x')
		i++;
	if (str[i] != 'x')
		return (nbr);
	i++;
	//printf("i = %d\n", i);
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
	printf("nbr = %x\n", nbr);
	fflush(stdout);
	return(nbr);
}
/*-----------------------------------------------------------------------*/ 
/*-----------------------------------------------------------------------*/ 
int	*fill_col(char *line)
{
	char	**str;
	int		*z_line;
	int		i;
	int		len;

	i = 0;
	len = ft_count_word(line, ' ');
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

/*-----------------------------------------------------------------------*/ 
/*-----------------------------------------------------------------------*/ 

void	ft_read_col(char *file, fdf **data)
{
	int fd;
	int i;
	i = 0;

	/*-----------------------------------------------------------------------*/ 
	(*data)->z_col = (int **)malloc(sizeof(int *) * ((*data)->height + 1));
	if (!(*data)->z_col)
		return ;
	/*-----------------------------------------------------------------------*/
	fd = open(file, O_RDONLY, 0);
	while (i < (*data)->height)
	{
	/*-----------------------------------------------------------------------*/
		(*data)->z_col [i]= fill_col(get_next_line(fd));
	/*-----------------------------------------------------------------------*/ 
		i++;
	}
	(*data)->z_col[i] = NULL;
	close(fd);
	// printf("%x\n", (*data)->z_col[2][2]);
	// // fflush(stdout);
}

