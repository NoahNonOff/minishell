/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:18 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/07 15:32:10 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_error(int nb_arg, char *file)
{
	int	op_file;

	op_file = open(file, O_RDONLY);
	if (nb_arg < 2)
	{
		ft_putstr("File name missing.\n", 2);
		return (0);
	}
	if (nb_arg > 2)
	{
		ft_putstr("Too many arguments.\n", 2);
		return (0);
	}
	if (op_file == -1)
	{
		ft_putstr("Cannot read file.\n", 2);
		return (0);
	}
	close(op_file);
	return (1);
}

int	main(int argc, char **argv)
{
	int		len;
	int		op;
	char	buffer[256];

	if (!check_error(argc, argv[1]))
		return (0);
	len = 1;
	op = open(argv[1], O_RDONLY);
	while (len > 0)
	{
		len = read(op, buffer, 256);
		write(1, buffer, len);
	}
	close(op);
	return (0);
}
