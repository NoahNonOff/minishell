/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:54:25 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/23 09:54:27 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	o;

	i = 0;
	o = 0;
	while (dest[i] != '\0')
		i++;
	while (src[o] && nb > 0)
	{
		dest[i + o] = src[o];
		o++;
		nb--;
	}
	dest[i + o] = '\0';
	return (dest);
}
