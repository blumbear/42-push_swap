/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:20:18 by ttaquet           #+#    #+#             */
/*   Updated: 2024/04/24 01:44:55 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_max(t_list **stack)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *stack;
	max = tmp;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_list	*ft_find_min(t_list **stack)
{
	t_list	*tmp;
	t_list	*min;

	tmp = *stack;
	min = tmp;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
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

int	ft_stack_size(t_list	**stack)
{
	t_list *tmp;
	int		i;

	if (!stack || !*stack)
		return (0);
	i = 1;
	tmp = *stack;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
