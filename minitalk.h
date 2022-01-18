/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:57:51 by baubigna          #+#    #+#             */
/*   Updated: 2022/01/18 16:03:29 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_char
{
	char	l;
	int		pow;
}				t_char;

int		is_conv(const char c);
int		treat_unsint(unsigned int u);
int		treat_hexa(unsigned int h, int i);
int		treat_char(int c);
int		ft_printf(const char *s, ...);
int		treat_str(char *s);
int		treat_int(int n);
int		treat_ptr(unsigned long l);
int		treat_args(va_list args, const char c);
int		nb_len(int n);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		*convert_binary(int n);
void	reverse_tab(int *b);

#endif