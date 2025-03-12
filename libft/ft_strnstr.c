/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:47:49 by aycami            #+#    #+#             */
/*   Updated: 2024/10/23 01:41:19 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;

	if (!to_find[0])
		return ((char *)str);
	while (*str && len > 0)
	{
		i = 0;
		while (to_find[i] == str[i] && to_find[i] && len - i > 0)
			i++;
		if (!to_find[i])
			return ((char *) str);
		len--;
		str++;
	}
	return (NULL);
}
