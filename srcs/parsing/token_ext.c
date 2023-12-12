#include "minishell.h"

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