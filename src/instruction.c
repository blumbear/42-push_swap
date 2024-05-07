/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 07:38:57 by tom               #+#    #+#             */
/*   Updated: 2024/05/07 18:32:58 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *stacks, t_list **a, t_list **b, bool print)
{
	if (ft_strncmp(stacks, "ab", 2) == 0)
	{
		ft_swap_nodes(a);
		ft_swap_nodes(b);
		if (print)
			ft_printf("ss\n");
	}
	else
	{
		if (*stacks == 'a')
			ft_swap_nodes(a);
		else if (*stacks == 'b')
			ft_swap_nodes(b);
		if (print)
			ft_printf("s%c\n", *stacks);
	}
}

void	push(char stack, t_list **a, t_list **b, bool print)
{
	if (stack == 'a')
		ft_push_node(b, a);
	else if (stack == 'b')
		ft_push_node(a, b);
	if (print)
		ft_printf("p%c\n", stack);
}

void	rotate(char *stacks, t_list **a, t_list **b, bool print)
{
	if (ft_strncmp(stacks, "ab", 2) == 0)
	{
		ft_rotate_stack(a);
		ft_rotate_stack(b);
		if (print)
			ft_printf("rr\n");
	}
	else
	{
		if (*stacks == 'a')
			ft_rotate_stack(a);
		else if (*stacks == 'b')
			ft_rotate_stack(b);
		if (print)
			ft_printf("r%c\n", *stacks);
	}
}

void	reverse_rotate(char *stacks, t_list **a, t_list **b, bool print)
{
	if (ft_strncmp(stacks, "ab", 2) == 0)
	{
		ft_rev_rotate_stack(a);
		ft_rev_rotate_stack(b);
		if (print)
			ft_printf("rrr\n");
	}
	else
	{
		if (*stacks == 'a')
			ft_rev_rotate_stack(a);
		else if (*stacks == 'b')
			ft_rev_rotate_stack(b);
		if (print)
			ft_printf("rr%c\n", *stacks);
	}
}
