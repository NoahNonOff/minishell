/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:08:51 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/02/09 13:01:47 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_arg	arg_config(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_arg	conf;
	int		fd;
	int		ifile;

	conf = arg_config(argc, argv);
	ifile = conf.first_file_idx;
	if (conf.readf_stdin)
		ft_tail(conf.given_val, 0);
	while (ifile < argc && ifile != -1)
	{
		fd = open(argv[ifile], O_RDONLY);
		if (fd < 0)
		{
			ft_except(argv[ifile], argv[0]);
			close(fd);
			conf.first_file_idx++;
		}
		else
		{
			header_print(argv[ifile], argc, conf.first_file_idx, ifile);
			ft_tail(conf.given_val, fd);
		}
		ifile++;
	}
	return (0);
}

t_arg	arg_config(int argc, char **argv)
{
	t_arg	conf;

	conf.first_file_idx = -1;
	conf.given_val = 0;
	conf.readf_stdin = 0;
	if (argc < 3 || (ft_strcmp(argv[1], "-c") == 0 && argc < 4))
	{
		conf.readf_stdin = 1;
		if (argc == 2)
			conf.given_val = ft_atoi(argv[1] + 2);
		else
			conf.given_val = ft_atoi(argv[2]);
		return (conf);
	}
	if (ft_strcmp(argv[1], "-c") == 0)
	{
		conf.first_file_idx = 3;
		conf.given_val = ft_atoi(argv[2]);
	}
	else
	{
		conf.first_file_idx = 2;
		conf.given_val = ft_atoi(argv[1] + 2);
	}
	return (conf);
}
