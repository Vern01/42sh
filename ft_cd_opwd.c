/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_opwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:04:19 by rojones           #+#    #+#             */
/*   Updated: 2016/08/31 10:27:28 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_cd_opwd(t_data *data)
{
	int		varloc;
	char	**split;

	varloc = ft_check_env_var("OLDPWD", data->env);
	if (varloc == -1)
	{
		ft_putstr("cd: failed to get OLDPWD path\n");
		return ;
	}
	split = ft_strsplit(data->env[varloc], '=');
	if (split[1] == NULL)
	{
		ft_putstr("cd: failed to get OLDPWD path\n");
		return ;
	}
	ft_exc_cd(split[1], data->env);
	ft_free_str_arr(&split);
	varloc = ft_check_env_var("PWD", data->env);
	if (varloc == -1)
		return ;
	split = ft_strsplit(data->env[varloc], '=');
	if (split[1] == NULL)
		return ;
	ft_printf("%s\n", split[1]);
	ft_free_str_arr(&split);
}
