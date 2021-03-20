/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:41:41 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/17 11:05:30 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *s);
int		isline(char *s);
char	*ft_strjoin(char *tmp, char *buf, int oct);
char	*ft_strcdup(char *tmp);
char	*ft_gsubstr(char *tmp);

#endif
