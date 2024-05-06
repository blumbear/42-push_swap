/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:01:11 by tom               #+#    #+#             */
/*   Updated: 2024/05/06 15:43:08 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list **a, t_list **b)
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
		tmp = *b;
		while (tmp)
		{
			tmp->index = i++;
			tmp = tmp->next;
		}
	}
}

void	set_mediane(t_list **a, t_list **b)
{
	int		mediane;
	t_list	*tmp;
	
	if (!*a)
		return ;
	mediane = ft_stack_size(a) / 2;
	tmp = *a;
	while (tmp)
	{
		tmp->above_mediane = (tmp->index <= mediane);
		tmp = tmp->next;
	}
	if (!*b)
		return ;
	mediane = ft_stack_size(b) / 2;
	tmp = *b;
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

	if (stack == 'a' && *a)
		tmp = *a;
	else if (stack == 'b' && *b)
		tmp = *b;
	while (tmp)
	{
		if (stack == 'a')
		{
			cost_to_top_a = tmp->index - ((ft_stack_size(a) - tmp->index + 1) * !tmp->above_mediane);
			cost_to_top_b = tmp->target->index - ((ft_stack_size(b) - tmp->target->index) * !tmp->target->above_mediane);
		}
		else if (stack == 'b')
		{
			cost_to_top_b = tmp->index - ((ft_stack_size(b) - tmp->index) * !tmp->above_mediane);
			cost_to_top_a = tmp->target->index - ((ft_stack_size(a) - tmp->target->index) * !tmp->target->above_mediane);
		}
		tmp->cost = cost_to_top_a + cost_to_top_b;
		// ft_printf("%c | %d cost -> %d\n", stack, tmp->content, tmp->cost);
		tmp = tmp->next;
	}
	// ft_print_stack(a, b);
}

void	set_target(t_list **a, t_list **b, char from)
{
	t_list	*tmp;
	
	if (from == 'a')
		tmp = (*a);
	else
		tmp = *b;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (from == 'a')
			ft_find_target(b, tmp, "a to b");
		else
			ft_find_target(a, tmp, "b to a");
		tmp = tmp->next;
	}
	// ft_print_stack(a, b);
}
