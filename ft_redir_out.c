/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 14:07:06 by rojones           #+#    #+#             */
/*   Updated: 2016/08/06 14:11:08 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static char	*ft_getname(char *name, int *op)
{
	if (*(name + 1) == '>')
	{
		*op = 2;
		name += 2;
	}
	else
	{
		*op = 1;
		name++;
	}
	return (name);
}

static void	ft_close(char *redir)
{
	char	*op;
	char	*sub;
	int		fd;

	op = ft_strchr(redir, '>');
	if (op == NULL)
		return ;
	if (op == redir)
	{
		puts("closing fd 1");
		close(1);
	}
	else
	{
		sub = ft_strsub(redir, 0, (int)(op - redir));
		fd = ft_atoi(sub);
		close(fd);
		if (sub)
			free(sub);
	}
}

static int	ft_open(int op, int over, char *name)
{
	int fd;

	fd = -1;
	over = 1;
	if (op == 1)
		fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	else
		fd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0777);
	if (fd == -1)
	{
		ft_putstr("failed to open file");
		return (-1);
	}
	dup2(fd, over);
	close(fd);
	return (fd);
}

int			ft_redir_out(char *redir, int cl)
{
	int		fd;
	int		op;
	int		over;
	char	*name;

	over = 1;
	fd = -1;
	name = ft_strchr(redir, '>');
	over = ft_redir_over(redir, name);
	name = ft_getname(name, &op);
	if (cl)
		fd = 1;
	if (ft_strcmp(name, "&-") == 0 && cl == 1)
		ft_close(redir);
	else if (ft_strcmp(name, "&-") != 0)
		fd = ft_open(op, over, name);
	return (fd);
}
