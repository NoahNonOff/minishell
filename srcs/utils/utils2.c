#include "utils.h"

int	m_isWhitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

void	m_bzero(void *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = 0;
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

int	m_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (i < n && s1[i] != s2[i])
		return (1);
	if (s1[i])
		return (1);
	return (0);
}