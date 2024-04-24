/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:05:44 by tom               #+#    #+#             */
/*   Updated: 2024/04/24 13:02:04 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_turk_sort(t_list **a, t_list **b)
{
	int a_size;

	a_size = ft_stack_size(a);
	if (ft_is_sorted(a))
		return ;
	if (a_size <= 3)
		ft_sort_three_node(a);
	else if (a_size <= 5)
		ft_sort_five_node(a, b, a_size);
}

void	ft_fill_stack_b(t_list **a, t_list **b, int a_size)
{
	int max;
	int min;

	max = ft_find_max(a)->content;
	min = ft_find_min(a)->content;
	while (a_size-- > 3)
	{
		if ((*a)->content == min || (*a)->content == max)
		{
			if ((*a)->next->content != min && (*a)->next->content != max)
				rotate("a", a, b);
			else
				reverse_rotate("a", a, b);
		}
		push('b', a, b);
	}
}

void	ft_sort_five_node(t_list **a, t_list **b, int a_size)
{
	t_list	*tmp;

	ft_set_index(a, b);
	ft_set_mediane(a);
	ft_fill_stack_b(a, b, a_size);
	ft_sort_three_node(a);
	while (*b)
	{
		ft_find_target(a, (*b), "b to a");
		while ((*a) != (*b)->target)
			rotate("a", a, b);
		push('a', a, b);
		ft_set_index(a, b);
		ft_set_mediane(a);
	}
	tmp = ft_find_min(a);
	if (tmp->above_mediane)
		while (!ft_is_sorted(a))
			rotate("a", a, b);
	else
		while (!ft_is_sorted(a))
			reverse_rotate("a", a, b);
	ft_print_stack(a, b);
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
			rotate("a", head_a, NULL);
		else
			reverse_rotate("a", head_a, NULL);
	}
	if (!ft_is_sorted(head_a))
		swap("a", head_a, NULL);
}

