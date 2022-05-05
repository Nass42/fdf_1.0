/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:53:08 by namohamm          #+#    #+#             */
/*   Updated: 2022/03/19 01:44:34 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd('8', fd);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-nb, fd);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
		}
		ft_putchar_fd(48 + nb % 10, fd);
	}
}

static void	ft_decoding(int sig, siginfo_t *info, void *ptr)
{
	static char	c;
	static int	b;

	(void) ptr;
	(void) info;
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
	}
	c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &ft_decoding;
	sa.sa_flags = SA_SIGINFO;
	write(1, "PID: ", 6);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
