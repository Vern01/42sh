/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:03:08 by rojones           #+#    #+#             */
/*   Updated: 2016/09/07 13:19:41 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int	ft_cd_home(t_data *data)
{
	int		varloc;
	char	**split;

	varloc = ft_check_env_var("HOME", data->env);
	if (varloc == -1)
	{
		ft_putstr("cd: failed to get HOME path\n");
		return (EXIT_FAILURE);
	}
	split = ft_strsplit(data->env[varloc], '=');
	if (split[1] == NULL)
	{
		ft_putstr("cd: failed to get HOME path\n");
		return (EXIT_FAILURE);
	}
	ft_exc_cd(split[1], data->env);
	ft_free_str_arr(&split);
	return (EXIT_SUCCESS);
}
