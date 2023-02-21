/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:05:01 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/25 12:14:48 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	fac;
	int	n;

	if (nb < 0)
		return (0);
	fac = 1;
	n = 2;
	while (n <= nb)
		fac = fac * n++;
	return (fac);
}
