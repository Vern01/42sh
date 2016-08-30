/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 07:49:11 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 08:59:49 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

int		ft_cargs(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*ft_chrjoin(char *str1, char *str2, char c)
{
	char	*tmp;
	int		len;
	int		i;

	len = ft_strlen(str1) + ft_strlen(str2) + 2;
	tmp = (char *)malloc(sizeof(char) * len);
	i = -1;
	while (*str1)
	{
		tmp[++i] = *str1;
		str1++;
	}
	tmp[++i] = c;
	while (*str2)
	{
		tmp[++i] = *str2;
		str2++;
	}
	tmp[++i] = '\0';
	return (tmp);
}

int		ft_setenv(t_env *env, char *name, char *value, int reset)
{
	int		c;
	char	**tmp;

	if (!name || !value)
		return (ft_error(1, "setenv", E_SETENV));
	if (ft_getenv(name, env) && reset)
		return (ft_update_env(env, name, value));
	else if (!ft_getenv(name, env))
	{
		c = ft_cargs(env->environ);
		tmp = ft_dupenviron(env->environ, c + 1);
		tmp[c] = ft_chrjoin(name, value, '=');
		ft_free_environ(env->environ);
		env->environ = tmp;
	}
	return (1);
}
