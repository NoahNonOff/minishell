/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:44:33 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/21 10:44:47 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = -1;
	if (str[0] == 0)
	{
		return (1);
	}
	while (str[++i])
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			return (0);
		}
	}
	return (1);
}