/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 09:41:54 by rojones           #+#    #+#             */
/*   Updated: 2016/09/09 08:36:56 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int	contains_command(char *s)
{
	if (strcmp(s, "echo") == 0)
		return (1);
	else if (strcmp(s, "cd") == 0)
		return (1);
	else if ((strcmp(s, "setenv") == 0 || strcmp(s, "export") == 0))
		return (1);
	else if ((strcmp(s, "unsetenv") == 0 || strcmp(s, "unset") == 0))
		return (1);
	return (0);
}

int	ft_get_block(char **s, int *block, int *pipe, t_data *data)
{
	if (strcmp(s[0], "echo") == 0)
		return (ft_echo(s, data));
	if (strcmp(s[0], "cd") == 0 && (*block += 1) && *pipe == 1)
		return (ft_cd(s, data));
	else if ((strcmp(s[0], "setenv") == 0 ||
			strcmp(s[0], "export") == 0) && (*block += 1) && *pipe == 1)
		return (ft_setenv(s, data));
	else if ((strcmp(s[0], "unsetenv") == 0 ||
			strcmp(s[0], "unset") == 0) && (*block += 1) && *pipe == 1)
		return (ft_unsetenv(s, data));
	return (EXIT_FAILURE);
}

int	ft_get_comm(char **s, t_data *data, int p)
{
	char	*path;
	int		b;

	path = NULL;
	b = 0;
	if (s[0])
	{
		if (strcmp(s[0], "exit") == 0)
			ft_exit(s, data);
		else if (contains_command(s[0]))
			return (ft_get_block(s, &b, &p, data));
		else if (strcmp(s[0], "env") == 0)
			ft_env(s, data->env);
		else if (b == 0 && (path = ft_search_path(s, data)) != NULL)
			execve(path, s, data->env);
		else if (ft_is_local(s[0]))
			ft_local_export(s[0], data);
		else if (strcmp(s[0], "printll") == 0)
			ft_print_locals(data);
		else if (b == 0)
			ft_printf("command not found: %s\n", s[0]);
		ft_strdel(&path);
	}
	return(EXIT_FAILURE);
}
