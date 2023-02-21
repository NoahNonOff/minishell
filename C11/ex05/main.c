/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:22:38 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/07 10:57:35 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	res;

	if (argc != 4)
		return (-1);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (ft_operat(a, b, argv, &res) == -1)
		return (-1);
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}

int	check_zero(int b, char **argv)
{
	if (ft_strcmp(argv[2], "/") == 0 && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (ft_strcmp(argv[2], "%") == 0 && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	ft_operat(int a, int b, char **argv, int *res)
{
	if (!check_zero(b, argv))
		return (-1);
	if (ft_strcmp(argv[2], "+") == 0)
		*res = add(a, b);
	else if (ft_strcmp(argv[2], "-") == 0)
		*res = subtract(a, b);
	else if (ft_strcmp(argv[2], "/") == 0)
		*res = divide(a, b);
	else if (ft_strcmp(argv[2], "%") == 0)
		*res = modulo(a, b);
	else if (ft_strcmp(argv[2], "*") == 0)
		*res = mult(a, b);
	else
		*res = 0;
	return (1);
}
