#include "minishell.h"

char	**tabRemoveEmpty(char **cmd);
char	*extract_token(char *prompt, int *pos);
bool	modified_token(t_shell *data, char **token, t_red *red);
/* ----------------------------------------- */

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

// this function aims to extract the commands (multiple tokens)
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
		if (!token || !modified_token(data, &token, *red))
			return (m_freeTab(cmd));
		cmd = m_endtabPush(cmd, token);
		free(token);
		while (data->prompt[*pos] && m_isWhitespace(data->prompt[*pos]))
			(*pos)++;
	}
	if (data->prompt[*pos] == '|')
		(*pos)++;
	return (cmd);
}

// It check if an errors occurs during the parsing
static bool	check_extract_error(char **cmd, t_red *red)
{
	if (!red || !cmd)
	{
		free_red(red);
		m_freeTab(cmd);
		m_putstr("error: failed during allocation\n", 2);
		return (false);
	}
	return (true);
}

/*
	this function create the linked list by extracting
	a string array, and a structure for the redirections
*/
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
		cmd = tabRemoveEmpty(cmd);
		if (!check_extract_error(cmd, red))
			return (NULL);
		begin = add_parse(begin, red, cmd);
	}
	return (begin);
}