/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:14:09 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/18 09:14:19 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		char_in_sep(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (-1);
}

int		nbr_word(char *str, char *charset)
{
	int i;
	int mot;

	i = 0;
	mot = 1;
	while (char_in_sep(str[i], charset) == 0)
		i++;
	while (str[i] != '\0')
	{
		if (char_in_sep(str[i], charset) == 0 &&
			char_in_sep(str[i + 1], charset) != 0 && str[i + 1] != '\0')
			mot++;
		i++;
	}	
	return (mot);
}

char	*ft_strcpy2(char *dest, char *src, int i, int len)
{
	int j;

	j = 0;
	while (i - len < i)
	{
		dest[j] = src[i - len];
		len--;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		len;
	int		mot;
	char	**tab;

	i = 0;
	mot = 0;
	tab = malloc(sizeof(char) * nbr_word(str, charset) + 1);
	while (mot < nbr_word(str, charset))
	{
		len = 0;
		while (char_in_sep(str[i], charset) == 0)
			i++;
		while (char_in_sep(str[i], charset) != 0)
		{
			i++;
			len++;
		}
		tab[mot] = malloc(sizeof(char) * len + 1);
		tab[mot] = ft_strcpy2(tab[mot], str, i, len);
		mot++;
		i++;
	}
	tab[mot] = malloc(sizeof(char));
	tab[mot] = 0;
	return (tab);
}