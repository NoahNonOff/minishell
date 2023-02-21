/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:57:33 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/22 20:13:36 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	t[5];

	*t = '0';
	t[1] = '1';
	t[2] = '2';
	t[3] = ',';
	t[4] = ' ';
	while (*t < '7')
	{
		if (*t != 7)
		{
			write(1, t, 5);
		}
		if (++t[2] > '9')
		{
			if (++t[1] > '8')
				t[1] = ++(*t) + 1;
			t[2] = t[1] + 1;
		}
	}
	write(1, t, 3);
}