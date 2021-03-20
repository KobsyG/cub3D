/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:01:19 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/18 09:09:28 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int		ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s && s[i])
// 		i++;
// 	return (i);
// }

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*s2;
	int	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(s2 = malloc(1)))
			return (NULL);
		s2[0] = 0;
		return (s2);
	}
	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && s[start] != 0)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = 0;
	return (s2);
}