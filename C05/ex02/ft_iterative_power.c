/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:50 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/25 14:12:53 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	n;
	int	result;

	n = 1;
	if (power == 0 && nb == 0)
		return (1);
	if (power < 0)
		return (0);
	result = nb;
	while (n != power)
	{
		result *= nb;
		n++;
	}
	return (result);
}
