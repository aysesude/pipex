/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:00:36 by aycami            #+#    #+#             */
/*   Updated: 2024/10/07 15:00:38 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;
	t_list	*next;

	a = *lst;
	while (a != NULL)
	{
		next = a->next;
		del(a->content);
		free(a);
		a = next;
	}
	*lst = NULL;
}
