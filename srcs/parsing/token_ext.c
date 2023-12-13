#include "minishell.h"

char	modified_edge(char edge, char c);
/* ----------------------------------------- */

char	*find_var(char **env, char *token, int len)
{
	int		i;
	char	*ret;
	char	**split_env;

	i = -1;
	ret = NULL;
	while (!ret && env && env[++i])
	{
		split_env = m_split(env[i], '=');
		if (!split_env)
			return (NULL);
		if (!m_strncmp(split_env[0], token, len))
			ret = m_strdup(split_env[1]);
		m_freeTab(split_env);
	}
	return (ret);
}

int	get_red(t_red *red, char *token)
{
	(void)red;
	(void)token;
	return (1);
}

// remove the redirection and the quotes
char	*manage_red(t_red *red, char *token)
{
	int		i;
	int		idx;
	char	edge;
	char	new_token[TOKEN_MAX_SZ];

	i = -1;
	idx = 0;
	edge = ' ';
	m_bzero(&new_token[0], TOKEN_MAX_SZ);
	while (token[++i] && idx < TOKEN_MAX_SZ)
	{
		if (token[i] == '\"' || token[i] == '\'')
			edge = modified_edge(edge, token[i]);
		if ((token[i] == '>' || token[i] == '<') && edge == ' ')
			i += get_red(red, &token[i]);
		else if (edge != ' ')
			new_token[idx++] = token[i];
	}
	return (m_strdup(new_token));
}