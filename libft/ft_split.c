/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:56:29 by aycami            #+#    #+#             */
/*   Updated: 2024/10/07 14:56:37 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_wordcount(const char *s, char c)
{
	unsigned int	word;

	word = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s)
				s++;
			word++;
		}
	}
	return (word);
}

static unsigned int	ft_index(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	j;
	unsigned int	a;

	str = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	a = -1;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			str[++a] = (char *)malloc((ft_index(s, c) + 1) * sizeof(char));
			if (!str[a])
				return (ft_free(str));
			j = 0;
			while (*s && *s != c)
				str[a][j++] = *s++;
			str[a][j] = '\0';
		}
	}
	str[++a] = NULL;
	return (str);
}
