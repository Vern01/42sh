/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_script.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 10:37:36 by rojones           #+#    #+#             */
/*   Updated: 2016/09/09 16:56:15 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_run_script(char *path, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line && line[0])
			line = ft_check_qut(line);
		if (line && line[0])
			ft_split_input(line, data);
		ft_strdel(&line);
	}
	close(fd);
}
