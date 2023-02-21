/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:16:18 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/24 21:16:43 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_val(char c, int val);
int	white_space_finder(char c);

int	ft_atoi(char *str)
{
	int	i;
	int	val_neg;
	int	n;

	i = 0;
	val_neg = 0;
	n = 0;
	while (white_space_finder(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			val_neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10;
		n += str[i] - '0';
		i++;
	}
	if (val_neg % 2 != 0)
		n = 0 - n;
	return (n);
}

int	white_space_finder(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\v')
		return (1);
	return (0);
}
