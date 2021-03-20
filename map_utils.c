/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:56:38 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/20 10:10:39 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		only_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' || line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s2;

	if (!(s2 = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

int	ft_atoi(const char *nptr)
{
	int nbr;
	int i;
	int signe;

	nbr = 0;
	i = 0;
	signe = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	return (nbr * signe);
}

int	complete_R(char *line, t_map *info_map)
{
	int	i;

	i = 1;
	info_map->x = 0;
	info_map->y = 0;

	while (line[i] == ' ')
		i++;
	if (line[i] < '0' && line[i] > '9')
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
	{
		info_map->x = info_map->x * 10 + (line[i] - 48);
		i++;
	}
	while (line[i] == ' ')
		i++;
	if (line[i] < '0' || line[i] > '9')
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
	{
		info_map->y = info_map->y * 10 + (line[i] - 48);
		i++;
	}
	info_map->nbr_info++;
	return (0);
}

int	complete_NO(char *line, t_map *info_map)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	info_map->path_NO = ft_substr(line, i, ft_strlen(line) - i);
	if (info_map->path_NO == NULL)
		return (-1);
	info_map->nbr_info++;
	return (0);
}

int	complete_SO(char *line, t_map *info_map)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	info_map->path_SO = ft_substr(line, i, ft_strlen(line) - i);
	if (info_map->path_SO == NULL)
		return (-1);
	info_map->nbr_info++;
	return (0);
}

int	complete_WE(char *line, t_map *info_map)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	info_map->path_WE = ft_substr(line, i, ft_strlen(line) - i);
	if (info_map->path_WE == NULL)
		return (-1);
	info_map->nbr_info++;
	return (0);
}

int	complete_EA(char *line, t_map *info_map)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	info_map->path_EA = ft_substr(line, i, ft_strlen(line) - i);
	if (info_map->path_EA == NULL)
		return (-1);
	info_map->nbr_info++;
	return (0);
}

int	complete_S(char *line, t_map *info_map)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	info_map->path_S = ft_substr(line, i, ft_strlen(line) - i);
	if (info_map->path_S == NULL)
		return (-1);
	info_map->nbr_info++;
	return (0);
}

int	complete_F(char *line, t_map *info_map)
{
	char	**tab;
	
	tab = ft_split(&line[1], " ,");
	info_map->color_F = (0 << 24 | ft_atoi(tab[0]) << 16 | ft_atoi(tab[1]) << 8 | ft_atoi(tab[2]));
	ft_freeall(tab, 2);
	// free ;ieux plus tard
	info_map->nbr_info++;
	return (0);
}

int	complete_C(char *line, t_map *info_map)
{
	char	**tab;

	tab = ft_split(&line[1], " ,");
	info_map->color_C = (0 << 24 | ft_atoi(tab[0]) << 16 | ft_atoi(tab[1]) << 8 | ft_atoi(tab[2]));
	ft_freeall(tab, 2);
	info_map->nbr_info++;
	return (0);
}

void	ft_freeall(char **map, int nbr_line)
{
	while (nbr_line >= 0)
	{
		free(map[nbr_line]);
		nbr_line--;
	}
	free(map);
}

char	**ft_tab(char **map, char *line, int nbr_line)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char*) * nbr_line + 2);
	i = 0;
	while(i < nbr_line)
	{
		tab[i] = ft_strdup(map[i]);
		printf("map[%d} = |%s|\n", i, map[i]);
		i++;
	}
	tab[nbr_line] = ft_strdup(line);
	printf("tab[%d} = |%s|\n", nbr_line, tab[nbr_line]);
	tab[nbr_line + 1] = 0;
	ft_freeall(map, nbr_line - 1);
	return (tab);
}