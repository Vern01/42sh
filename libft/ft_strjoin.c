/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 13:55:35 by rojones           #+#    #+#             */
/*   Updated: 2016/07/30 11:46:12 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*re;
	int		i;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(re = (char *)malloc((sizeof(char) * size))))
		return (NULL);
	i = 0;
	while (*s1 && i < size)
		re[i++] = *s1++;
	while (*s2 && i < size)
		re[i++] = *s2++;
	re[i] = '\0';
	return (re);
}
