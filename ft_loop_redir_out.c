/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_redir_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 17:55:11 by rojones           #+#    #+#             */
/*   Updated: 2016/09/07 15:22:33 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_loop_redir_out(t_launch *lau, t_data *data, char **env, int i)
{
	pid_t	pid;

	if (lau->out && lau->out[i])
	{
		pid = fork();
		if (pid == -1)
			ft_putstr_fd("forrk error\n", 2);
		else if (pid == 0)
		{
			ft_redir_out(lau->out[i], 1);
			ft_get_comm(lau->args, data, lau->pipe);
			exit(0);
		}
		else
		{
			wait(NULL);
			ft_loop_redir_out(lau, data, env, i + 1);
		}
	}
	return (env);
}
