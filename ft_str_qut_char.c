/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_qut_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:22:14 by rojones           #+#    #+#             */
/*   Updated: 2016/09/09 15:06:22 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	*ft_str_qut_char(char *str, char c)
{
	int i;
	int	s_qut;
	int	d_qut;

	i = 0;
	s_qut = 0;
	d_qut = 0;
	while (str && str[i] != '\0')
	{
		if (i == 0 && str[i] == '\'')
			s_qut = 1;
		if (i == 0 && str[i] == '"')
			d_qut = 1;
		if (str[i] == '"' && i > 0 && str[i - 1] != '\\' && s_qut == 0)
			d_qut = (d_qut == 0) ? 1 : 0;
		if (str[i] == '\'' && i > 0 && str[i - 1] != '\\' && d_qut == 0)
			s_qut = (s_qut == 0) ? 1 : 0;
		if (str[i] == c && s_qut == 0 && d_qut == 0)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
