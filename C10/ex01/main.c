/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:09:50 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/07 16:43:31 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int	fd;
	int	nb_file;

	if (argc == 1)
		write_file(0);
	nb_file = 1;
	while (nb_file < argc)
	{
		if ((argv[nb_file][0] == '-') || (argv[nb_file][0] == '-'
					&& argv[nb_file][1] == '-'))
			write_file(0);
		else
		{
			fd = open(argv[nb_file], O_RDONLY);
			if (fd < 0)
			{
				ft_except(argv[nb_file], argv[0]);
				close(fd);
			}
			else
				write_file(fd);
		}
		nb_file++;
	}
}
