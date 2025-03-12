/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:33:26 by aycami            #+#    #+#             */
/*   Updated: 2025/01/07 02:53:53 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned int unbr)
{
	int	i;

	i = 0;
	if (unbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	i += ft_put_nbr(unbr);
	return (i);
}
