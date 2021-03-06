/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:21:05 by rojones           #+#    #+#             */
/*   Updated: 2016/08/31 10:59:23 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		str_size;
	char	*re;
	int		i;

	i = 0;
	str_size = ft_strlen(str);
	if (!(re = (char *)malloc((sizeof(char) * (str_size + 1)))))
		return (NULL);
	while (i <= str_size)
	{
		re[i] = str[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}
