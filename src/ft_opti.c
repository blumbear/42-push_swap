/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:33:25 by tom               #+#    #+#             */
/*   Updated: 2024/05/27 01:35:42 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_opti(t_list **a, t_list **b, t_list *min_cost)
{
	int	tmp;

	tmp = ft_abs(min_cost->index - min_cost->target->index);
	if (node_to_top(min_cost, ft_stack_size(a) 
		== node_to_top(min_cost->target, ft_stack_size(b)))
		|| node_to_top(min_cost, ft_stack_size(a) 
		< node_to_top(min_cost->target, ft_stack_size(b))))
	{
		if (tmp < node_to_top(min_cost, ft_stack_size(a)))
		{
			while (min_cost != *a && min_cost->target != *b)
				rotate("ab", a, b, 1);
			while (min_cost != *a)
				rotate("a", a, b, 1);
			while (min_cost->target != *b)
				rotate("b", a, b, 1);
		}
	}
	else if (node_to_top(min_cost, ft_stack_size(a) 
				> node_to_top(min_cost->target, ft_stack_size(b))))
		ft_opti_bis(a, b, min_cost, tmp);
}


void	ft_rev_rotate_test(t_list **a, t_list **b, t_list *min_cost)
{
		if (*a != min_cost && *b != min_cost->target
			&& min_cost->target->above_mediane && min_cost->above_mediane)
			while (min_cost != *a && min_cost->target != *b)
				rotate("ab", a, b, 1);
		if (*a != min_cost && *b != min_cost->target
			&& !min_cost->target->above_mediane && !min_cost->above_mediane)
			while (min_cost != *a && min_cost->target != *b)
				reverse_rotate("ab", a, b, 1);
}

void	ft_opti_bis(t_list **a, t_list **b, t_list *min_cost, int tmp)
{
	if (tmp < node_to_top(min_cost->target, ft_stack_size(b)))
			{
				while (min_cost != *a && min_cost->target != *b)
					reverse_rotate("ab", a, b, 1);
				while (min_cost != *a)
					reverse_rotate("a", a, b, 1);
				while (min_cost->target != *b)
					reverse_rotate("b", a, b, 1);
			}
}
