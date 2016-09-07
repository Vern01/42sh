/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 09:41:54 by rojones           #+#    #+#             */
/*   Updated: 2016/09/07 07:44:28 by oexall           ###   ########.fr       */
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
			ft_echo(split, data);
		else if (strcmp(split[0], "cd") == 0)
			ft_cd(split, data);
		else if (strcmp(split[0], "setenv") == 0 || strcmp(split[0], "export") == 0)
			data->env = ft_setenv(split, data);
		else if (strcmp(split[0], "unsetenv") == 0 || strcmp(split[0], "unset") == 0)
			data->env = ft_unsetenv(split, data);
		else if (strcmp(split[0], "env") == 0)
			ft_env(split, data->env);
		else if ((path = ft_search_path(split, data)) != NULL)
			execve(path, split, data->env);
		else if (ft_is_local(split[0]))
			ft_local_export(split[0], data);
		else if (strcmp(split[0], "printll") == 0)
			ft_print_locals(data);
		else
			ft_printf("command not found: %s\n", split[0]);
		if (path)
			free(path);
	}
	return (data->env);
}
