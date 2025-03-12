/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:30:24 by aycami            #+#    #+#             */
/*   Updated: 2025/01/07 02:53:30 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(long nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		i += ft_put_nbr(nbr / 10);
	}
	i += ft_putchar((nbr % 10) + '0');
	return (i);
}

int	ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		i += ft_putchar(str[i]);
	}
	return (i);
}
