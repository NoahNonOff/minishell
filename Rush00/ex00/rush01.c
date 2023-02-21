/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:22:41 by amoutill          #+#    #+#             */
/*   Updated: 2023/01/22 15:31:36 by nbeaufil         ###   ########.fr       */
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
			if ((j == 0 && i == 0) || (j == x - 1 && i == y - 1))
				ft_putchar('/');
			else if ((j == x - 1 && i == 0) || (j == 0 && i == y - 1))
				ft_putchar('\\');
			else
				ft_putchar('*');
		}
		else
		{
			if (j == 0 || (j == x - 1))
				ft_putchar('*');
			else
				ft_putchar(' ');
		}
		j++;
	}
}
