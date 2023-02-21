/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:34:10 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/22 15:34:29 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush_write_line(int x, int y, int i, int j);

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	j = 0;
	while (i < y)
	{
		rush_write_line(x, y, i, j);
		i++;
		ft_putchar('\n');
		j = 0;
	}
}

void	rush_write_line(int x, int y, int i, int j)
{
	while (j < x)
	{
		if (i == 0 || (i == y - 1))
		{
			if (j == 0)
				ft_putchar('A');
			else if (j == x - 1)
				ft_putchar('C');
			else
				ft_putchar('B');
		}
		else
		{
			if (j == 0 || (j == x - 1))
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		j++;
	}
}
