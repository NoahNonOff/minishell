/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:54:20 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/31 10:54:21 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	bound;
	int	*buffer;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	bound = max - min;
	buffer = malloc(sizeof(int) * bound);
	if (!buffer)
	{
		*range = 0;
		return (-1);
	}
	*range = buffer;
	i = 0;
	while (i < bound)
	{
		buffer[i] = min + i;
		i++;
	}
	return (i);
}
