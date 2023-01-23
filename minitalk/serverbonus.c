/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverbonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:46:22 by aamhal            #+#    #+#             */
/*   Updated: 2023/01/22 16:29:39 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"

void	ft_settozer(char *c, int *i)
{
	*c = 0;
	*i = 0;
}

void	handler(int signal, siginfo_t *info, void *p)
{
	static int	i;
	static int	cpid;
	static char	c;
	int			d;

	(void)p;
	if (cpid != info->si_pid)
	{
		cpid = info->si_pid;
		ft_settozer(&c, &i);
	}
	if (signal == SIGUSR1)
		d = 1;
	else
		d = 0;
	c += (d << i);
	i++;
	if (i == 8)
	{
		if (!c)
			kill(cpid, SIGUSR2);
		write(1, &c, 1);
		ft_settozer(&c, &i);
	}	
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
