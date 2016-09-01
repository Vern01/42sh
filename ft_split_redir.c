/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 14:51:31 by rojones           #+#    #+#             */
/*   Updated: 2016/08/05 16:15:22 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static void	ft_count(char **redir, int *in, int *out)
{
	int	i;

	i = -1;
	while (redir[++i])
	{
		if (ft_strchr(redir[i], '>'))
			(*out)++;
		if (ft_strchr(redir[i], '<'))
			(*in)++;
	}
}

static void	ft_populate(char **redir, char **save, int c, int num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (redir[i] && j < num)
	{
		if (ft_strchr(redir[i], c))
		{
			save[j] = ft_strdup(redir[i]);
			j++;
		}
		i++;
	}
	save[j] = NULL;
}

void		ft_split_redir(char **redir, char ***out, char ***in)
{
	char	**reout;
	char	**rein;
	int		iout;
	int		iin;

	iout = 0;
	iin = 0;
	ft_count(redir, &iin, &iout);
	if (!(reout = (char**)malloc(sizeof(char*) * (iout + 1))))
		return ;
	if (!(rein = (char**)malloc(sizeof(char*) * (iin + 1))))
		return ;
	ft_populate(redir, reout, '>', iout);
	ft_populate(redir, rein, '<', iin);
	*out = reout;
	*in = rein;
}
