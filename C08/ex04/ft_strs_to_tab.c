/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:26:24 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/01/30 17:51:47 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *av);
int		ft_strlen(char *av);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*tab;

	tab = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

int	ft_strlen(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

char	*ft_strdup(char *av)
{
	char	*cp;
	int		i;

	i = 0;
	cp = malloc((ft_strlen(av) + 1) * sizeof(char));
	if (!cp)
		return (NULL);
	while (av[i])
	{
		cp[i] = av[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
