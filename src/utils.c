/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:20:18 by ttaquet           #+#    #+#             */
/*   Updated: 2024/04/23 08:29:58 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_list **stack)
{
	t_list	*tmp;
	int		max;

	tmp = *stack;
	max = tmp->content;
	while (tmp->next)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

bool ft_is_sorted(t_list **stack)
{
	t_list *tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
