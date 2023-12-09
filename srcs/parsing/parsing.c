#include "minishell.h"

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
}

t_parse	*parse(t_shell *data)
{
	int		pos;
	char	**cmd;
	t_red	*red;
	t_parse	*parse;

	pos = 0;
	parse = NULL;
	while (pos < m_strlen(data->prompt))
	{
		red = NULL;
		cmd = extract_cmd(data, &pos, &red);
		if (error_in_parsing(red, cmd))
			return (free_list(begin, 1));
		parse = add_parse(parse, red, cmd);
	}
	return (parse);
}

char	**extract_cmd(t_prompt *data, int *pos, t_red **red)
{
	if (!t_redInit(red))
		return (NULL);
}

/*
char	**extract_cmd(t_prompt *data, int *pos, t_red **red)
{
	int		len;
	char	*token;
	char	**cmd;

	cmd = NULL;
	while (data->prompt && _is_whitespace(data->prompt[*pos]))
		(*pos)++;
	while (data->prompt && data->prompt[*pos] != '|')
	{
		token = extract_token(data->prompt, pos); // extract the token (tes"$PATH >alpha"'alpha'>file1)
		if (!token)
			return (_free_tab(cmd));
		token = modified_token(data, token, red); // set red
		cmd = _endtab_push(cmd, token); // add the token to the tab
		if (!cmd)
			return (_free_tab(cmd));
		while (data->prompt && _is_whitespace(data->prompt[*pos]))
			(*pos)++;
	}
	if (data->prompt[*pos] == '|')
		(*pos)++; // skip the pipe
	return (cmd);
}
*/