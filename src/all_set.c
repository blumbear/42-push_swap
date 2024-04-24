/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:01:11 by tom               #+#    #+#             */
/*   Updated: 2024/04/24 14:05:56 by tom              ###   ########.fr       */
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

void	set_cost(t_list **a, t_list **b, char stack)
{
	t_list	*tmp;
	int		cost_to_top_b;
	int		cost_to_top_a;

	tmp = (*a);
	if (stack == 'b')
		tmp = (*b);
	while (tmp)
	{
		cost_to_top_b = tmp->index;
		cost_to_top_a = tmp->target->index;
		if (!tmp->above_mediane)
			cost_to_top_b = ft_stack_size(b) - tmp->index;
		if (!tmp->target->above_mediane)
			cost_to_top_a = ft_stack_size(a) - tmp->target->index;
		tmp->cost = cost_to_top_b + cost_to_top_a;
		tmp = tmp->next;
	}
}

void	set_target(t_list **a, t_list **b, char from)
{
	t_list	*tmp;
	
	tmp = *b;
	if (from == 'a')
		tmp = (*a);
	while (tmp)
	{
		if (from == 'a')
			ft_find_target(b, tmp, "a to b");
		else
			ft_find_target(a, tmp, "a to b");
		tmp = tmp->next;
	}
}
