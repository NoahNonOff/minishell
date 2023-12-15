#include "utils.h"

static int	m_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

char	**m_endtabPush(char **tab, const char *to_add)
{
	int		len;
	char	**ret;

	len = 0;
	if (!to_add || !m_strlen(to_add))
		return (tab);
	ret = malloc(sizeof(char *) * (m_tablen(tab) + 2));
	if (!ret)
		return (NULL);
	while (tab && tab[len])
	{
		ret[len] = (char *)tab[len];
		if (!ret[len++])
			return (m_freeTab(ret));
	}
	ret[len] = m_strdup(to_add);
	if (!ret[len++])
		return (m_freeTab(ret));
	ret[len] = NULL;
	if (tab)
		free(tab);
	return (ret);
}