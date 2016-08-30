/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupenviron.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 08:48:47 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 08:54:17 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

char	**ft_dupenviron(char **environ, int size)
{
	int		i;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (environ[++i] && i < size)
		tmp[i] = ft_strdup(environ[i]);
	while (++i < size)
		tmp[i][0] = '\0';
	tmp[size] = NULL;
	return (tmp);
}
