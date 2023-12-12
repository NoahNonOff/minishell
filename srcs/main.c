#include "minishell.h"

int		running(t_shell *data);
/* ----------------------------------------- */

void	handle_signal(int signo)
{
	if (signo == SIGINT)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	init_data(t_shell *data, char *env[])
{
	data->env = m_duplicateTab(env);
	if (!data->env)
		exit (1);
	data->ret_value = 0;
}

static void	end_prog(t_shell *data)
{
	free(data->prompt);
	m_freeTab(data->env);
}

int	main(int ac, char *av[], char *env[])
{
	t_shell	data;

	(void)ac;
	(void)av;
	init_data(&data, env);
	while (1)
	{
		signal(SIGINT, handle_signal);
		signal(SIGQUIT, SIG_IGN);
		if (running(&data))
			break ;
	}
	end_prog(&data);
	return (0);
}
