#include "minishell.h"

bool		parse_check(char *prompt);
t_parse		*parse(t_shell *data);

void	print_address(t_parse *ll);
/* ----------------------------------------- */

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


int	running(t_shell *data)
{
	t_parse	*cmds;

	if (prompt_check(data))
		return (0);
	add_history(data->prompt);
	if (!parse_check(data->prompt))
		return (0);
	cmds = parse(data);

	//printf("%s\n", data->prompt);
	print_address(cmds);
	free_list(cmds, 0);
	free(data->prompt);
	return (0);
}
