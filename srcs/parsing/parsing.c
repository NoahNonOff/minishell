#include "minishell.h"

char	*extract_token(char *prompt, int *pos);
bool	modified_token(t_shell *data, char **token, t_red **red);
/* ----------------------------------------- */

void	free_red(t_red *red)
{
	m_freeTab(red->input1);
	m_freeTab(red->input2);
	m_freeTab(red->output1);
	m_freeTab(red->output2);
	free(red);
}

static bool	error_in_parsing(t_red *red, char **cmd)
{
	if (!red || !cmd)
	{
		free_red(red);
		m_freeTab(cmd);
		return (true);
	}
	return (false);
}

static bool	t_redInit(t_red **red)
{
	if (!red)
		return (false);
	*red = malloc(sizeof(t_red));
	if (!(*red))
		return (false);
	(*red)->input1 = NULL;
	(*red)->input2 = NULL;
	(*red)->output1 = NULL;
	(*red)->output2 = NULL;
	return (true);
}

char	**extract_cmd(t_shell *data, int *pos, t_red **red)
{
	char	**cmd;
	char	*token;

	cmd = NULL;
	if (!t_redInit(red))
		return (NULL);
	while (data->prompt && m_isWhitespace(data->prompt[*pos]))
		(*pos)++;
	while (data->prompt && data->prompt[*pos] && data->prompt[*pos] != '|')
	{
		token = extract_token(data->prompt, pos);
		if (!token || !modified_token(data, &token, red))
			return (m_freeTab(cmd));
		cmd = m_endtabPush(cmd, token);
		if (!cmd)
			return (m_freeTab(cmd));
		while (data->prompt[*pos] && m_isWhitespace(data->prompt[*pos]))
			(*pos)++;
	}
	if (data->prompt[*pos] == '|')
		(*pos)++;
	return (cmd);
}

t_parse	*parse(t_shell *data)
{
	int		pos;
	char	**cmd;
	t_red	*red;
	t_parse	*begin;

	pos = 0;
	begin = NULL;
	while (pos < m_strlen(data->prompt))
	{
		red = NULL;
		cmd = extract_cmd(data, &pos, &red);
		if (error_in_parsing(red, cmd))
			return (free_list(begin, 1));
		begin = add_parse(begin, red, cmd);
	}
	return (begin);
}