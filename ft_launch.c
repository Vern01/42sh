/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 13:36:10 by rojones           #+#    #+#             */
/*   Updated: 2016/09/09 09:22:27 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static void	ft_init(t_launch *lau, char *line)
{
	lau->cmd = ft_split_line_op(line);
	lau->i = -1;
	if (lau->cmd && lau->cmd[1] == NULL)
		lau->pipe = 0;
	else if (lau->cmd && lau->cmd[1] != NULL)
		lau->pipe = 1;
	lau->fd_in = 0;
	lau->out = NULL;
	lau->in = NULL;
}

static void	ft_close(t_launch *lau, int full)
{
	if (lau->cmd && full == 1)
		ft_free_str_arr(&lau->cmd);
	if (lau->out)
		ft_free_str_arr(&lau->out);
	if (lau->in)
		ft_free_str_arr(&lau->in);
}

static void	ft_perent(t_launch *lau, t_data *data, int *stat)
{
	wait(stat);
	*stat = WEXITSTATUS(*stat);
	if (ft_strcmp(lau->args[0], "exit") == 0)
		ft_exit(lau->args, data);
	else if (strcmp(lau->args[0], "cd") == 0)
		*stat = ft_cd(lau->args, data);
	else if (strcmp(lau->args[0], "setenv") == 0 ||
			strcmp(lau->args[0], "export") == 0)
		*stat = ft_setenv(lau->args, data);
	else if (strcmp(lau->args[0], "unsetenv") == 0 ||
			strcmp(lau->args[0], "unset") == 0)
		*stat = ft_unsetenv(lau->args, data);
	else if (ft_is_local(lau->args[0]))
		ft_local_export(lau->args[0], data);
	close(lau->p[1]);
	lau->fd_in = lau->p[0];
	if (lau->args)
		ft_free_str_arr(&lau->args);
	if (lau->out)
		ft_free_str_arr(&lau->out);
	if (lau->in)
		ft_free_str_arr(&lau->in);
	if (lau->redir)
		ft_memdel((void **)&lau->redir);
}

static void	ft_chiled(char **env, t_launch *lau, t_data *data)
{
	int	j;
	int	re;

	j = -1;
	re = EXIT_FAILURE;
	dup2(lau->fd_in, 0);
	if (lau->in)
		while (lau->in[++j])
			ft_redir_in(lau->in[j], 1, j + lau->fd_in);
	if ((lau->cmd[lau->i + 1]) != NULL)
	{
		env = ft_loop_redir_out(lau, data, env, 0);
		dup2(lau->p[1], 1);
		re = ft_get_comm(lau->args, data, lau->pipe);
	}
	else
	{
		if (lau->out && lau->out[0])
			env = ft_loop_redir_out(lau, data, env, 0);
		else
			re = ft_get_comm(lau->args, data, lau->pipe);
	}
	close(lau->p[0]);
	exit(EXIT_FAILURE);
}

char		**ft_launch(char *line, t_data *data, int *stat)
{
	t_launch	lau;

	ft_check_redir_files(line);
	ft_init(&lau, line);
	while (lau.cmd[++lau.i])
	{
		lau.redir = ft_get_redir(&lau.cmd[lau.i]);
		if (lau.redir)
			ft_launch_redir(&lau);
		lau.args = ft_extract_args(lau.cmd[lau.i]);
		if (lau.args && lau.args[0])
		{
			pipe(lau.p);
			if ((lau.pid = fork()) == -1)
				exit(EXIT_FAILURE);
			else if (lau.pid == 0)
				ft_chiled(data->env, &lau, data);
			else
				ft_perent(&lau, data, stat);
		}
		ft_close(&lau, 0);
	}
	ft_close(&lau, 1);
	return (data->env);
}
