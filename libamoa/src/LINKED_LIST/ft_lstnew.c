/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:33:13 by ttaquet           #+#    #+#             */
/*   Updated: 2024/05/07 15:15:43 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libamoa.h"

t_list	*ft_lstnew(int content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list) * 1);
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
