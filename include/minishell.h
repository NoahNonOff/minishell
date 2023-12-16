#ifndef MINISHELL_H
# define MINISHELL_H

/* ==================== include ==================== */
# include <readline/readline.h> /* readline() */
# include <readline/history.h>
# include <stdio.h> /* debug printf */
# include <stdbool.h> /* bool */
# include <signal.h> /* signal() */

# include "utils.h"

/* ===================== macros ==================== */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# define TOKEN_MAX_SZ 508
# define PROMPT_MAX_SZ 1016


/* ===================== struct ==================== */

typedef struct s_var
{
	int		idx;
	char	edge;
	char	new_token[TOKEN_MAX_SZ];
}	t_var;

// Executable struct
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
	int		ret_value;
	t_parse	*begin_list; // to free in child proc
}	t_shell;

/* ===================== proto ===================== */

// main.c
void		free_shell(t_shell *data);

// parsing_utils.c
char		modified_edge(char edge, char c);
void		free_red(t_red *red);
void		t_varInit(t_var *var);

// linked_list.c
void		*free_list(t_parse *ptr, int option);
t_parse		*add_parse(t_parse *begin, t_red *red, char **cmd);
void		assign_pipe_type(t_parse *parse);

#endif
