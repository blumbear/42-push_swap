/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_fonction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:20:53 by tom               #+#    #+#             */
/*   Updated: 2024/04/24 12:21:18 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target(t_list **stack, t_list *node, char *direction)
{
	t_list	*tmp;
	int		n;

	tmp = (*stack);
	n = ft_find_max(stack)->content;
	if (ft_strncmp(direction, "b to a", 6) == 0)
	{
		if (n > node->content)
		{
			while (tmp->next && tmp->content < node->content)
				tmp = tmp->next;
			node->target = tmp;
		}
		else if (n < node->content)
		{
			n = ft_find_min(stack)->content;
			while (tmp->next && tmp->content != n)
				tmp = tmp->next;
			node->target = tmp;
		}
	}
	else
		return ;
}

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
