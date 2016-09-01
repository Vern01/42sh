/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 12:58:23 by rojones           #+#    #+#             */
/*   Updated: 2016/08/31 10:25:58 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static char	*ft_sign_sub(char *in, char **env)
{
	char	*s1;
	char	*s2;
	char	*home;
	char	*tild;
	char	*re;

	if (in && (tild = ft_strstr(in, "~/")) != NULL)
	{
		home = ft_get_env_var(env, ft_check_env_var("HOME", env));
		s1 = ft_strsub(in, 0, (int)(tild - in));
		s2 = ft_strsub(in, (int)(tild - in) + 1,
				ft_strlen(in) - (int)(tild - in));
		re = ft_strjoin(s1, home);
		free(s1);
		free(home);
		s1 = re;
		re = ft_strjoin(s1, s2);
		free(s1);
		free(s2);
	}
	else
		re = ft_strdup(in);
	return (re);
}

static void	ft_check_dir_cd(char *path, char **env)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, R_OK) == 0)
			ft_exc_cd(path, env);
		else
			ft_putstr_fd("incorect permissions for file\n", 2);
	}
	else
		ft_putstr_fd("fille does not exist\n", 2);
}

char		**ft_cd(char **args, t_data *data)
{
	char	*path;

	path = NULL;
	if (ft_count_arg(args) > 2)
		ft_putstr("incorect number of arguments\n");
	else if (args[1] == NULL || ((int)(ft_strcmp(args[1], "~")) == 0)
			|| ((int)(ft_strcmp(args[1], "--")) == 0))
		ft_cd_home(data);
	else if ((int)(strcmp(args[1], "-")) == 0)
		ft_cd_opwd(data);
	else
	{
		path = ft_sign_sub(args[1], data->env);
		ft_check_dir_cd(path, data->env);
	}
	if (path)
		free(path);
	return (data->env);
}
