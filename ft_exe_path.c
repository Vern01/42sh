/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 10:02:46 by rojones           #+#    #+#             */
/*   Updated: 2016/09/09 15:25:05 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int	ft_exe_path(char **args, t_data *data)
{
	char	*path;
	int		script;

	script = 0;
	if ((path = ft_search_path(args, data, &script)) == NULL)
		return (0);
	execve(path, args, data->env);
	if (path)
		free(path);
	return (1);
}
