/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 09:41:54 by rojones           #+#    #+#             */
/*   Updated: 2016/08/31 11:13:56 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_get_comm(char **split, t_data *data)
{
	char	*path;

	path = NULL;
	if (split[0])
	{
		if (strcmp(split[0], "exit") == 0)
			ft_exit(split, data);
		else if (strcmp(split[0], "echo") == 0)
			ft_echo(split, data->env);
		else if (strcmp(split[0], "cd") == 0)
			ft_cd(split, data);
		else if (strcmp(split[0], "setenv") == 0)
			data->env = ft_setenv(split, data);
		else if (strcmp(split[0], "unsetenv") == 0)
			data->env = ft_unsetenv(split, data);
		else if (strcmp(split[0], "env") == 0)
			ft_env(split, data->env);
		else if ((path = ft_search_path(split, data)) != NULL)
			execve(path, split, data->env);
		else
			ft_printf("command not found: %s\n", split[0]);
		if (path)
			free(path);
	}
	return (data->env);
}
