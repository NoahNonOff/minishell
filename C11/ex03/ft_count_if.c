/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:07:48 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/04 17:07:49 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (i < length)
		if ((*f)(tab[i++]) != 0)
			res++;
	return (res);
}
