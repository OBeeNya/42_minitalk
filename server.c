/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:41 by baubigna          #+#    #+#             */
/*   Updated: 2022/01/18 17:47:40 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum)
{
	static t_char	letter = {0, 128};

	if (signum == SIGUSR2)
		letter.l += letter.pow;
	letter.pow /= 2;
	if (letter.pow < 1)
	{
		if (letter.l == 0)
			ft_printf("\n");
		write(1, &letter.l, 1);
		letter.pow = 128;
		letter.l = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", (int)getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
	}
	return (0);
}
