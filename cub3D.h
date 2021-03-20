/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:11:49 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/20 10:03:20 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "gnl/get_next_line.h"

typedef struct	s_map
{
	int			nbr_info;
	int			x;
	int			y;
	char		*path_NO;
	char		*path_SO;
	char		*path_WE;
	char		*path_EA;
	char		*path_S;
	int			color_F;
	int			color_C;
	char		**map;
}				t_map;

typedef struct	s_rgb_F
{
	int			r;
	int			g;
	int			b;
}				t_rgb_F;

typedef struct	s_rgb_C
{
	int			r;
	int			g;
	int			b;
}				t_rgb_C;

char	**ft_split(char *str, char *charset);
char	**ft_tab(char **map, char *line, int nbr_line);

char	*ft_substr(char const *s, unsigned int start, int len);
int		complete_C(char *line, t_map *info_map);
int		complete_EA(char *line, t_map *info_map);
int		complete_F(char *line, t_map *info_map);
int		complete_NO(char *line, t_map *info_map);
int		complete_R(char *line, t_map *info_map);
int		complete_S(char *line, t_map *info_map);
int		complete_SO(char *line, t_map *info_map);
int		complete_WE(char *line, t_map *info_map);

int		ID_map(int fd, t_map *info_map);
int		descr_map(int fd, t_map *info_map);
int		only_space(char *line);

char	*ft_strdup(const char *s);

void	ft_freeall(char **map, int nbr_line);

#endif
