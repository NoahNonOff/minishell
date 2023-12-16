#include "minishell.h"

void	launch_pipe(int fd_in, int p_fd[2], t_parse *cmd, t_shell *data);
/* ----------------------------------------- */

static void	close_fd(int fd)
{
	if (fd > 2)
		close(fd);
}

void	execList(t_shell *data)
{
	int		fd_in;
	int		p_fd[2];
	t_parse	*cmd;

	fd_in = 0;
	cmd = data->begin_list;
	if (!cmd->pipe_type)
		launch(cmd, data);
	else
	{
		while (cmd)
		{
			if (cmd->pipe_type == 3)
				p_fd[1] = 1;
			else if (pipe(p_fd) == -1)
				continue ;
			launch_pipe(fd_in, p_fd, cmd, data);
			close_fd(fd_in);
			fd_in = p_fd[0];
			cmd = cmd->next;
		}
	}
}

void	launch_pipe(int fd_in, int p_fd[2], t_parse *cmd, t_shell *data)
{
	pid_t	pid_pipe;

	pid_pipe = fork();
	if (pid_pipe == -1)
		return ;
	if (!pid_pipe)
	{
		if (p_fd[0] != fd_in)
			close_fd(p_fd[0]);
		dup2(fd_in, 0);
		dup2(p_fd[1], 1);
		launch(ast, pipe_type);
		close_fd(p_fd[1]);
		free_shell();
		exit(0);
	}
	close_fd(p_fd[1]);
	waitpid(pid_pipe, NULL, 0);
}
