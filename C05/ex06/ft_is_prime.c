/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:21:21 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/25 20:31:40 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	test;
	int	i;

	test = 0;
	if (nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		test = 1;
	else
	{
		i = 3;
		while (i < nb)
		{
			if (nb % i == 0)
				test = 1;
			i++;
		}
	}
	if (!test)
		return (1);
	else
		return (0);
}
