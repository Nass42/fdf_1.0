/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:40:54 by aalmazro          #+#    #+#             */
/*   Updated: 2022/03/12 11:52:29 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char *str)
{
	int		bits;
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		bits = 7;
		while (bits >= 0)
		{
			if ((c & (1 << bits)) != 0)
				kill(pid, SIGUSR1);
			else if ((c & (0 << bits)) == 0)
				kill(pid, SIGUSR2);
			bits--;
			usleep(100000); // microsecond
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	pid = ft_atoi(argv[1]);
	send_bits(pid, argv[2]);
	if (argc != 3)
		return (0);
}
