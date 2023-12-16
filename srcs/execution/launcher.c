#include "minishell.h"

static int	wait_son(int pid)
{
	int	status;

	status = 0;
	waitpid(pid, &status, 0);
	if (!WIFEXITED(status))
		return (-1);
	return (WEXITSTATUS(status));
}

static void	destroy_file(char *str)
{
	if (-1 == access(str, F_OK))
		return ;
	unlink(str);
}

/*
int	launch(t_leaf *leaf, int pipe_type)
{
	int		status;
	int		*fd_out;
	int		fd_in;
	t_red	red;

	status = 0;
	red = red_parse(leaf, &status);
	if (-1 == status)
		return (-1);
	fd_out = out_redirection(&red, pipe_type);
	if (!fd_out)
		return (exit_launch(&red));
	fd_in = write_in(&red, pipe_type);
	free_t_red(&red);
	g_glob.ret = execute(fd_in, fd_out[0], leaf);
	if (fd_out[0] != 1)
		write_on_file(fd_out);
	close_files(fd_out);
	if (fd_in > 2)
		close(fd_in);
	destroy_file(".tmp");
	return (status);
}

int	execute(int fd_in, int fd_out, t_leaf *leaf)
{
	int	cmd;

	cmd = find_builtins(leaf->cmd[0]);
	if (cmd)
		return (do_builtins(cmd, leaf));
	g_glob.pid_cmd = fork();
	if (!g_glob.pid_cmd)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		dup2(fd_in, 0);
		dup2(fd_out, 1);
		exec(leaf);
	}
	signal(SIGINT, &exit_execute);
	return (wait_son());
}

void	exec(t_leaf *leaf)
{
	char	*path;

	if (0 == access(leaf->cmd[0], F_OK | X_OK))
	{
		if (execve(leaf->cmd[0], leaf->cmd, g_glob.env) == -1)
			perror(leaf->cmd[0]);
	}
	else
	{
		path = get_path(leaf->cmd[0], g_glob.env);
		if (!path)
			perror(path);
		if (execve(path, leaf->cmd, g_glob.env) == -1)
			perror(path);
		free(path);
		free_glob();
	}
	exit(0);
}
*/