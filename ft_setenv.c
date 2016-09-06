/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:46:36 by rojones           #+#    #+#             */
/*   Updated: 2016/09/06 13:58:06 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char		**ft_replace_env_var(char **env, char *value, int i)
{
	char	**re;
	char	*temp;

	re = ft_cpyenv(env);
	if (!re || !value)
		return (env);
	temp = re[i];
	re[i] = strdup(value);
	free(value);
	if (temp)
		free(temp);
	return (re);
}

char		**ft_add_env_var(char **split, char **env)
{
	char	**re;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
		i++;
	if (!(re = (char **)malloc(sizeof(char *) * (i + 2))))
	{
		ft_putstr("add_env_var Memory allocation failed.\n");
		return (NULL);
	}
	while (env[j])
	{
		re[j] = strdup(env[j]);
		j++;
	}
	re[j++] = ft_build_env_var(split);
	re[j] = NULL;
	return (re);
}

char	**ft_dupenv(char **env, int size)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = (char **)malloc(sizeof(char *) * (size + 1));
	while (env[++i] && i < size)
		tmp[i] = ft_strdup(env[i]);
	while (++i < size)
		tmp[i][0] = '\0';
	tmp[size] = NULL;
	return (tmp);
}

char		**ft_setenv(char **split, t_data *data)
{
	int		c;
	char	**tmp;
	char	*name;

	if (!split[0] || !split[1])
	{
		ft_printf("setenv: Needs and arguement.\n");
		return (NULL);
	}
	tmp = NULL;
	name = ft_strsub(split[1], 0, ft_strchr(split[1], '=') - split[1]);
	if (ft_check_env_var(name, data->env) < 0)
	{
		c = 0;
		while (data->env[c])
			c++;
		tmp = ft_dupenv(data->env, c + 1);
		tmp[c] = ft_strdup(split[1]);
		ft_free_str_arr(&data->env);
		data->env = tmp;
	}
	free(name);
	return (tmp);
}
