/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:31:34 by ttaquet           #+#    #+#             */
/*   Updated: 2024/05/07 18:25:00 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libamoa.h"

void	ft_lstiter(t_list *list, void (*f)(int))
{
	while (list)
	{
		f(list->content);
		list = list->next;
	}
	list = NULL;
}
