/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_line_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 08:45:46 by rojones           #+#    #+#             */
/*   Updated: 2016/09/07 13:51:43 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static int	ft_count_pipes(char *line)
{
	char	*ln;
	char	*rem;
	int		i;

	ln = line;
	i = 1;
	while ((rem = ft_str_qut_char(ln, '|')) != NULL)
	{
		ln = rem + 1;
		i++;
	}
	return (i);
}

char		**ft_split_line_op(char *line)
{
	char	**re;
	char	*ln;
	char	*rem;
	int		i;
	int		j;

	i = ft_count_pipes(line);
	if (!(re = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	ln = line;
	j = 0;
	while (j < i)
	{
		rem = ft_str_qut_char(ln, '|');
		if (rem)
			re[j] = ft_strsub(line, (int)(ln - line), (int)(rem - ln));
		else
			re[j] = ft_strsub(line, (int)(ln - line), ft_strlen(line) - (int)
					(ln - line));
		ln = rem + 1;
		j++;
	}
	re[j] = NULL;
	return (re);
}
