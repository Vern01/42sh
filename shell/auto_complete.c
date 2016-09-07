/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:17:27 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/07 13:49:31 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*get_auto_line(char *line)
{
	char	*new;
	int		i;

	if (ft_strlen(line) < 1 || line[ft_strlen(line) - 1] == ' ')
		return (ft_strdup(line));
	i = ft_strlen(line) - 1;
	while (i >= 0 && line[i] != ' ')
		i--;
	new = ft_strnew(i + 1);
	ft_strncpy(new, line, i + 1);
	return (new);
}

int		ft_auto(t_term **sh)
{
	int		i;

	if ((*sh)->len < 1)
	{
		ft_add_to_line(&(*sh));
		return (0);
	}
	i = -1;
	while ((*sh)->line[++i] != '\0')
		if ((*sh)->line[i] != '\t')
			return (ft_auto_complete(&(*sh), NULL, NULL, 1));
	ft_add_to_line(&(*sh));
	return (0);
}

int		ft_auto_complete(t_term **sh, t_list *lst, t_list *tmp, int ret)
{
	t_auto	new;
	char	*line;

	new.len = 0;
	lst = get_auto_list(&(*sh), &new, (*sh)->line);
	line = get_auto_line((*sh)->line);
	while (ret > 0 && (*sh)->buf[0] == 9   && lst != NULL)
	{
		if (tmp == NULL)
			tmp = lst;
		ft_memset((*sh)->line, 0, MAX_LEN);
		ft_strcpy((*sh)->line, line);
		ft_strncat((*sh)->line, tmp->content, tmp->content_size);
		(*sh)->my_cur = ft_strlen((*sh)->line);
		(*sh)->len = ft_strlen((*sh)->line);
		(*sh)->std_cur = (ft_strlen((*sh)->prt) + (*sh)->my_cur) % tgetnum("co");
		ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
		if (ft_lstsize(lst) > 1)
			auto_complete_print(lst, &new, 0, (*sh)->std_cur);
		tmp = tmp->next;
		ret = read(0, (*sh)->buf, 3);
	}
	if (ret > 0 && lst != NULL)
		return (ft_buf_input(&(*sh)));
	else
		return (ft_read_entry(&(*sh)));
	return (0);
}
