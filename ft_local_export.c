/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_local_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 10:43:37 by oexall            #+#    #+#             */
/*   Updated: 2016/09/06 14:48:40 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	*ft_get_local(t_data *data, char *search)
{
	int	i;

	i = -1;
	while (data->local[++i])
		if (ft_strncmp(data->local[i], search, ft_strlen(search)) == 0)
			return (data->local[i]);
	return (NULL);
}

void	ft_print_locals(t_data *data)
{
	int	i;

	i = -1;
	while (data->local[++i])
		ft_putendl(data->local[i]);
}

int		ft_is_local(char *line)
{
	char	*tmp;
	char	*e_pos;

	tmp = line;
	if ((e_pos = ft_strchr(line, '=')) == NULL)
		return (0);
	while (*tmp != *e_pos)
	{
		if (!ft_isalnum(*tmp))
			return (0);
		tmp++;
	}
	return (1);
}

void	ft_replace_local(char *name, t_data *data, char *local)
{
	int	i;

	i = -1;
	while (data->local[++i])
		if (ft_strncmp(data->local[i], name, ft_strlen(name)) == 0)
		{
			free(data->local[i]);
			data->local[i] = ft_strdup(local);
		}
}

void	ft_local_export(char *local, t_data *data)
{
	int		i;
	char	*name;
	char	**tmp;

	name = ft_strsub(local, 0, ft_strlen(local) -
			ft_strlen(ft_strchr(local, '=')));
	if (!data->local)
	{
		data->local = (char **)malloc(sizeof(char *) * 2);
		data->local[0] = ft_strdup(local);
		data->local[1] = NULL;
	}
	else if (data->local && ft_get_local(data, name))
		ft_replace_local(name, data, local);
	else if (data->local)
	{
		i = 0;
		while (data->local[i])
			i++;
		tmp = ft_dupenv(data->local, i + 1);
		tmp[i] = ft_strdup(local);
		ft_free_str_arr(&data->local);
		data->local = tmp;
	}
	free(name);
}
