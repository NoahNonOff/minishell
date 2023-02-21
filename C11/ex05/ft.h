/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:21:27 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/07 10:48:32 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		add(int a, int b);
int		subtract(int a, int b);
int		divide(int a, int b);
int		mult(int a, int b);
int		modulo(int a, int b);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
int		check_zero(int b, char **argv);
int		ft_operat(int a, int b, char **argv, int *res);
int		ft_strcmp(char *s1, char *s2);

#endif
