/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:43:57 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/07 16:43:58 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	write_file(int fd)
{
	int		len;
	char	buff[256];

	len = 1;
	while (len > 0)
	{
		len = read(fd, buff, 256);
		write(1, buff, len);
	}
	close(fd);
}

void	ft_except(char *filename, char *binary_name)
{
	write(2, basename(binary_name), ft_strlen(basename(binary_name)));
	write(2, ": ", 2);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	ft_putstr(strerror(errno), 2);
	write(2, "\n", 1);
}
