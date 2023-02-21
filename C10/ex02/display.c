/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 06:53:36 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/09 12:57:09 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_lim(int fd)
{
	int		len;
	char	*lim;
	char	reader[256];

	lim = malloc(sizeof(char));
	if (!lim)
		return (NULL);
	lim[0] = 0;
	len = 1;
	while (len > 0)
	{
		len = read(fd, reader, 256);
		if (len > 0)
			lim = ft_strncat_mall(lim, reader, len);
	}
	return (lim);
}

void	ft_tail(int count, int fd)
{
	char	*lim;

	lim = ft_lim(fd);
	if (count > ft_strlen(lim))
		count = ft_strlen(lim);
	while (lim[ft_strlen(lim) - count])
		write(1, &lim[ft_strlen(lim) - count--], 1);
}

void	header_print(char *filename, int nb, int firstFile, int idx)
{
	if (idx != firstFile)
		write(1, "\n", 1);
	if (firstFile + 1 < nb)
	{
		write(1, "==> ", 4);
		ft_putstr(filename, 1);
		write(1, " <==\n", 5);
	}
}
