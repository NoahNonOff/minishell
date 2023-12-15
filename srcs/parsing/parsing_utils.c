#include "minishell.h"

char	modified_edge(char edge, char c)
{
	if (edge == c)
		return (' ');
	return (c);
}

void	free_red(t_red *red)
{
	m_freeTab(red->input1);
	m_freeTab(red->input2);
	m_freeTab(red->output1);
	m_freeTab(red->output2);
	free(red);
}

void	t_varInit(t_var *var)
{
	var->idx = 0;
	var->edge = ' ';
	m_bzero(&var->new_token[0], TOKEN_MAX_SZ);
}