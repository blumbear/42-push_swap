/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:20:18 by ttaquet           #+#    #+#             */
/*   Updated: 2024/04/30 14:29:14 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_is_not_double(t_list **stack)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack;
	while(tmp_a)
	{
		tmp_b = tmp_a->next;
		while(tmp_b)
		{
			if (tmp_a->content == tmp_b->content)
				return (0);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
	return (1);
}

int	ft_all_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}
