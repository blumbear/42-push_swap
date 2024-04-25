/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:07:45 by tom               #+#    #+#             */
/*   Updated: 2024/04/25 17:27:26 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_stack_b_five(t_list **a, t_list **b, int a_size)
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

void	ft_fill_stack_b(t_list **a, t_list **b, int a_size)
{
	t_list	*tmp;
	int		max;
	int		min;
	//int		min_cost;

	max = ft_find_max(a)->content;
	min = ft_find_min(a)->content;
	while (a_size-- > 3)
	{
		set_target(a, b, 'a');
		set_cost(a, b, 'a');
		tmp = find_min_cost(a);
		if (*b)
		{
			if (tmp->content == min || tmp->content == max)
			{
				if ((*a)->next->content != min && (*a)->next->content != max)
					rotate("a", a, b);
				else
					reverse_rotate("a", a, b);
			}
		}
		push('b', a, b);
	}
}

void	ft_fill_stack_a(char **list, t_list **a, bool splitted)
{
	long int	tmp;
	int			i;

	i = -1;
	while (list[++i])
	{
		tmp = ft_atoi(list[i]);
		if (tmp > MAX_INT || tmp < MIN_INT || ft_strlen(list[i]) > 11)
		{
			if (splitted)
				ft_free_double_array(list);
			ft_error(a, NULL, "The value mist be between MIN_INT and MAX_INT");
		}
		if (ft_strlen(list[i]) != ft_intlen(tmp))
		{
			if (splitted)
				ft_free_double_array(list);
			ft_error(a, NULL, "The value cant contain any char");
		}
		ft_lstadd_back(a, ft_lstnew((int)tmp));
	}
}
