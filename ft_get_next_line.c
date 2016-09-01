/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 11:32:54 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/06 17:29:39 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"
#include <ctype.h>

char	*ft_realloc(char *p, size_t size, size_t cursor, t_line *l)
{
	char	*temp;
	size_t	i;
	size_t	j;

	if (!(temp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < size - 1)
	{
		if (j == cursor && (size_t)l->i > l->cursor + 1)
			j++;
		temp[j++] = p[i++];
	}
	temp[j] = '\0';
	free(p);
	return (temp);
}

void	get_char(int const fd, t_line **l)
{
	static char	buf[10];
	static char	*p;
	static int	len = 0;
	int			j;

	ft_bzero(buf, 10);
	if (len == 0)
	{
		j = 0;
		while ((len = read(fd, &buf[j], 1)) && (buf[j] == 27 || buf[j] == 91))
			j++;
		ft_key_pressed(buf, l);
		p = (char *)&buf;
		if (len == 0)
			(*l)->c = '\0';
	}
	(*l)->c = *p;
	if (isprint((*l)->c))
		(*l)->i++;
	p++;
	len--;
}

void	def_line_info(t_line *l)
{
	l->i = 0;
	l->cursor = 0;
	l->c = 'a';
}

int		ft_get_next_line(int const fd, t_line **l)
{
	if (!((*l)->line = (char *)malloc(sizeof(char) * 1)))
		exit(0);
	(*l)->line[0] = '\0';
	while ((*l)->c != '\n' && (*l)->c != '\0')
	{
		get_char(fd, l);
		if ((*l)->c == 127 && (*l)->cursor > 0)
			ft_remove_char(*l);
		else if (ft_isprint((*l)->c))
			ft_add_char(*l);
	}
	ft_line_save(l);
	if ((*l)->line != NULL)
		(*l)->line[(*l)->i] = '\0';
	if ((*l)->line == NULL || ((*l)->c == '\0' && (*l)->line[0] == '\0'))
	{
		free((*l)->line);
		return (0);
	}
	return (1);
}
