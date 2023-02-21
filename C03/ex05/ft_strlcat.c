/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:53:16 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/24 14:21:35 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_dest;
	unsigned int	size_src;

	size_dest = 0;
	size_src = 0;
	while (dest[size_dest] && size_dest < size)
		size_dest++;
	while (src[size_src] && size && size_dest + size_src < size -1)
	{
		dest[size_dest + size_src] = src[size_src];
		size_src++;
	}
	if (size_dest < size)
		dest[size_dest + size_src] = '\0';
	size_src = 0;
	while (src[size_src])
		size_src++;
	return (size_dest + size_src);
}
