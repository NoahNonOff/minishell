/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 07:32:13 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/02 09:02:13 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);
int		count_size_of_str(int size, char **strs, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		total;

	total = count_size_of_str(size, strs, sep);
	result = malloc(sizeof(char) * (total));
	if (!result)
		return (NULL);
	result[0] = 0;
	if (size <= 0)
		return (result);
	i = -1;
	while (++i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
	}
	result[ft_strlen(result)] = 0;
	return (result);
}

int	count_size_of_str(int size, char **strs, char *sep)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	if (size == 0)
		return (1);
	while (i < size)
		total += ft_strlen(strs[i++]);
	total += ft_strlen(sep) * (size - 1);
	return (total + 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	destlen;

	i = 0;
	destlen = ft_strlen(dest);
	while (src[i])
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = 0;
	return (dest);
}
