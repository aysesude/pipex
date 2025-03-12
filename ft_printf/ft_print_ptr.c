/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:32:12 by aycami            #+#    #+#             */
/*   Updated: 2025/01/07 02:53:56 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr >= 16)
	{
		i += ft_put_ptr(ptr / 16);
		i += ft_put_ptr(ptr % 16);
	}
	else if (ptr > 9)
	{
		i += ft_putchar(ptr - 10 + 'a');
	}
	else if (ptr <= 9)
	{
		i += ft_putchar(ptr + 48);
	}
	return (i);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	i += ft_putstr("0x");
	i += ft_put_ptr(ptr);
	return (i);
}
