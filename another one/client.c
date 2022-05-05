/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:52:54 by namohamm          #+#    #+#             */
/*   Updated: 2022/03/18 16:00:41 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "ft_mini.h"

void handle_sig(int sig)
{
	(void) sig;
	printf("okay\n");
}

void	ft_coding(int pid, char *str)
{
	int	i;
	int	b;

	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	i = 0;
	while (str[i])
	{
		b = 7;
		while (b >= 0)
		{
			if ((str[i] & (1 << b)) > 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			b--;
			usleep(100);
		}
		i++;
	}
}

int main(int ac, char *av[])
{
	int pid = ft_atoi(av[1]);
	ft_coding(pid, av[2]);
}
