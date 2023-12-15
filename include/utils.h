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
char	**m_duplicateTab(char **tab);

// utils 2
int		m_isWhitespace(char c);
void	m_bzero(void *s, int n);
char	*m_strncpy(char *dest, char *src, int n);
int		m_strncmp(const char *s1, const char *s2, int n);

// utils 3
char	*m_itoa(int n);
char	**m_split(char const *s, char c);

// utils 4
int		m_tablen(char **tab);
char	**m_endtabPush(char **tab, const char *to_add);

#endif
