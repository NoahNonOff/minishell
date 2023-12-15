#include "minishell.h"

void	run(t_parse *begin_cmd, t_shell *data)
{
	t_parse	*cmd;
	// int		pipe_fd[2];

	(void)data;
	cmd = begin_cmd;
	while (cmd)
	{
		// execute()
		cmd = cmd->next;
	}
}