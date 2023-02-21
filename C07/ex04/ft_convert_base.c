/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:26:59 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/02 09:04:01 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	verif_base(char *base);
int	ft_strlen(char *str);
int	ft_atoi_base(char *str, char *base);

char	*ft_zero(char *base_to)
{
	char	*ret;

	ret = malloc(2 * sizeof(char));
	ret[0] = base_to[0];
	ret[1] = 0;
	return (ret);
}

void	ft_reverse_tab(char *tab, int size)
{
	char	tmp;
	int		i;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
}	

void	*ft_strdup(char *src)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int			i;
	long int	nb;
	char		ret[33];
	char		*result;
	int			sign;

	i = 0;
	sign = 1;
	nb = (long int)nbr;
	if (nb < 0)
	{
		sign = -1;
		nb = -nb;
	}
	while (nb)
	{
		ret[i++] = base[nb % ft_strlen(base)];
		nb = nb / ft_strlen(base);
	}
	if (sign == -1)
		ret[i++] = '-';
	ret[i] = 0;
	ft_reverse_tab(ret, ft_strlen(ret));
	result = ft_strdup(ret);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		val_b10;

	if (!verif_base(base_from) || !verif_base(base_to))
		return (NULL);
	val_b10 = ft_atoi_base(nbr, base_from);
	if (val_b10 == 0)
		return (ft_zero(base_to));
	res = (char *)malloc(ft_strlen(ft_itoa_base(val_b10, base_to))
			* sizeof(char));
	if (!res)
		return (NULL);
	res = ft_itoa_base(val_b10, base_to);
	return (res);
}
