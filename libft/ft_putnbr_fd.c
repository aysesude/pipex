/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:59:11 by aycami            #+#    #+#             */
/*   Updated: 2024/10/07 14:59:13 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	char	mychr;

	if (nb == -2147483648)
	{
		ft_putnbr_fd(nb / 10, fd);
		write(fd, "8", 1);
	}
	else if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		mychr = (nb % 10) + '0';
		write(fd, &mychr, 1);
	}
	else
	{
		mychr = (nb % 10) + '0';
		write(fd, &mychr, 1);
	}
}
