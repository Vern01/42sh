/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 17:18:28 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/07 13:18:14 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <dirent.h>

int		check_auto(char *line)
{
	int		i;
	int		check;
	int		len;

	i = -1;
	check = 0;
	while (line[++i] != '\0')
	{
		if (line[i] != '\t' && line[i] != ' ')
		{
			while (line[i] != '\0' && line[i] != '\t' && line[i] != ' ')
				i++;
			check++;
		}
		if (check > 1)
			return (1);
	}
	if (check == 0)
		return (0);
	len = ft_strlen(line) - 1;
	if (check == 1 && line[len] == ' ')
		return (1);
	return (2);
}

t_list	*get_auto_list(t_term **sh, t_auto *new, char *line)
{
	t_list			*lst;
	int				ret;
	int				val;

	ret = check_auto(line);
	val = 0;
	lst = NULL;
	new->nb = 0;
	new->len = 0;
	if (ft_strlen(line) < 1 || line[ft_strlen(line) - 1] == ' ')
		val = 1;
	if (ret == 1)
		lst = auto_read_dir(lst, new, line, val);
	else
		lst = auto_read_bin(lst, new, line, val);
	new->nb = tgetnum("co") / (new->len + 3);
	if (ft_lstsize(lst) > 1)
		auto_complete_print(lst, new, 0, (*sh)->std_cur);
	return (lst);
}
