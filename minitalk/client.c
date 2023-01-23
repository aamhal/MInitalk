/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:01:57 by aamhal            #+#    #+#             */
/*   Updated: 2023/01/20 16:35:16 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char c)
{
	int	j;
	int	d;

	d = 1;
	j = 7;
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
	while (av[2][i])
	{
		ft_send(pid, av[2][i]);
		i++;
	}
	ft_send(pid, 0);
	return (0);
}
