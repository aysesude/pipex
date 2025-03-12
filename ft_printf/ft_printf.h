/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:21:01 by aycami            #+#    #+#             */
/*   Updated: 2025/01/19 00:12:34 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char a);
int	ft_putstr(char *str);
int	ft_put_nbr(long nbr);
int	ft_print_hex(unsigned int hex, const char format);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_nbr(int nbr);
int	ft_print_unbr(unsigned int unbr);
int	ft_printf(const char *format, ...);

#endif
