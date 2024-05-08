/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:05:44 by tom               #+#    #+#             */
/*   Updated: 2024/05/09 00:53:41 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_else(t_list **a, t_list **b)
{
	ft_fill_stack_b(a, b, ft_stack_size(a));
	ft_sort_three_node(a);
	while (*b)
	{
		ft_place_on_top_second(a, b, NULL);
		push('a', a, b, 1);
	}
	set_index(a, b);
	set_mediane(a, b);
	if (ft_find_min(a)->above_mediane)
		while (*a != ft_find_min(a))
			rotate("a", a, b, 1);
	else
		while (*a != ft_find_min(a))
			reverse_rotate("a", a, b, 1);
}

void	ft_turk_sort(t_list **a, t_list **b)
{
	int	a_size;

	a_size = ft_stack_size(a);
	if (a_size <= 3)
		ft_sort_three_node(a);
	else if (a_size <= 5)
		ft_sort_five_node(a, b);
	else
		ft_sort_else(a, b);
}

void	ft_sort_five_node(t_list **a, t_list **b)
{
	ft_fill_stack_b_five(a, b);
	ft_sort_three_node(a);
	while (*b)
	{
		set_index(a, b);
		set_mediane(a, b);
		ft_find_target(a, *b, "b to a");
		while (*a != (*b)->target)
		{
			if ((*b)->target->above_mediane)
				rotate("a", a, b, 1);
			else
				reverse_rotate("a", a, b, 1);
		}
		push('a', a, b, 1);
	}
	set_index(a, b);
	set_mediane(a, b);
	if (ft_find_min(a)->above_mediane)
		while (!ft_is_sorted(a))
			rotate("a", a, b, 1);
	else
		while (!ft_is_sorted(a))
			reverse_rotate("a", a, b, 1);
}

void	ft_sort_three_node(t_list **head_a)
{
	int		max;

	max = ft_find_max(head_a)->content;
	if (ft_is_sorted(head_a))
		return ;
	if (ft_lstlast(*head_a)->content != max)
	{
		if ((*head_a)->content == max)
			rotate("a", head_a, NULL, 1);
		else
			reverse_rotate("a", head_a, NULL, 1);
	}
	if (!ft_is_sorted(head_a))
		swap("a", head_a, NULL, 1);
}
