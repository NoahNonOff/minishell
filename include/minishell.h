/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <nbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:16:47 by abougy            #+#    #+#             */
/*   Updated: 2023/12/08 16:17:39 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ==================== include ==================== */
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <fcntl.h>

# include "utils.h"

/* ===================== macros ==================== */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# ifndef _BOOL_
#  define _BOOL_

#  define bool int
#  define true 1
#  define false 0

# endif

/* ===================== struct ==================== */

typedef struct s_redirection
{
	char	**input1; // 1
	char	**input2; // 2
	char	**output1; // 3
	char	**output2; // 4
}	t_red;

typedef struct s_parse
{
	/* 0 -> none | 1 -> first | 2 -> middle | 3 -> last */
	int				pipe_type;
	int				list_size;
	t_red			*red;
	char			**cmds;
	struct s_parse	*next;
}	t_parse;

typedef struct s_shell
{
	char	*prompt;
	char	**env;
}	t_shell;

/* ===================== proto ===================== */

#endif
