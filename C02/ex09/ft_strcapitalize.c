/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:35:14 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/21 15:39:26 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	alpha(char c);
int	is_lower_case(char c);
int	is_upper_case(char c);
int	is_number(char c);

int	is_lower_case(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	is_upper_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (is_upper_case(str[i]))
			str[i] += 32;
	}
	if (is_lower_case(str[0]))
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (!is_number(str[i - 1]) && !alpha(str[i -1]))
			if (is_lower_case(str[i]))
				str[i] -= 32;
		i++;
	}
	return (str);
}

int	alpha(char c)
{
	if (is_upper_case(c) || is_lower_case(c))
		return (1);
	else
		return (0);
}
