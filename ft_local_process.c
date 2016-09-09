/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_local_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 07:51:29 by oexall            #+#    #+#             */
/*   Updated: 2016/09/09 15:32:18 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static char	*ft_trimsp(char *str)
{
	char	*end;

	while (ft_isspace(*str))
		str++;
	end = str + ft_strlen(str) - 1;
	while (ft_isspace(*end))
		end--;
	*(end + 1) = '\0';
	return (str);
}

static char	*ft_get_var(char *str, t_data *data)
{
	int		ind;
	char	*tmp;
	char	*var;
	char	*pr;

	pr = NULL;
	tmp = str;
	while (*tmp != '\0' && !ft_isspace(*tmp))
		tmp++;
	var = ft_strsub(str, 1, tmp - str);
	if ((ind = ft_check_env_var(ft_trimsp(var), data->env)) > -1)
		pr = ft_get_env_var(data->env, ind);
	else if (ft_get_local(data, var))
		pr = ft_strdup(&ft_strchr(ft_get_local(data, ft_trimsp(var)), '=')[1]);
	ft_strdel(&var);
	return (pr);
}

char		*ft_local_process(char *line, t_data *data)
{
	char	*tmp;
	char	*pos;
	char	*var;
	char	*ret;

	if ((pos = ft_str_qut_char(line, '$')) == NULL)
		return (line);
	ret = ft_strsub(line, 0, pos - line);
	var = ft_get_var(pos, data);
	if (var)
	{
		tmp = ret;
		ft_strdel(&ret);
		ret = ft_strjoin(tmp, var);
		while (*pos != '\0' && !ft_isspace(*pos))
			pos++;
		tmp = ret;
		ft_strdel(&ret);
		ret = ft_strjoin(tmp, pos);
	}
	return (ft_local_process(ret, data));
}
