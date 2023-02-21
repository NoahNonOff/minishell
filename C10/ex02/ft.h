/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 05:48:06 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/09 12:59:08 by nbeaufil         ###   ########.fr       */
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
# include <stdlib.h>

void	header_print(char *filename, int nb, int firstFile, int idx);
int		ft_atoi(char *str);
void	ft_except(char *filename, char *binary_name);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int fd);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strncat_mall(char *dest, char *src, int n);
void	ft_tail(int count, int fd);

typedef struct s_arg{
	int	first_file_idx;
	int	given_val;
	int	readf_stdin;
}t_arg;

#endif
