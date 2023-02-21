/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:39:46 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/30 19:24:30 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*new_memory;
	int		i;

	i = -1;
	new_memory = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new_memory)
		return (NULL);
	while (src[++i])
		new_memory[i] = src[i];
	new_memory[i] = 0;
	return (new_memory);
}
