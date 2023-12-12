#include "minishell.h"

typedef struct s_var
{
	int		idx;
	char	edge;
	char	new_token[TOKEN_MAX_SZ];
}	t_var;

char	*manage_var(t_shell *data, char	*token);
char	*find_var(char **env, char *token, int len);
/* ----------------------------------------- */

static char	modified_edge(char edge, char c)
{
	if (edge == c)
		return (' ');
	return (c);
}

char	*extract_token(char *prompt, int *pos)
{
	char	c;
	int		len;
	char	edge;
	char	*token;

	len = 0;
	edge = ' ';
	token = NULL;
	while (prompt && prompt[(*pos) + len])
	{
		c = prompt[(*pos) + len];
		if (edge == ' ' && (c == ' ' || c == '|'))
			break ;
		else if (c == '\"' || c == '\'')
			edge = modified_edge(edge, c);
		len++;
	}
	token = malloc(sizeof(char) * (len + 1));
	if (!token)
		return (NULL);
	token = m_strncpy(token, &prompt[*pos], len);
	(*pos) += len;
	return (token);
}

bool	modified_token(t_shell *data, char **token, t_red **red)
{
	char	*str;

	(void)red;
	str = manage_var(data, *token);
	free(*token);
	if (!str)
		return (false);
	// modified for remove red (< | >)
	*token = str;
	return (true);
}

static int	get_var_name(t_shell *data, t_var *var, char *token)
{
	int		len;
	char	*replace;

	len = 0;
	if (token[1] != '?')
		while ((token && token[++len]))
			if (token[len] == ' ' || token[len] == '\'' || token[len] == '\"')
				break ;
	if (len == 0 && token[1] == '?')
	{
		replace = m_itoa(data->ret_value);
		len = 2;
	}
	else
		replace = find_var(data->env, &token[1], len);
	if (!replace)
		return (len - 1);
	m_strncpy(&var->new_token[var->idx], replace, m_strlen(replace));
	var->idx += m_strlen(replace);
	free(replace);
	return (len - 1);
}

char	*manage_var(t_shell *data, char	*token)
{
	int		i;
	t_var	var;

	m_bzero(&var, sizeof(t_var));
	var.edge = ' ';
	i = -1;
	while (token[++i] && var.idx < TOKEN_MAX_SZ)
	{
		if (token[i] == '\"' || token[i] == '\'')
			var.edge = modified_edge(var.edge, token[i]);
		if (token[i] == '$' && var.edge != '\'' && token[i + 1])
			i += get_var_name(data, &var, &token[i]);
		else
			var.new_token[var.idx++] = token[i];
	}
	return (m_strdup(var.new_token));
}