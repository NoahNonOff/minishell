/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:54:04 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/07 16:37:12 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_strlen(char *str);
void	ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);
void	ft_except(char *filename, char *binary_name);
void	write_file(int fd);

#endif
