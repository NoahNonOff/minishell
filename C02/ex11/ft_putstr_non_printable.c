/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:37:44 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/08 12:37:46 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_printable(char c);
void	ft_put_hex(char n);

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_str_is_printable(str[i]))
			write(1, &str[i], 1);
		else
			ft_put_hex(str[i]);
		i++;
	}
}

int	ft_str_is_printable(char c)
{
	if (c < ' ' || c == 127)
		return (0);
	return (1);
}

void	ft_put_hex(char n)
{
	char			*base;
	unsigned char	c;

	c = (unsigned char)n;
	base = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}
