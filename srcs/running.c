#include "minishell.h"

bool		parse_check(char *prompt);
t_parse		*parse(t_shell *data);
void		run(t_parse *begin_cmd, t_shell *data);
/* ----------------------------------------- */

/* ================== to remove ================== */
void	print_red(char **red, int i)
{
	printf("red[%d]=", i);
	if (!red)
		printf("NULL");
	else
		for (int j = 0; red && red[j]; j++)
			printf("[%s] ", red[j]);
	printf("\n");
}

void	print_address(t_parse *ll)
{
	int	idx = 0;
	while (ll)
	{
		printf("cmd %d:\n", idx++);
		for (int i = 0; ll->cmds && ll->cmds[i]; i++)
			printf("[%s] ", ll->cmds[i]);
		printf("\n");
		print_red(ll->red->input1, 1);
		print_red(ll->red->input2, 2);
		print_red(ll->red->output1, 3);
		print_red(ll->red->output2, 4);
		ll = ll->next;
	}
}
/* =============================================== */

static int	prompt_check(t_shell *data)
{
	if (isatty(0) && isatty(2))
	{
		data->prompt = readline("\x1B[1m\x1B[41mHell$\x1B[0m ");
		if (!data->prompt)
		{
			m_putstr("exit\n", 1);
			m_freeTab(data->env);
			exit(0);
		}
	}
	if (!data->prompt[0])
		return (1);
	return (0);
}

static void	parse_prep(t_shell *data)
{
	int		i;
	int		idx;
	int		red;
	char	ret[PROMPT_MAX_SZ];

	i = -1;
	idx = 0;
	red = 0;
	m_bzero(&ret, PROMPT_MAX_SZ);
	while (data->prompt && data->prompt[++i])
	{
		if (data->prompt[i] == '<' || data->prompt[i] == '>')
			red = 1;
		else if (data->prompt[i] != ' ' && data->prompt[i] != '<'
			&& data->prompt[i] != '>')
			red = 0;
		if (m_isWhitespace(data->prompt[i]) && red)
			continue ;
		ret[idx++] = data->prompt[i];
	}
	free(data->prompt);
	data->prompt = m_strdup(ret);
}

// true = quit the program | false = stay in the loop
bool	running(t_shell *data)
{
	t_parse	*cmds;

	if (prompt_check(data))
		return (false);
	add_history(data->prompt);
	if (!parse_check(data->prompt))
		return (false);
	parse_prep(data);
	if (!data->prompt)
		return (true);
	cmds = parse(data);
	assign_pipe_type(cmds);
	/* ============== */
	print_address(cmds);
	/* ============== */
	run(cmds, data);
	free_list(cmds, 0);
	free(data->prompt);
	return (false);
}
