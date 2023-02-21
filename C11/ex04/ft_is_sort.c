/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:10:22 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/06 15:40:03 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	croiss;
	int	decroiss;

	i = 1;
	croiss = 1;
	decroiss = 1;
	if (length <= 1)
		return (1);
	while (i < length)
	{
		if ((*f)(tab[i - 1], tab[i]) < 0)
			decroiss = 0;
		i++;
	}
	i = 1;
	while (i < length)
	{
		if ((*f)(tab[i - 1], tab[i]) > 0)
			croiss = 0;
		i++;
	}
	if (croiss || decroiss)
		return (1);
	return (0);
}
