#ifndef UTILS_H
# define UTILS_H

/* ==================== include ==================== */

# include <stdlib.h> /* allocation */
# include <unistd.h> /* input - output */

/* ===================== proto ===================== */

// utils 1
void	*m_freeTab(char **tab);
int		m_strlen(const char *s);
char	*m_strdup(const char *s);
void	m_putstr(const char *str, int fd);
char	**m_duplicateTab(const char **tab);

// utils 2
int		m_isWhitespace(char c);
char	**m_endtabPush(const char **tab, const char *to_add);

#endif
