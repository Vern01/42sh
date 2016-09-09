/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 21:19:02 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/09 16:41:00 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*get_line(char *line)
{
	static int	i = 1;
	t_term		*shell;
	int			ret;

	if (i == 1)
	{
		tputs(tgetstr("cl", 0), 0, ft_shell_putchar);
		i++;
	}
	shell = ft_init_shell();
	ret = 0;
	ft_memset(shell->line, 0, MAX_LEN);
	shell->std_cur = ft_strlen(shell->prt);
	tputs(tgetstr("sc", 0), 0, ft_shell_putchar);
	while (1)
	{
		ret = ft_read_entry(&shell);
		if (ret == 1)
		{
			line = ft_strdup(shell->line);
			return (line);
		}
	}
	return (NULL);
}
