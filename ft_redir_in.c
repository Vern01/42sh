/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 14:09:20 by rojones           #+#    #+#             */
/*   Updated: 2016/08/06 14:21:21 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

/*
** static void ft_write_untill(char *name)
**{
**	pid_t	pid;
**	int		end;
**	char	*line;
**
**	end = 0;
**	pid = getpid();
**	while (get_next_line(0, &line) > 0 && end == 0)
**	{
**		if (ft_strcmp(line, name) == 0)
**			end = 1;
**		else
**		{
**			ft_putstr_fd(line, 0);
**			ft_putstr_fd("\n", 0);
**		}
**		if (line)
**			free(line);
**	}
**}
*/

static void	ft_close(char *redir)
{
	char	*op;
	char	*sub;
	int		fd;

	op = ft_strchr(redir, '<');
	if (op == NULL)
		return ;
	if (op == redir)
		close(0);
	else
	{
		sub = ft_strsub(redir, 0, (int)(op - redir));
		fd = ft_atoi(sub);
		close(fd);
		if (sub)
			free(sub);
	}
}

static void	ft_write_fd(int over, char *name)
{
	int		fd;
	int		rdre;
	char	buf[20];

	if (name == NULL)
		return ;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return ;
	while ((rdre = read(fd, buf, 20)) > 0)
		write(over, buf, rdre);
	close(fd);
}

static int	ft_exe_single_op(int init, int over, int cl, char *name)
{
	int fd;

	fd = 0;
	if (init == 0)
	{
		fd = open(name, O_RDONLY);
		if (fd == -1)
			return (-1);
		dup2(fd, over);
		close(fd);
	}
	else if (cl == 1)
		ft_write_fd(over, name);
	return (fd);
}

int			ft_redir_in(char *redir, int cl, int init)
{
	int		op;
	int		fd;
	int		over;
	char	*name;

	over = 0;
	op = 0;
	name = ft_strchr(redir, '<');
	over = ft_redir_over(redir, name);
	fd = 0;
	if (*(name + 1) == '<')
	{
		op = 1;
		name += 2;
	}
	else
		name++;
	if (ft_strcmp(name, "&-") == 0 && cl == 1)
		ft_close(redir);
	else if (op == 0)
		fd = ft_exe_single_op(init, over, cl, name);
	else
		;
	return (fd);
}
