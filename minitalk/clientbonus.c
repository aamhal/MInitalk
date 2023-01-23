/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientbonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:35:44 by aamhal            #+#    #+#             */
/*   Updated: 2023/01/19 23:35:59 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"

void	ft_send(int pid, char c)
{
	int	j;
	int	d;

	d = 1;
	j = 8;
	while (j--)
	{
		if (c & d)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		d = d << 1;
	}
}

void	hundler(int signal)
{
	if (signal == SIGUSR2)
		ft_putstr_fd("message recived\n", 1);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr_fd("this function take only two parameters!!\n", 1);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("wrong id !!\n", 1);
		return (1);
	}
	signal(SIGUSR2, hundler);
	while (av[2][i])
	{
		ft_send(pid, av[2][i]);
		i++;
	}
	ft_send(pid, 0);
	return (0);
}
