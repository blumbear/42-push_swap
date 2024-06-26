/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:20:18 by ttaquet           #+#    #+#             */
/*   Updated: 2024/05/27 02:25:38 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_list **stack)
{
	t_list	*tmp;

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
	t_list	*tmp;
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

bool	ft_is_not_double(t_list **stack)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack;
	while (tmp_a)
	{
		tmp_b = tmp_a->next;
		while (tmp_b)
		{
			if (tmp_a->content == tmp_b->content)
				return (false);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
	return (true);
}

bool	ft_all_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' && i != 0)
			return (0);
		if (str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (str[i] == ' ' && i != 0);
	}
	return (1);
}

int	node_to_top(t_list *node, int stack_size)
{
	if (node->above_mediane)
		return (node->index);
	return (stack_size - node->index);
}
