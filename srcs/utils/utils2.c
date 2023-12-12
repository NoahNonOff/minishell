#include "utils.h"

int	m_isWhitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

char	**m_endtabPush(char **tab, const char *to_add)
{
	int		len;
	char	**ret;

	len = 0;
	if (!to_add)
		return (NULL);
	ret = malloc(sizeof(char *) * (m_strlen(to_add) + 2));
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

char	*m_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = -1;
	if (!dest || !src)
		return (NULL);
	while (++i < n && src[i])
		dest[i] = src[i];
	dest[n] = 0;
	return (dest);
}