/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:53:08 by namohamm          #+#    #+#             */
/*   Updated: 2022/03/18 15:49:35 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "ft_mini.h"

// int b;

static void ft_decode_your_future(int sig, siginfo_t *info, void *ptr)
{
	static char c;
	static int b;
	(void) ptr;
	if (sig == SIGUSR1)
		c |= 1;
	if (sig == SIGUSR2)
		c |= 0;
	b++;
	if (b == 8)
	{
		write(1, &c, 1);
		b = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	c <<= 1;
}

int main()
{
	struct sigaction sa;

	// b = 0;
	sa.sa_sigaction = &ft_decode_your_future;
	sa.sa_flags = SA_SIGINFO;
	printf("pid = %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	
	while (1)
		pause();
}
