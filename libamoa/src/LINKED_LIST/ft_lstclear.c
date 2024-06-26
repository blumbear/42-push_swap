/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:40:41 by ttaquet           #+#    #+#             */
/*   Updated: 2024/05/07 18:24:43 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libamoa.h"

void	ft_lstclear(t_list **list, void (*del_fun)(int))
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		ft_lstdelone(*list, del_fun);
		*list = tmp;
	}
	list = NULL;
}
