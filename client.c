/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:32:00 by baubigna          #+#    #+#             */
/*   Updated: 2022/01/18 17:43:58 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_digit(char *av)
{
	while (*av)
	{
		if (*av < 48 || *av > 57)
			return (0);
		av++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Please give 2 arguments\n");
		return (0);
	}
	if (ft_atoi(av[1]) < 1 || !is_digit(av[1]) || ft_atoi(av[1]) > 99999)
	{
		ft_printf("Please give valid PID\n");
		return (0);
	}
	return (1);
}

void	print_nl(char **av)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill((pid_t)ft_atoi(av[1]), SIGUSR1);
		usleep(40);
		i++;
	}
}

void	send_signals(char **av)
{
	int	i;
	int	l;
	int	*b;

	l = 0;
	while (l < ft_strlen(av[2]))
	{
		b = convert_binary(av[2][l]);
		reverse_tab(b);
		i = 0;
		while (i < 8)
		{
			if (b[i] == 0)
				kill((pid_t)ft_atoi(av[1]), SIGUSR1);
			else
				kill((pid_t)ft_atoi(av[1]), SIGUSR2);
			usleep(40);
			i++;
		}
		l++;
	}
	free(b);
}

int	main(int ac, char **av)
{
	if (!check_args(ac, av))
		return (0);
	send_signals(av);
	print_nl(av);
	return (0);
}
