/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:58:47 by aycami            #+#    #+#             */
/*   Updated: 2024/10/07 14:58:59 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		write(fd, str++, 1);
	}
	write(fd, "\n", 1);
}
