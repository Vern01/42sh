/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh21.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 11:50:00 by rojones           #+#    #+#             */
/*   Updated: 2016/09/09 08:24:29 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static int	ft_oflag(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-o") == 0)
			return (1);
		if (ft_strcmp(av[i], "-u") == 0)
			return (2);
		i++;
	}
	return (-1);
}

static char	*ft_get_prompt(char **env)
{
	char	*h;
	char	*p;
	char	*t;
	int		check;

	h = NULL;
	p = NULL;
	t = NULL;
	check = ft_check_env_var("HOME", env);
	if (check != -1)
		h = ft_get_env_var(env, check);
	if (check != -1)
		check = ft_check_env_var("PWD", env);
	if (check != -1)
		p = ft_get_env_var(env, check);
	if (p && h)
	{
		if (ft_strstr(p, h) == p)
			t = ft_strdup(&p[ft_strlen(h)]);
	}
	if (p)
		free(p);
	if (h)
		free(h);
	return (t);
}

void	ft_prompt(int oflag, char **env)
{
	int		check;
	char	*p;

	p = NULL;
	if (oflag == 1)
	{
		p = ft_get_prompt(env);
		if (p != NULL)
			ft_printf("%s> ", p);
	}
	else if (oflag == 2)
	{
		check = ft_check_env_var("USER", env);
		p = ft_get_env_var(env, check);
		ft_printf("%s> ", p);
	}
	if (oflag == -1 || p == NULL)
		write(1, "$> ", 3);
	if (p)
		free(p);
}

int			main(int ac, char **av)
{
	t_data		data;
	extern char **environ;
	int         oflag;

	ft_init_win(&data.win);
	data.env = ft_cpyenv(environ);
	data.local = NULL;
	oflag = ft_oflag(ac, av);
	data.line = ft_line_def();
	while (1)
	{
		data.line->line = get_line(data.line->line);
		if (data.line->line != NULL && data.line->line[0] != '\0')
			data.line->line = ft_check_qut(data.line->line);
		if (data.line->line != NULL && data.line->line[0] != '\0')
			data.env = ft_split_input(
					ft_local_process(data.line->line, &data), &data);
		ft_history_tower("reset", data.line->line);
	}
}
