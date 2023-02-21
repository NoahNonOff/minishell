/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:27:29 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/24 11:20:16 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (dest[i] != '\0')
		i++;
	while (src[o] != '\0')
	{
		dest[i + o] = src[o];
		o++;
	}
	dest[i + o] = '\0';
	return (dest);
}
