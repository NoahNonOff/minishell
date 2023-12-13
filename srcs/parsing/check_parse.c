#include "minishell.h"

static bool	nothing_after(const char *prompt, int code)
{
	int	i;

	i = 0;
	while (prompt[i] && m_isWhitespace(prompt[i]))
		i++;
	if (code)
	{
		if (!prompt[i] || prompt[i] == '|'
			|| prompt[i] == '<' || prompt[i] == '>')
			return (true);
	}
	else
		if (!prompt[i] || prompt[i] == '|')
			return (true);
	return (false);
}

static bool	check_pipe(const char *prompt, int i)
{
	int	len;

	len = i - 1;
	while (len > -1 && m_isWhitespace(prompt[len]))
		len--;
	if (len == -1 || prompt[len] == '|' || nothing_after(&prompt[i + 1], 0))
	{
		m_putstr("bash: parse error near `|'\n", 2);
		return (false);
	}
	return (true);
}

static bool	check_red(const char *prompt, int *i)
{
	bool	status;

	status = true;
	if (!prompt[(*i) + 1] || prompt[(*i) + 1] == '|'
		|| nothing_after(&prompt[(*i) + 1], 1))
		status = false;
	else if (prompt[(*i) + 1] == '<' || prompt[(*i) + 1] == '>')
	{
		(*i)++;
		if (prompt[(*i)] != prompt[(*i) - 1])
			status = false;
		else if (!prompt[(*i) + 1] || prompt[(*i) + 1] == '|'
			|| prompt[(*i) + 1] == '>' || prompt[(*i) + 1] == '<'
			|| nothing_after(&prompt[(*i) + 1], 1))
			status = false;
	}
	if (!status)
		m_putstr("bash: parse error near `redirection\n", 2);
	return (status);
}

static bool	check_c(const char *prompt, int *i, char *edge)
{
	if (*edge == prompt[*i])
		*edge = 0;
	else if (!*edge && (prompt[*i] == '\'' || prompt[*i] == '\"'))
		*edge = prompt[*i];
	else if (!*edge && prompt[*i] == '|')
		return (check_pipe(prompt, *i));
	else if (!*edge && (prompt[*i] == '>' || prompt[*i] == '<'))
		return (check_red(prompt, i));
	return (true);
}

bool	parse_check(const char *prompt)
{
	int		i;
	char	edge;

	i = -1;
	edge = 0;
	while (prompt && ++i < m_strlen(prompt))
		if (!check_c(prompt, &i, &edge))
			return (false);
	if (edge == 0)
		return (true);
	m_putstr("bash: parse error near quote\n", 2);
	return (false);
}
