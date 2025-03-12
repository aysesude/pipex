/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:48:12 by aycami            #+#    #+#             */
/*   Updated: 2025/01/18 23:29:04 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_str(va_list args, char format_type)
{
	int	i;

	i = 0;
	if (format_type == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (format_type == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format_type == 'p')
		i += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format_type == 'i' || format_type == 'd')
		i += ft_print_nbr(va_arg(args, int));
	else if (format_type == 'u')
		i += ft_print_unbr(va_arg(args, unsigned int));
	else if (format_type == 'x' || format_type == 'X')
		i += ft_print_hex(va_arg(args, unsigned int), format_type);
	else if (format_type == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			j += ft_format_str(args, format[i + 1]);
			i++;
		}
		else
			j += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (j);
}
