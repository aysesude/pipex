/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:29:59 by aycami            #+#    #+#             */
/*   Updated: 2025/01/07 04:08:46 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int hex, const char format)
{
	int	i;

	i = 0;
	if (hex >= 16)
	{
		i += ft_print_hex(hex / 16, format);
		i += ft_print_hex(hex % 16, format);
	}
	else if (hex > 9 && format == 'x')
	{
		i += ft_putchar(hex - 10 + 'a');
	}
	else if (hex > 9 && format == 'X')
	{
		i += ft_putchar(hex - 10 + 'A');
	}
	else if (hex <= 9)
	{
		i += ft_putchar(hex + 48);
	}
	return (i);
}
