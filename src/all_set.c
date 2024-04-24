/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:01:11 by tom               #+#    #+#             */
/*   Updated: 2024/04/24 12:03:46 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index(t_list **a, t_list **b)
{
	int		i;
	t_list	*tmp;

	if (*a)
	{
		i = 0;
		tmp = *a;
		while (tmp)
		{
			tmp->index = i++;
			tmp = tmp->next;
		}
	}
	if (*b)
	{
		i = 0;
		tmp = (*b);
		tmp->index = i++;
		while (tmp)
		{
			tmp->index = i++;
			tmp = tmp->next;
		}
	}
}

void	ft_set_mediane(t_list **stack)
{
	int		mediane;
	t_list	*tmp;
	
	if (!*stack)
		return ;
	mediane = ft_stack_size(stack) / 2;
	tmp = (*stack);
	while (tmp)
	{
		tmp->above_mediane = (tmp->index <= mediane);
		tmp = tmp->next;
	}
}
