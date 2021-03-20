/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:41:43 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/17 11:05:40 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			oct;
	static char	*tmp;
	char		buf[BUFFER_SIZE + 1];

	if (BUFFER_SIZE < 1)
		return (-1);
	if (fd <= -1 || !line)
		return (-1);
	oct = 1;
	while (oct != 0 && isline(tmp) == 0)
	{
		oct = read(fd, buf, BUFFER_SIZE);
		if (oct == -1)
			return (-1);
		tmp = ft_strjoin(tmp, buf, oct);
	}
	*line = ft_strcdup(tmp);
	if (oct == 0)
	{
		free(tmp);
		tmp = NULL;
		return (0);
	}
	tmp = ft_gsubstr(tmp);
	return (1);
}
