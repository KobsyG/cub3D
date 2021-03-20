/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:10:58 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/20 10:05:35 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ID_map(int fd, t_map *info_map)
{
	int		oct;
	char	*line;

	info_map->nbr_info = 0;
	while (info_map->nbr_info != 8)
	{
		oct = get_next_line(fd, &line);
		if (line[0] == 'R')
			complete_R(line, info_map);
		else if (line[0] == 'N' && line[1] == 'O')
			complete_NO(line, info_map);
		else if (line[0] == 'S' && line[1] == 'O')
			complete_SO(line, info_map);
		else if (line[0] == 'W' && line[1] == 'E')
			complete_WE(line, info_map);
		else if (line[0] == 'E' && line[1] == 'A')
			complete_EA(line, info_map);
		else if (line[0] == 'S' && line[1] == ' ')
			complete_S(line, info_map);
		else if (line[0] == 'F' && line[1] == ' ')
			complete_F(line, info_map);
		else if (line[0] == 'C' && line [1] == ' ')
			complete_C(line, info_map);
		free(line);
	}
	return (0);
}

int		descr_map(int fd, t_map *info_map)
{
	int		oct;
	int		nbr_line;
	char	*line;

	oct = get_next_line(fd, &line);
	while (only_space(line) == 0)
	{
		free(line);
		oct = get_next_line(fd, &line);
	}
	nbr_line = 0;
	info_map->map = malloc(sizeof(char*) * 2);
	info_map->map[0] = ft_strdup(line);
	info_map->map[1] = 0;
	while (oct != 0 || only_space(line) != 0)
	{
		free(line);
		nbr_line++;
		oct = get_next_line(fd, &line);
		printf("\nnbr_line = %d\n", nbr_line);
		//printf("nbr_line = %d -------- line = |%s|\n", nbr_line, line);
		info_map->map = ft_tab(info_map->map, line, nbr_line);
	}
	free(line);
	return (0);
}
