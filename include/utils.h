#ifndef UTILS_H
# define UTILS_H

/* ==================== include ==================== */

# include <stdlib.h> /* allocation */
# include <unistd.h> /* input - output */

/* ===================== proto ===================== */

// utils 1
void	m_putstr(const char *str, int fd);
int		m_strlen(const char *s);
char	**m_duplicateTab(const char **tab);
void	*m_freeTab(char **tab);
char	*m_strdup(const char *s);

// utils 2
int		m_isWhitespace(char c);
char	**m_endtabPush(const char **tab, const char *to_add);

#endif
