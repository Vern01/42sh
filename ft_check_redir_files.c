/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redir_files.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 07:01:48 by rojones           #+#    #+#             */
/*   Updated: 2016/08/06 13:25:12 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static void	ft_printerror(char *redir)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(redir, 2);
	ft_putstr_fd(" could not be done.\n", 2);
}

static void	ft_redir(char *redir, char op, int dir)
{
	int	tempfd;
	int	over;
	int	check;

	over = ft_redir_over(redir, ft_strchr(redir, op));
	check = 0;
	tempfd = dup(over);
	if (tempfd == -1)
	{
		ft_printerror(redir);
		return ;
	}
	if (dir == 1)
		check = ft_redir_out(redir, 0);
	else if (dir == 0)
		check = ft_redir_in(redir, 0, 1);
	if (check != -1)
	{
		dup2(tempfd, over);
		close(tempfd);
	}
	else
		ft_printerror(redir);
}

void		ft_check_redir_files(char *line)
{
	char	*nline;
	char	*redir;
	char	**split;
	int		i;

	nline = ft_strdup(line);
	redir = ft_get_redir(&nline);
	split = NULL;
	if (redir)
		split = ft_strsplit(redir, ' ');
	i = -1;
	while (split && split[++i])
	{
		if (ft_strchr(split[i], '<') != NULL)
			ft_redir(split[i], '<', 0);
		if (ft_strchr(split[i], '>') != NULL)
			ft_redir(split[i], '>', 1);
	}
	if (nline)
		free(nline);
	if (redir)
		free(redir);
	if (split)
		ft_free_str_arr(&split);
}
