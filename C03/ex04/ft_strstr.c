/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:31:42 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/24 13:44:42 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	o;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			o = 0;
			while (to_find[o] && (str[i + o] == to_find[o]))
				o++;
			if (to_find[o] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
