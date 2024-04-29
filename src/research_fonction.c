/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_fonction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:20:53 by tom               #+#    #+#             */
/*   Updated: 2024/04/29 16:23:00 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target_bis(t_list **stack, t_list *node)
{
	t_list	*tmp;
	int		n;

	if (!*stack)
		return ;
	node->target = NULL;
	tmp = *stack;
	n = node->content - tmp->content;
	while (tmp)
	{
		if (node->content > tmp->content &&
				(node->content - tmp->content <= n || n < 0))
		{
			n = node->content - tmp->content;
			node->target = tmp;
		}
		tmp = tmp->next;
	}
	if (!node->target)
		node->target = ft_find_max(stack);
	ft_printf("%d -> %d\n", node->content , node->target->content);
}

void	ft_find_target(t_list **stack, t_list *node, char *direction)
{
	t_list	*tmp;
	int		n;

	if (ft_strncmp(direction, "b to a", 6) == 0)
	{
		if (!*stack)
			return ;
		node->target = NULL;
		tmp = *stack;
		n = tmp->content - node->content;
		while (tmp)
		{
			if (tmp->content > node->content &&
					(tmp->content - node->content <= n || n < 0))
			{
				n = tmp->content - node->content;
				node->target = tmp;
			}
			tmp = tmp->next;
		}
		if (!node->target)
			node->target = ft_find_min(stack);
		ft_printf("%d -> %d\n", node->content , node->target->content);
	}
	else
		ft_find_target_bis(stack, node);
}

t_list	*ft_find_max(t_list **stack)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *stack;
	max = *stack;
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
	min = *stack;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*find_min_cost(t_list **stack)
{
	t_list	*tmp;
	t_list	*min_cost;
	t_list	*min;
	t_list	*max;
	
	min = ft_find_min(stack);
	max = ft_find_max(stack);
	tmp = *stack;
	min_cost = *stack;
	while (tmp)
	{
		if (min_cost == max || min_cost == min)
			min_cost = tmp;
		else if (tmp != min && tmp != max && tmp->cost < min_cost->cost)
			min_cost = tmp;
		tmp = tmp->next;
	}
	return (min_cost);
}
