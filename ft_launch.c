/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 13:36:10 by rojones           #+#    #+#             */
/*   Updated: 2016/09/07 11:50:01 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

/*
** char	**ft_launch(char *line, char **env)
**  {
**  pid_t	pid;
**  int		status;
**  char	**args;
**
**  args = ft_extract_args(line);
**  if (args && args[0])
**  {
**  if (ft_strcmp(args[0], "exit") == 0)
**  ft_exit(args, env);
**  else if (strcmp(args[0], "cd") == 0)
**  ft_cd(args, env);
**  else if (strcmp(args[0], "setenv") == 0)
**  env = ft_setenv(args, env);
**  else if (strcmp(args[0], "unsetenv") == 0)
**  env = ft_unsetenv(args, env);
**  else
**  {
**  pid = fork();
**  if (pid > 0)
**  wait(&status);
**  if (pid == 0)
**  {
**  env = ft_op_order(args, env);
**  exit(0);
**  }
**  ft_free_str_arr(args);
**  }
**  }
**  return (env);
** }
*/

static void	ft_init(t_launch *lau, char *line)
{
	lau->cmd = ft_split_line_op(line);
	lau->i = -1;
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
	if(lau->in)
		ft_free_str_arr(&lau->in);
}

static void	ft_perent(t_launch *lau, t_data *data, int	*stat)
{
	wait(stat);
	*stat = WEXITSTATUS(*stat);
//	*stat = WIFEXITED(*stat);
	ft_printf("stat %d\n", *stat);
	if (ft_strcmp(lau->args[0], "exit") == 0)
		ft_exit(lau->args, data);
	else if (strcmp(lau->args[0], "cd") == 0)
		ft_cd(lau->args, data);
	else if (strcmp(lau->args[0], "setenv") == 0)
		data->env = ft_setenv(lau->args, data);
	else if (strcmp(lau->args[0], "unsetenv") == 0)
		data->env = ft_unsetenv(lau->args, data);
	close(lau->p[1]);
	lau->fd_in = lau->p[0];
	if (lau->args)
		ft_free_str_arr(&lau->args);
	if (lau->out)
		ft_free_str_arr(&lau->out);
	if (lau->in)
		ft_free_str_arr(&lau->in);
	if (lau->redir)
	{
		free(lau->redir);
		lau->redir = NULL;
	}
}

static void	ft_chiled(char **env, t_launch *lau, t_data *data)
{
	int	j;

	j = -1;
	dup2(lau->fd_in, 0);
	if (lau->in)
	{
		while (lau->in[++j])
			ft_redir_in(lau->in[j], 1, j + lau->fd_in);
	}
	if ((lau->cmd[lau->i + 1]) != NULL)
	{
		env = ft_loop_redir_out(lau, data, env, 0);
		dup2(lau->p[1], 1);
		env = ft_get_comm(lau->args, data);
	}
	else
	{
		if (lau->out && lau->out[0])
			env = ft_loop_redir_out(lau, data, env, 0);
		else
			env = ft_get_comm(lau->args, data);
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
		{
			lau.splredir = ft_strsplit(lau.redir, ' ');
			ft_split_redir(lau.splredir, &lau.out, &lau.in);
		}
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
