/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:31:25 by rojones           #+#    #+#             */
/*   Updated: 2016/08/02 07:29:39 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char test;

	test = c;
	while (*(str) != '\0')
	{
		if (*str == test)
			return ((char *)str);
		str++;
	}
	if (*str == test)
		return ((char *)str);
	return (NULL);
}
