/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operateur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:24:49 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/07 10:49:08 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	add(int a, int b)
{
	int	res;

	res = a + b;
	return (res);
}

int	subtract(int a, int b)
{
	int	res;

	res = a - b;
	return (res);
}

int	divide(int a, int b)
{
	int	res;

	res = a / b;
	return (res);
}

int	mult(int a, int b)
{
	int	res;

	res = a * b;
	return (res);
}

int	modulo(int a, int b)
{
	int	res;

	res = a % b;
	return (res);
}
