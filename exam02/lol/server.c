/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:41:00 by aalmazro          #+#    #+#             */
/*   Updated: 2022/03/12 11:58:42 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	translate_msg(int sig, siginfo_t *info, void *temp)
{
	static char		c;
	static int		bits;

	info = NULL;
	(void) temp;
	if (sig == SIGUSR1)
		c |= 1; // c or
	if (sig == SIGUSR2)
		c |= 0;
	bits++;
	if (bits == 8)
	{
		ft_putchar_fd(c, 1);
		bits = 0;
		c = 0;
	}
	c = c << 1;
}

int	main(void)
{
	struct sigaction	s;

	s.sa_sigaction = &translate_msg;
	s.sa_flags = SA_SIGINFO; // request info for signal receive
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
		pause();
}
