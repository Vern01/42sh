/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 09:58:34 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/09 16:42:19 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <dirent.h>

t_list	*auto_read_bin(t_list *lst, t_auto *new, char *line, int ret)
{
	DIR				*dir;
	struct dirent	*dp;
	char			**mytab;
	int				i;

	dp = NULL;
	mytab = ft_strsplit(ft_strchr(getenv("PATH"), ':') + 1, ':');
	i = -1;
	while (mytab[++i] != NULL)
	{
		dir = opendir(mytab[i]);
		while ((dp = readdir(dir)) != NULL)
		{
			if (ft_isalnum(dp->d_name[0]) == 0)
				continue ;
			if (ret == 1)
			{
				ft_lstaddend(&lst, ft_lstnew(dp->d_name, dp->d_namlen));
				if (new->len < dp->d_namlen)
					new->len = dp->d_namlen;
			}
			else
			{
				if (ft_strncmp(line, dp->d_name, ft_strlen(line)) == 0)
					ft_lstaddend(&lst, ft_lstnew(dp->d_name, dp->d_namlen));
				if (new->len < dp->d_namlen)
					new->len = dp->d_namlen;
			}
		}
	}
	return (lst);
}

t_list	*auto_read_dir(t_list *lst, t_auto *new, char *line, int ret)
{
	DIR				*dir;
	struct dirent	*dp;

	dir = opendir(".");
	dp = NULL;
	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_isalnum(dp->d_name[0]) == 0)
			continue ;
		if (ret == 1)
		{
			ft_lstaddend(&lst, ft_lstnew(dp->d_name, dp->d_namlen));
			if (new->len < dp->d_namlen)
				new->len = dp->d_namlen;
		}
		else
		{
			if (ft_strncmp(ft_strrchr(line, ' ') + 1, dp->d_name, \
						ft_strlen(ft_strrchr(line, ' ') + 1)) == 0)
				ft_lstaddend(&lst, ft_lstnew(dp->d_name, dp->d_namlen));
			if (new->len < dp->d_namlen)
				new->len = dp->d_namlen;
		}
	}
	return (lst);
}
