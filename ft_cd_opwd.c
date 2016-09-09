/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_opwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:04:19 by rojones           #+#    #+#             */
/*   Updated: 2016/09/08 07:34:54 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int	ft_cd_opwd(t_data *data)
{
	int		varloc;
	char	**split;

	if ((varloc = ft_check_env_var("OLDPWD", data->env)) == -1)
	{
		ft_putstr("cd: failed to get OLDPWD path\n");
		return (EXIT_FAILURE);
	}
	split = ft_strsplit(data->env[varloc], '=');
	if (split[1] == NULL)
	{
		ft_putstr("cd: failed to get OLDPWD path\n");
		return (EXIT_FAILURE);
	}
	ft_exc_cd(split[1], data->env);
	ft_free_str_arr(&split);
	varloc = ft_check_env_var("PWD", data->env);
	if (varloc == -1)
		return (EXIT_FAILURE);
	split = ft_strsplit(data->env[varloc], '=');
	if (split == NULL || split[1] == NULL)
		return (EXIT_FAILURE);
	ft_printf("%s\n", split[1]);
	ft_free_str_arr(&split);
	return (EXIT_SUCCESS);
}
