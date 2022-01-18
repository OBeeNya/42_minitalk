/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:54:58 by baubigna          #+#    #+#             */
/*   Updated: 2022/01/17 16:05:32 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*convert_binary(int n)
{
	int	*b;
	int	i;

	i = 0;
	b = malloc(sizeof(int) * 8);
	while (i < 8)
		b[i++] = 0;
	i = 0;
	while (n > 0)
	{
		b[i] = n % 2;
		i++;
		n /= 2;
	}
	return (b);
}
