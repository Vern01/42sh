/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_ctrl_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:02:16 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/07 15:07:29 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		next_word(char *line, int i)
{
	int		j;

	j = i;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] != '\0' && line[i] != ' ' && line[i] != '\t')
		j = i;
	while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t')
		i++;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] != '\0')
		j = i;
	return (j);
}

int		prev_word(char *line, int i)
{
	int		j;

	j = i;
	while (i > 0 && line[i] != ' ' && line[i] != '\t')
		i--;
	if (line[i] != '\0' && line[i + 1] != '\0' && line[i + 1] != ' ')
		j = i + 1;
	while (i > 0 && (line[i] == ' ' || line[i] == '\t'))
		i--;
	while (i > 0 && line[i] != ' ' && line[i] != '\t')
		i--;
	if (line[i] != ' ' && line[i] != '\t')
		j = i;
	if (line[i + 1] != ' ' && line[i + 1] != '\t')
		j = i + 1;
	return (j);
}
