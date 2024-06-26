/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:01:11 by tom               #+#    #+#             */
/*   Updated: 2024/05/27 16:37:29 by ttaquet          ###   ########.fr       */
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

	tmp = NULL;
	if (stack == 'a' && *a != NULL)
		tmp = *a;
	else if (stack == 'b' && *b != NULL)
		tmp = *b;
	while (tmp)
	{
		if (stack == 'a')
			tmp->cost = node_to_top(tmp, ft_stack_size(a))
				+ node_to_top(tmp->target, ft_stack_size(b));
		else if (stack == 'b')
			tmp->cost = node_to_top(tmp, ft_stack_size(b))
				+ node_to_top(tmp->target, ft_stack_size(a));
		tmp = tmp->next;
	}
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
}
