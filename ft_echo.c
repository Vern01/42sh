/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 10:09:47 by rojones           #+#    #+#             */
/*   Updated: 2016/09/07 07:44:01 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static void	ft_init_echo_flag(t_echo_flag *echo_flag)
{
	echo_flag->n = 0;
	echo_flag->set_e = 1;
}

static int	ft_check_flag(char *arg, t_echo_flag *echo_flag)
{
	int	i;

	if (arg[0] != '-' || (arg[0] == '-' && arg[1] == '\0'))
		return (0);
	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'n')
			echo_flag->n = 1;
		else if (arg[i] == 'e')
			echo_flag->set_e = 1;
		else if (arg[i] == 'E')
			echo_flag->set_e = 0;
		else
			return (0);
		i++;
	}
	return (1);
}

static int	ft_echo_mode(char **args, t_echo_flag echo_flag, t_data *dat, int i)
{
	int	re;
	int	sp;

	re = 0;
	sp = 1;
	if (ft_strstr(args[i], "$"))
		sp = ft_echo_env_var(dat, args[i]);
	else if (echo_flag.set_e == 0)
		ft_putstr(args[i]);
	else
		re = ft_echo_str(args[i]);
	if (args[i + 1] != NULL && sp == 1)
		ft_putchar(' ');
	return (re);
}

void		ft_echo(char **args, t_data *data)
{
	t_echo_flag	echo_flag;
	int			i;
	int			exit;

	i = 1;
	exit = 0;
	ft_init_echo_flag(&echo_flag);
	while (args[i] && ft_check_flag(args[i], &echo_flag) == 1)
		i++;
	while (args[i] && exit == 0)
	{
		exit = ft_echo_mode(args, echo_flag, data, i);
		i++;
	}
	if (echo_flag.n == 0 && exit == 0)
		ft_putstr("\n");
}
